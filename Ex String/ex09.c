#include <stdio.h>

int tamanho(char palavra[]) {
    int qteChar = 0;

    for(int i = 0; palavra[i] != '\0'; i++) {
        qteChar++;
    }

    return qteChar;
}

char letraEspecifica(char palavra[], int posicao) {
    return palavra[posicao - 1];
}

int vogais(char palavra[]) {
    int qteVogais = 0;

    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] == 'a' || palavra[i] == 'A' || palavra[i] == 'e' || palavra[i] == 'E' || palavra[i] == 'i' || palavra[i] == 'I' || palavra[i] == 'o' || palavra[i] == 'O' || palavra[i] == 'u' || palavra[i] == 'U') {
            qteVogais++;
        }
    }

    return qteVogais;
}

int consoantes(char palavra[]) {
    int qteConsoantes = 0;

    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] != 'a' && palavra[i] != 'A' && palavra[i] != 'e' && palavra[i] != 'E' && palavra[i] != 'i' && palavra[i] != 'I' && palavra[i] != 'o' && palavra[i] != 'O' && palavra[i] != 'u' && palavra[i] != 'U') {
            qteConsoantes++;
        }
    }

    return qteConsoantes;
}

void palavraInvertida(char palavra[], char invertida[]) {
    int qteChar = tamanho(palavra);

    for (int i = 0; i < qteChar; i++) {
        invertida[i] = palavra[(qteChar - 1) - i];
    }

    invertida[qteChar] = '\0';
}

int verifPalindromo(char palavra[]){
    int qteChar = tamanho(palavra);

    int palindromo = 0;

    for (int i = 0; i < qteChar; i++) {
        if(palavra[i] == palavra[(qteChar - 1) - i]){
            palindromo = 1;
        }
        else{
            palindromo = 0;
        }
    }

    return palindromo;
}

int main() {
    int qteChar = 0, qteVogais = 0, qteConsoantes = 0, palindromo;
    char palavra[100], palavraInvert[100], primeiraLetra, ultimaLetra;

    printf("Digite uma palavra: ");
    scanf("%99s", palavra);

    qteChar = tamanho(palavra);
    primeiraLetra = letraEspecifica(palavra, 1);
    ultimaLetra = letraEspecifica(palavra, qteChar);
    qteVogais = vogais(palavra);
    qteConsoantes = consoantes(palavra);
    palavraInvertida(palavra, palavraInvert);
    palindromo = verifPalindromo(palavra);

    printf("A palavra digitada foi: %s\n", palavra);
    printf("A quantidade de caracteres da palavra é: %d \n", qteChar);
    printf("A primeira letra da palavra é: %c \n", primeiraLetra);
    printf("A ultima letra da palavra é: %c \n", ultimaLetra);
    printf("A quantidade de vogais da palavra é: %d \n", qteVogais);
    printf("A quantidade de consoantes da palavra é: %d \n", qteConsoantes);
    printf("A palavra invertida é: %s \n", palavraInvert);

    if(palindromo == 1){
        printf("Essa palavra é um palindromo.");
    }
    else{
        printf("Essa palavra não é um palindromo.");
    }

    return 0;
}