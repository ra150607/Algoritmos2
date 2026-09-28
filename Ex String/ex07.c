#include <stdio.h>

int main() {
    int qteChar = 0, palindromo;
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%99s", palavra);

    for(int i = 0; palavra[i] != '\0'; i++) {
        qteChar++;
    }

    for (int i = 0; i < qteChar; i++) {
        if(palavra[i] == palavra[(qteChar - 1) - i]){
            palindromo = 1;
        }
        else{
            palindromo = 0;
        }
    }

    if(palindromo == 1){
        printf("Essa palavra é um palindromo.");
    }
    else{
        printf("Essa palavra não é um palindromo.");
    }

    return 0;
}