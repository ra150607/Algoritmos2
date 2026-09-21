#include <stdio.h>

int main() {
    int tmax = 10, qteNegativo = 0;;
    float num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%f", &num[i]);
    }

    for (int i = 0; i < tmax; i++) {
        if (num[i] < 0) {
            qteNegativo++;
        }else {
            printf("O número %.2f é positivo\n", num[i]);
        }
    }

    printf("A quantidade de números negativos é: %d\n", qteNegativo);

    return 0;
}