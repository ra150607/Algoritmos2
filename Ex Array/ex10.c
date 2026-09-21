#include <stdio.h>

int main() {
    int tmax = 10;
    int A[tmax], B[tmax], C[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero do vetor A: ", i + 1);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero do vetor B: ", i + 1);
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < tmax; i++) {
        C[i] = A[i] + B[i];
        printf("A soma do %dº numero dos vetores A e B é: %d\n", i + 1, C[i]);
    }

    return 0;
}