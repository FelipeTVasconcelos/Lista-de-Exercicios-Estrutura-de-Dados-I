/*
 * Questao 2 (Logistica)
 * Lista sequencial (vetor) de paradas de uma rota de entrega.
 * Cada parada possui: nome do bairro (string) e prazo_minutos (int).
 *
 * Funcao principal:
 *  - remover_parada(): remove uma parada da rota (por indice) quando a
 *    entrega e concluida, deslocando os elementos seguintes.
 */

#include <stdio.h>
#include <string.h>

#define MAX_PARADAS 50
#define TAM_NOME 50

/* Estrutura de uma parada da rota */
typedef struct {
    char bairro[TAM_NOME];
    int prazo_minutos;
} Parada;

/* Insere uma nova parada no final da lista sequencial */
void inserir_parada(Parada rota[], int *quantidade, const char *bairro, int prazo_minutos) {
    if (*quantidade >= MAX_PARADAS) {
        printf("Rota cheia! Nao e possivel adicionar mais paradas.\n");
        return;
    }
    strcpy(rota[*quantidade].bairro, bairro);
    rota[*quantidade].prazo_minutos = prazo_minutos;
    (*quantidade)++;
}

/* Remove uma parada da rota pelo indice, quando a entrega e concluida.
 * Desloca os elementos seguintes uma posicao para a esquerda. */
int remover_parada(Parada rota[], int *quantidade, int indice) {
    if (indice < 0 || indice >= *quantidade) {
        printf("Indice invalido!\n");
        return 0;
    }
    for (int i = indice; i < *quantidade - 1; i++) {
        rota[i] = rota[i + 1];
    }
    (*quantidade)--;
    return 1;
}

/* Exibe a rota atual */
void exibir_rota(Parada rota[], int quantidade) {
    printf("---- Rota Atual ----\n");
    for (int i = 0; i < quantidade; i++) {
        printf("[%d] Bairro: %s | Prazo: %d min\n", i, rota[i].bairro, rota[i].prazo_minutos);
    }
    printf("---------------------\n");
}

int main(void) {
    Parada rota[MAX_PARADAS];
    int quantidade = 0;

    inserir_parada(rota, &quantidade, "Centro", 15);
    inserir_parada(rota, &quantidade, "Jurunas", 25);
    inserir_parada(rota, &quantidade, "Umarizal", 10);
    inserir_parada(rota, &quantidade, "Marco", 30);

    exibir_rota(rota, quantidade);

    /* Entrega do bairro "Jurunas" (indice 1) foi concluida */
    printf("\nEntrega concluida em: %s\n", rota[1].bairro);
    remover_parada(rota, &quantidade, 1);

    printf("\nRota apos remocao:\n");
    exibir_rota(rota, quantidade);

    return 0;
}
