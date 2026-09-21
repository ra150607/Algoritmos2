#include <stdio.h>

int main() {
    int tmax = 10;
    int num[tmax], numMod[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < tmax; i++) {
        if (num[i] < 0) {
            numMod[i] = 0;
        } else {
            numMod[i] = num[i];
        }
    }

    printf("O novo vetor modificado é:\n");
    for (int i = 0; i < tmax; i++) {
        printf("%d\n", numMod[i]);
    }

    return 0;
}