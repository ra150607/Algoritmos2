#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TAM_NOME 100
#define LIMITE_FAIXA 100.0
#define TARIFA_ATE_100 0.60
#define TARIFA_ACIMA_100 0.75
#define CONSUMO_MAXIMO 1e9

typedef struct {
    char nome[TAM_NOME];
    double consumoKwh;
    double tarifaAplicada;
    double valorConta;
} Cliente;

// Prototipos das funcoes
void limparBuffer(void);
void lerNome(char *destino, int tamanho);
double lerConsumo(void);
double obterTarifa(double consumo);
double calcularConta(double consumo);
void exibirFatura(const Cliente *cliente);
bool desejaContinuar(void);

int main(void) {
    int totalClientes = 0;
    double faturamentoTotal = 0.0;

    printf("============================================\n");
    printf("   SISTEMA DE CALCULO DE CONTA DE ENERGIA   \n");
    printf("============================================\n");

    do {
        Cliente cliente;

        printf("\n--- Cadastro do Cliente #%d ---\n", totalClientes + 1);
        lerNome(cliente.nome, TAM_NOME);
        cliente.consumoKwh = lerConsumo();
        cliente.tarifaAplicada = obterTarifa(cliente.consumoKwh);
        cliente.valorConta = calcularConta(cliente.consumoKwh);

        exibirFatura(&cliente);

        totalClientes++;
        faturamentoTotal += cliente.valorConta;

    } while (desejaContinuar());

    printf("\n============================================\n");
    printf("RESUMO GERAL\n");
    printf("Clientes processados: %d\n", totalClientes);
    printf("Valor total faturado: R$ %.2f\n", faturamentoTotal);
    printf("============================================\n");

    return 0;
}

// Descarta caracteres excedentes no buffer de entrada (stdin)
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // apenas consome o restante da linha
    }
}

// Le e valida o nome do cliente, garantindo que nao fique vazio
void lerNome(char *destino, int tamanho) {
    bool valido = false;

    while (!valido) {
        printf("Nome do cliente: ");
        if (fgets(destino, tamanho, stdin) != NULL) {
            if (strchr(destino, '\n') == NULL) {
                limparBuffer();
            } else {
                destino[strcspn(destino, "\n")] = '\0';
            }

            // Verifica se existe ao menos um caractere diferente de espaco
            for (int i = 0; destino[i] != '\0'; i++) {
                if (!isspace((unsigned char)destino[i])) {
                    valido = true;
                    break;
                }
            }
        }

        if (!valido) {
            printf("Erro: o nome nao pode ficar em branco. Tente novamente.\n");
        }
    }
}

// Le e valida o consumo em kWh (aceita ponto ou virgula e rejeita letras/negativos)
double lerConsumo(void) {
    char entrada[64];
    char *fim;
    double consumo;

    while (true) {
        printf("Consumo mensal (kWh): ");
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            continue;
        }

        if (strchr(entrada, '\n') == NULL) {
            limparBuffer();
        }

        // Converte virgula em ponto para facilitar a digitacao no padrao BR
        for (int i = 0; entrada[i] != '\0'; i++) {
            if (entrada[i] == ',') {
                entrada[i] = '.';
            }
        }

        consumo = strtod(entrada, &fim);

        // Nenhum numero foi convertido
        if (fim == entrada) {
            printf("Erro: digite um valor numerico valido (ex: 120.5 ou 120,5).\n");
            continue;
        }

        // Avanca espacos finais para garantir que nao ha letras apos o numero
        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (*fim != '\0') {
            printf("Erro: entrada contem caracteres invalidos. Digite apenas numeros.\n");
            continue;
        }

        if (consumo < 0.0 || consumo > CONSUMO_MAXIMO) {
            printf("Erro: o consumo deve ser um valor nao negativo e valido.\n");
            continue;
        }

        return consumo;
    }
}

// Retorna a tarifa correspondente a faixa de consumo
double obterTarifa(double consumo) {
    return (consumo <= LIMITE_FAIXA) ? TARIFA_ATE_100 : TARIFA_ACIMA_100;
}

// Calcula o valor final da conta com base na tarifa da faixa
double calcularConta(double consumo) {
    return consumo * obterTarifa(consumo);
}

// Exibe a fatura formatada do cliente
void exibirFatura(const Cliente *cliente) {
    printf("\n--------------------------------------------\n");
    printf("              FATURA DE ENERGIA             \n");
    printf("--------------------------------------------\n");
    printf("Cliente        : %s\n", cliente->nome);
    printf("Consumo total  : %.2f kWh\n", cliente->consumoKwh);
    printf("Tarifa aplicada: R$ %.2f / kWh\n", cliente->tarifaAplicada);
    printf("Valor da conta : R$ %.2f\n", cliente->valorConta);
    printf("--------------------------------------------\n");
}

// Pergunta se o usuario quer continuar e valida a resposta (S/N)
bool desejaContinuar(void) {
    char entrada[16];

    while (true) {
        printf("\nDeseja calcular para outro cliente? (S/N): ");
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return false;
        }

        if (strchr(entrada, '\n') == NULL) {
            limparBuffer();
        }

        int i = 0;
        while (isspace((unsigned char)entrada[i])) {
            i++;
        }

        char opcao = (char)toupper((unsigned char)entrada[i]);

        int j = i + 1;
        while (isspace((unsigned char)entrada[j])) {
            j++;
        }

        if ((opcao == 'S' || opcao == 'N') && entrada[j] == '\0') {
            return opcao == 'S';
        }

        printf("Opcao invalida. Digite apenas S ou N.\n");
    }
}