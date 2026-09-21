#include <stdio.h>

int main() {
    int tmax = 15, qtePar = 0, qteImpar = 0;
    int num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }
    
    for (int i = 0; i < tmax; i++) {
        if (num[i] % 2 == 0) {
            qtePar++;
        } else {
            qteImpar++;
        }
    }
    printf("Quantidade de números pares: %d\n", qtePar);
    printf("Quantidade de números ímpares: %d\n", qteImpar);
    return 0;
}