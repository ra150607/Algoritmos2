#include <stdio.h>

int main() {
    int tmax = 10;
    int num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < tmax; i++) {
        if (num[i] % 2 == 0) {
            printf("O número %d é par\n", num[i]);
        }
    }

    printf("\n");

    for (int i = 0; i < tmax; i++) {
        if (num[i] % 2 != 0) {
            printf("O número %d é ímpar\n", num[i]);
        }
    }

    return 0;
}