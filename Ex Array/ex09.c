#include <stdio.h>

int main() {
    int tmax = 10, numInt = 0;
    int num[tmax], numMult[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("Digite um número inteiro: ");
    scanf("%d", &numInt);
    
    for (int i = 0; i < tmax; i++) {
        numMult[i] = num[i] * numInt;
        printf("O %dº numero multiplicado por %d foi: %d\n", i + 1, numInt, numMult[i]);
    }

    return 0;
}