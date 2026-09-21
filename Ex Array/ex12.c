#include <stdio.h>

int main() {
    int tmax = 10, numPesq = 0, cont = 0;
    int num[tmax];

    for (int i = 0; i < tmax; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("Digite o numero que deseja pesquisar: ");
    scanf("%d", &numPesq);

    for (int i = 0; i < tmax; i++) {
        if (num[i] == numPesq) {
            cont++;
        }
    }

    if (cont > 0) {
        printf("O numero %d foi encontrado %d vezes no vetor.\n", numPesq, cont);
    } else {
        printf("O numero %d nao foi encontrado no vetor.\n", numPesq);
    }

    return 0;
}