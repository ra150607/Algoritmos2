#include <stdio.h>
#include <stdlib.h>

struct Sensor {
    int codigo;
    float temperatura;
};

int main() {
    int qteSensores, qteSensoresAdicionais, opcao;
    float mediaTemperatura = 0.0, somaTemperatura = 0.0, maiorTemperatura = 0.0, menorTemperatura = 0.0;

    printf("Digite a quantidade de sensores: ");
    scanf("%d", &qteSensores);

    struct Sensor *sensores = (struct Sensor*)malloc(qteSensores * sizeof(struct Sensor));

    if (sensores == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < qteSensores; i++) {
        printf("Digite o código do sensor %d: ", (i + 1));
        scanf("%d", &sensores[i].codigo);
        printf("Digite a temperatura do sensor %d: ", (i + 1));
        scanf("%f", &sensores[i].temperatura);
    }

    maiorTemperatura = sensores[0].temperatura;
    menorTemperatura = sensores[0].temperatura;

    for (int i = 0; i < qteSensores; i++) {
        printf("Sensor %d - Código: %d, Temperatura: %.3f\n", (i + 1), sensores[i].codigo, sensores[i].temperatura);
        somaTemperatura += sensores[i].temperatura;

        if (sensores[i].temperatura > maiorTemperatura) {
            maiorTemperatura = sensores[i].temperatura;
        }

        if (sensores[i].temperatura < menorTemperatura) {
            menorTemperatura = sensores[i].temperatura;
        }
    }

    mediaTemperatura = somaTemperatura / qteSensores;
    printf("Média das temperaturas: %.3f\n", mediaTemperatura);
    printf("Maior temperatura: %.3f\n", maiorTemperatura);
    printf("Menor temperatura: %.3f\n", menorTemperatura);

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

        for (int i = tamanhoAntigo; i < qteSensores; i++) {
            printf("Digite o código do sensor %d: ", (i + 1));
            scanf("%d", &sensores[i].codigo);
            printf("Digite a temperatura do sensor %d: ", (i + 1));
            scanf("%f", &sensores[i].temperatura);
        }

        somaTemperatura = 0.0;
        maiorTemperatura = sensores[0].temperatura;
        menorTemperatura = sensores[0].temperatura;

        printf("\nParametros com os novos sensores:\n");
        for (int i = 0; i < qteSensores; i++) {
            printf("Sensor %d - Código: %d, Temperatura: %.3f\n", (i + 1), sensores[i].codigo, sensores[i].temperatura);
            somaTemperatura += sensores[i].temperatura;

            if (sensores[i].temperatura > maiorTemperatura) {
                maiorTemperatura = sensores[i].temperatura;
            }

            if (sensores[i].temperatura < menorTemperatura) {
                menorTemperatura = sensores[i].temperatura;
            }
        }

        mediaTemperatura = somaTemperatura / qteSensores;

        printf("Média das temperaturas: %.3f\n", mediaTemperatura);
        printf("Maior temperatura: %.3f\n", maiorTemperatura);
        printf("Menor temperatura: %.3f\n", menorTemperatura);

        do {
            printf("Deseja adicionar mais sensores? (1 - Sim, 0 - Não): ");
        } while (scanf("%d", &opcao) != 1 || (opcao != 0 && opcao != 1));
    }

    free(sensores);
    sensores = NULL;

    return 0;
}