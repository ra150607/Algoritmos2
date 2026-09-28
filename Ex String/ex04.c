#include <stdio.h>

int main() {
    int qteChar = 0, qteLetra = 0;
    char letra;
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%99s", palavra);

    printf("Digite uma letra: ");
    scanf(" %c", &letra);

    for(int i = 0; palavra[i] != '\0'; i++) {
        qteChar++;
    }

    for (int i = 0; i < qteChar; i++) {
        if (palavra[i] == letra) {
            qteLetra++;
        }
    }

    printf("A palavra digitada tem %d letras '%c'.", qteLetra, letra);

    return 0;
}