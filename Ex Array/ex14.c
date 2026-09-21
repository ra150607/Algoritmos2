#include <stdio.h>

int main() {
    int tmax = 10, maiorNum = -2147483648, menorNum = 2147483647, diferenca;
    int num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < tmax; i++) {
        if (num[i] > maiorNum) {
            maiorNum = num[i];
        }
        if (num[i] < menorNum) {
            menorNum = num[i];
        }
    }

    diferenca = maiorNum - menorNum;

    printf("O maior número digitado foi: %d\n", maiorNum);
    printf("O menor número digitado foi: %d\n", menorNum);
    printf("A diferença entre eles é: %d\n", diferenca);

    return 0;
}