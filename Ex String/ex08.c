#include <stdio.h>

int main() {
    int qteChar1 = 0, qteChar2 = 0;
    char palavra1[100], palavra2[100];

    printf("Digite a 1ª palavra: ");
    scanf("%99s", palavra1);
    printf("Digite a 2ª palavra: ");
    scanf("%99s", palavra2);

    for(int i = 0; palavra1[i] != '\0'; i++) {
        qteChar1++;
    }
    for(int i = 0; palavra2[i] != '\0'; i++) {
        qteChar2++;
    }

    if(qteChar1 > qteChar2){
        printf("A palavra %s tem mais caracteres, ela possui %d caracteres.", palavra1, qteChar1);
    }else if(qteChar2 > qteChar1){
        printf("A palavra %s tem mais caracteres, ela possui %d caracteres.", palavra2, qteChar2);
    }
    else{
        printf("Ambas as palavras tem %d caracteres.", qteChar1);
    }

    return 0;
}