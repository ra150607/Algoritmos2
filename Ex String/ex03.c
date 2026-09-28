#include <stdio.h>

int main() {
    int qteChar = 0, qteVogal = 0;
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%99s", palavra);

    for(int i = 0; palavra[i] != '\0'; i++) {
        qteChar++;
    }

    for (int i = 0; i < qteChar; i++) {
        if (palavra[i] == 'a' || palavra[i] == 'A' || palavra[i] == 'e' || palavra[i] == 'E' || palavra[i] == 'i' || palavra[i] == 'I' || palavra[i] == 'o' || palavra[i] == 'O' || palavra[i] == 'u' || palavra[i] == 'U') {
            qteVogal++;
        }
    }

    printf("A palavra digitada tem %d vogais.", qteVogal);

    return 0;
}