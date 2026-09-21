#include <stdio.h>

int main() {
    int tmax = 10;
    float media = 0, soma = 0;
    float notas[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite a %dª nota: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
    media = soma / tmax;
    printf("A média das notas digitadas é: %f\n", media);

    for (int i = 0; i < tmax; i++) {
        if (notas[i] >= media) {
            printf("A %dª nota é maior ou igual à média: %f\n", i + 1, notas[i]);
        }
    }

    return 0;
}