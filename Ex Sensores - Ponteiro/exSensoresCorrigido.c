#include <stdio.h>
#include <stdlib.h>

struct Sensor {
    int codigo;
    float temperatura;
};

float mediaTemperatura(struct Sensor *sensores, int qteSensores) {
    float somaTemperatura = 0.0;

    for (int i = 0; i < qteSensores; i++) {
        somaTemperatura += (*(sensores + i)).temperatura;
    }

    return (somaTemperatura / qteSensores);
}

float maiorTemperatura(struct Sensor *sensores, int qteSensores) {
    float maiorTemp = (*(sensores + 0)).temperatura;

    for (int i = 1; i < qteSensores; i++) {
        if ((*(sensores + i)).temperatura > maiorTemp) {
            maiorTemp = (*(sensores + i)).temperatura;
        }
    }

    return maiorTemp;
}

float menorTemperatura(struct Sensor *sensores, int qteSensores) {
    float menorTemp = (*(sensores + 0)).temperatura;

    for (int i = 1; i < qteSensores; i++) {
        if ((*(sensores + i)).temperatura < menorTemp) {
            menorTemp = (*(sensores + i)).temperatura;
        }
    }

    return menorTemp;
}

void leituraSens(struct Sensor *sensores, int valorIni, int valorFim) {
    for (int i = valorIni; i < valorFim; i++) {
        printf("Digite o código do sensor %d: ", (i + 1));
        scanf("%d", &(*(sensores + i)).codigo);
        printf("Digite a temperatura do sensor %d: ", (i + 1));
        scanf("%f", &(*(sensores + i)).temperatura);
    }
}

void imprimirSens(struct Sensor *sensores, int qteSensores) {
    for (int i = 0; i < qteSensores; i++) {
        printf("Sensor %d - Código: %d, Temperatura: %.3f\n", (i + 1), (*(sensores + i)).codigo, (*(sensores + i)).temperatura);
    }
}

int main() {
    int qteSensores, qteSensoresAdicionais, opcao;

    printf("Digite a quantidade de sensores: ");
    scanf("%d", &qteSensores);

    struct Sensor *sensores = (struct Sensor*)malloc(qteSensores * sizeof(struct Sensor));

    if (sensores == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    leituraSens(sensores, 0, qteSensores);
    
    printf("Os sensores cadastrados são:\n");
    imprimirSens(sensores, qteSensores);
    printf("As informações dos sensores cadastrados são:\n");
    printf("Média das temperaturas: %.3f\n", mediaTemperatura(sensores, qteSensores));
    printf("Maior temperatura: %.3f\n", maiorTemperatura(sensores, qteSensores));
    printf("Menor temperatura: %.3f\n", menorTemperatura(sensores, qteSensores));

    do {
        printf("Deseja adicionar mais sensores? (1 - Sim, 0 - Não): ");
    } while (scanf("%d", &opcao) != 1 || (opcao != 0 && opcao != 1));

    while (opcao == 1) {
        printf("Digite a quantidade de sensores adicionais: ");
        scanf("%d", &qteSensoresAdicionais);

        int tamanhoAntigo = qteSensores;
        qteSensores += qteSensoresAdicionais;

        struct Sensor *temp = (struct Sensor*)realloc(sensores, qteSensores * sizeof(struct Sensor));
        if (temp == NULL) {
            printf("Erro ao realocar memória.\n");
            free(sensores);
            return 1;
        }
        sensores = temp;

        leituraSens(sensores, tamanhoAntigo, qteSensores);

        printf("Os sensores cadastrados são:\n");
        imprimirSens(sensores, qteSensores);
        printf("As informações dos sensores cadastrados são:\n");
        printf("Média das temperaturas: %.3f\n", mediaTemperatura(sensores, qteSensores));
        printf("Maior temperatura: %.3f\n", maiorTemperatura(sensores, qteSensores));
        printf("Menor temperatura: %.3f\n", menorTemperatura(sensores, qteSensores));

        do {
            printf("Deseja adicionar mais sensores? (1 - Sim, 0 - Não): ");
        } while (scanf("%d", &opcao) != 1 || (opcao != 0 && opcao != 1));
    }

    free(sensores);
    sensores = NULL;

    return 0;
}