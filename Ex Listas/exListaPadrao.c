#include <stdio.h>

#define CAPACIDADE 10
typedef struct {
    int dados[CAPACIDADE];
    int tamanho;
} Lista; 

void inicializar(Lista *lista) {
    lista->tamanho = 0;
}

int inserirFim(Lista *lista, int valor) {
    if (lista->tamanho == CAPACIDADE) {
        return 0;
    }
    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
}

void exibir(const Lista *lista) {
    printf("Elementos da lista: ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

int procuraValor(const Lista *lista, int valor) {
    int pos = 0;
    while (pos < lista->tamanho && lista->dados[pos] != valor) {
        pos++;
    }
    if (pos < lista->tamanho) {
        return pos;
    } else {
        return -1;
    }
}

int main(){
    Lista lista;
    inicializar(&lista);

    printf("Digite um valor para inserir no final da lista: ");
    int valor;
    scanf("%d", &valor);
    while( valor != -1 ) {
        if (inserirFim(&lista, valor) == 1) {
            printf("Valor inserido com sucesso.\n");
        } else {
            printf("Falha ao inserir valor. Lista cheia.\n");
        }
        printf("Digite outro valor para inserir no final da lista (ou -1 para sair): ");
        scanf("%d", &valor);
    }

    exibir(&lista);

    printf("Digite um valor para procurar na lista: ");
    int valor;
    scanf("%d", &valor);
    int posicao = procuraValor(&lista, valor);
    if (posicao != -1) {
        printf("Valor encontrado na posição: %d\n", posicao);
    } else {
        printf("Valor não encontrado na lista.\n");
    }
    return 0;
}