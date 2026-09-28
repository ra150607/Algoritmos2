#include <stdio.h>

int main() {
    int qteChar = 0;
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%99s", palavra);

    for(int i = 0; palavra[i] != '\0'; i++) {
        qteChar++;
    }

    for (int i = 0; i < qteChar; i++) {
        if (palavra[i] == 'a') {
            palavra[i] = '@';
        }
    }

    for (int i = 0; i < qteChar; i++) {
        printf("%c", palavra[i]);
    }

    return 0;
}