
 //Questao 3 (Turismo)
 //Fila para gerenciar a entrada de turistas em uma montanha-russa.
 //Cada turista possui: nome (string) e idade (int).
 //Funcoes principais:
 //enfileirar_turista(): insere no fim da fila
 //atender_turista(): remove do inicio da fila
 //Implementada com fila encadeada (sem limite fixo de tamanho).
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50

// No da fila 
typedef struct NoTurista {
    char nome[TAM_NOME];
    int idade;
    struct NoTurista *proximo;
} NoTurista;

// Estrutura da fila com ponteiros para inicio e fim 
typedef struct {
    NoTurista *inicio;
    NoTurista *fim;
} Fila;

// Inicializa a fila vazia
void inicializar_fila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Insere um turista no fim da fila (enfileirar) 
void enfileirar_turista(Fila *fila, const char *nome, int idade) {
    NoTurista *novo = (NoTurista *) malloc(sizeof(NoTurista));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->proximo = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    printf("Turista '%s' entrou na fila.\n", nome);
}

// Remove e atende o turista do inicio da fila 
int atender_turista(Fila *fila, char *nome_saida, int *idade_saida) {
    if (fila->inicio == NULL) {
        printf("Fila vazia! Nenhum turista para atender.\n");
        return 0;
    }
    NoTurista *removido = fila->inicio;
    strcpy(nome_saida, removido->nome);
    *idade_saida = removido->idade;

    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(removido);
    return 1;
}

int main(void) {
    Fila fila;
    inicializar_fila(&fila);

    enfileirar_turista(&fila, "Ana", 22);
    enfileirar_turista(&fila, "Bruno", 17);
    enfileirar_turista(&fila, "Carla", 30);

    printf("\n--- Iniciando embarque na montanha-russa ---\n");
    char nome[TAM_NOME];
    int idade;
    while (atender_turista(&fila, nome, &idade)) {
        printf("Embarcou: %s (%d anos)\n", nome, idade);
    }

    // Testa fila vazia 
    atender_turista(&fila, nome, &idade);

    return 0;
}
