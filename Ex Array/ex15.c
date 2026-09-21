#include <stdio.h>

int main() {
    int tmax = 10;
    int num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("\nValores digitados (sem repeticao):\n");
    for (int i = 0; i < tmax; i++) {
        int jaApareceu = 0;

        for (int j = 0; j < i; j++) {
            if (num[i] == num[j]) {
                jaApareceu = 1;
                break;
            }
        }

        if (!jaApareceu) {
            printf("%d ", num[i]);
        }
    }
    printf("\n");

    return 0;
}
