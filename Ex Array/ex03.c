#include <stdio.h>

int main() {
    int tmax = 8;
    int soma = 0;
    int num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
        soma += num[i];
    }
    printf("A soma dos numeros digitados é: %d\n", soma);
    return 0;
}