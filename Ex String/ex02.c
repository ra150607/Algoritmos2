#include <stdio.h>

int main() {
    int qteChar = 0;
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%99s", palavra);

    for(int i = 0; palavra[i] != '\0'; i++) {
        qteChar++;
    }

    printf("A palavra digitada tem %d caracteres.\n", qteChar);

    return 0;
}