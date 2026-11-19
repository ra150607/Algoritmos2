#include <stdio.h>
#include <stdlib.h>

typedef struct Sensor {
    int codigo;
    float temperatura;
    struct Sensor *proximo;
} Sensor;

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

Sensor *buscarSensor(Sensor *inicio, int codigo) {
    Sensor *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

Sensor *inserirInicio(Sensor *inicio, int codigo, float temperatura) {
    if (buscarSensor(inicio, codigo) != NULL) {
        printf("Erro: ja existe um sensor cadastrado com o codigo %d.\n", codigo);
        return inicio;
    }

    Sensor *novo = malloc(sizeof(Sensor));
    if (novo == NULL) {
        printf("Erro: falha na alocacao de memoria.\n");
        return inicio;
    }

    novo->codigo = codigo;
    novo->temperatura = temperatura;
    novo->proximo = inicio;

    printf("Sensor %d inserido no inicio com sucesso.\n", codigo);
    return novo;
}

Sensor *inserirFinal(Sensor *inicio, int codigo, float temperatura) {
    if (buscarSensor(inicio, codigo) != NULL) {
        printf("Erro: ja existe um sensor cadastrado com o codigo %d.\n", codigo);
        return inicio;
    }

    Sensor *novo = malloc(sizeof(Sensor));
    if (novo == NULL) {
        printf("Erro: falha na alocacao de memoria.\n");
        return inicio;
    }

    novo->codigo = codigo;
    novo->temperatura = temperatura;
    novo->proximo = NULL;

    if (inicio == NULL) {
        printf("Sensor %d inserido no final com sucesso.\n", codigo);
        return novo;
    }

    Sensor *atual = inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;

    printf("Sensor %d inserido no final com sucesso.\n", codigo);
    return inicio;
}

void listarSensores(Sensor *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia. Nenhum sensor cadastrado.\n");
        return;
    }

    Sensor *atual = inicio;
    printf("\n--- Sensores Cadastrados ---\n");
    while (atual != NULL) {
        printf("Codigo: %d | Temperatura: %.2f C\n", atual->codigo, atual->temperatura);
        atual = atual->proximo;
    }
}

Sensor *removerSensor(Sensor *inicio, int codigo) {
    if (inicio == NULL) {
        printf("Lista vazia. Nenhum sensor para remover.\n");
        return inicio;
    }

    Sensor *atual = inicio;
    Sensor *anterior = NULL;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Sensor com codigo %d nao encontrado.\n", codigo);
        return inicio;
    }

    if (anterior == NULL) {
        inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Sensor %d removido com sucesso.\n", codigo);
    return inicio;
}

void calcularTemperaturaMedia(Sensor *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia. Nao e possivel calcular a temperatura media.\n");
        return;
    }

    double soma = 0.0;
    int quantidade = 0;
    Sensor *atual = inicio;

    while (atual != NULL) {
        soma += atual->temperatura;
        quantidade++;
        atual = atual->proximo;
    }

    printf("Temperatura media (%d sensores): %.2f C\n", quantidade, soma / quantidade);
}

void contarAcimaTemperatura(Sensor *inicio, float limite) {
    if (inicio == NULL) {
        printf("Lista vazia. Nenhum sensor cadastrado.\n");
        return;
    }

    int contador = 0;
    Sensor *atual = inicio;

    while (atual != NULL) {
        if (atual->temperatura > limite) {
            contador++;
        }
        atual = atual->proximo;
    }

    printf("Quantidade de sensores com temperatura acima de %.2f C: %d\n", limite, contador);
}

Sensor *liberarLista(Sensor *inicio) {
    Sensor *atual = inicio;
    while (atual != NULL) {
        Sensor *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    return NULL;
}

int main(void) {
    Sensor *inicio = NULL;
    int opcao = -1;
    int codigo;
    float temperatura;

    do {
        printf("\n===== GERENCIAMENTO DE SENSORES =====\n");
        printf("1 - Inserir sensor no inicio\n");
        printf("2 - Inserir sensor no final\n");
        printf("3 - Listar sensores\n");
        printf("4 - Buscar sensor\n");
        printf("5 - Remover sensor\n");
        printf("6 - Calcular temperatura media\n");
        printf("7 - Contar sensores acima de uma temperatura\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            limparBuffer();
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Digite o codigo do sensor: ");
                if (scanf("%d", &codigo) != 1) {
                    printf("Codigo invalido.\n");
                    limparBuffer();
                    break;
                }
                printf("Digite a temperatura: ");
                if (scanf("%f", &temperatura) != 1) {
                    printf("Temperatura invalida.\n");
                    limparBuffer();
                    break;
                }
                inicio = inserirInicio(inicio, codigo, temperatura);
                break;

            case 2:
                printf("Digite o codigo do sensor: ");
                if (scanf("%d", &codigo) != 1) {
                    printf("Codigo invalido.\n");
                    limparBuffer();
                    break;
                }
                printf("Digite a temperatura: ");
                if (scanf("%f", &temperatura) != 1) {
                    printf("Temperatura invalida.\n");
                    limparBuffer();
                    break;
                }
                inicio = inserirFinal(inicio, codigo, temperatura);
                break;

            case 3:
                listarSensores(inicio);
                break;

            case 4:
                if (inicio == NULL) {
                    printf("Lista vazia. Nenhum sensor cadastrado.\n");
                    break;
                }
                printf("Digite o codigo do sensor para buscar: ");
                if (scanf("%d", &codigo) != 1) {
                    printf("Codigo invalido.\n");
                    limparBuffer();
                    break;
                }
                {
                    Sensor *encontrado = buscarSensor(inicio, codigo);
                    if (encontrado != NULL) {
                        printf("Sensor encontrado -> Codigo: %d | Temperatura: %.2f C\n", encontrado->codigo, encontrado->temperatura);
                    } else {
                        printf("Sensor com codigo %d nao encontrado.\n", codigo);
                    }
                }
                break;

            case 5:
                if (inicio == NULL) {
                    printf("Lista vazia. Nenhum sensor para remover.\n");
                    break;
                }
                printf("Digite o codigo do sensor para remover: ");
                if (scanf("%d", &codigo) != 1) {
                    printf("Codigo invalido.\n");
                    limparBuffer();
                    break;
                }
                inicio = removerSensor(inicio, codigo);
                break;

            case 6:
                calcularTemperaturaMedia(inicio);
                break;

            case 7:
                if (inicio == NULL) {
                    printf("Lista vazia. Nenhum sensor cadastrado.\n");
                    break;
                }
                printf("Digite a temperatura limite: ");
                if (scanf("%f", &temperatura) != 1) {
                    printf("Temperatura invalida.\n");
                    limparBuffer();
                    break;
                }
                contarAcimaTemperatura(inicio, temperatura);
                break;

            case 0:
                inicio = liberarLista(inicio);
                printf("Memoria liberada. Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}