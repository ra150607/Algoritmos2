#include <stdio.h>

int main() {
    int tmax = 10;
    int num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }
    
    for (int i = 9; i >= 0; i--) {
        printf("O %dº numero digitado foi: %d\n", i + 1, num[i]);
    }
    return 0;
}