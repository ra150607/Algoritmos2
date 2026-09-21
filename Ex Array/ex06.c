#include <stdio.h>

int main() {
    int tmax = 10, menorNum = 2147483647, menorIndex = 0;
    int num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }
    
    for (int i = 0; i < tmax; i++) {
        if (num[i] < menorNum) {
            menorNum = num[i];
            menorIndex = i;
        }
    }
    printf("O menor número digitado foi: %d\n", menorNum);
    printf("Ele estava na posição: %d\n", menorIndex + 1);
    return 0;
}