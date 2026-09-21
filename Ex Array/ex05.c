#include <stdio.h>

int main() {
    int tmax = 10, maiorNum = -2147483648;
    int num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < tmax; i++) {
        if (num[i] > maiorNum) {
            maiorNum = num[i];
        }
    }

    printf("O maior número digitado foi: %d\n", maiorNum);

    return 0;
}