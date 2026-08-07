/*
 * Questao 4 (Comercio)
 * Fila de impressao de pedidos da cozinha de um restaurante.
 * Cada pedido possui: numero_pedido (int) e nome_prato (string).
 *
 * Funcao principal:
 *  - desenfileirar_pedido(): remove e exibe o proximo prato que a
 *    cozinha deve preparar (comportamento FIFO).
 *
 * Implementada com fila estatica (vetor circular).
 */

#include <stdio.h>
#include <string.h>

#define MAX_PEDIDOS 20
#define TAM_NOME 50

/* Estrutura de um pedido */
typedef struct {
    int numero_pedido;
    char nome_prato[TAM_NOME];
} Pedido;

/* Estrutura da fila de pedidos (vetor circular) */
typedef struct {
    Pedido pedidos[MAX_PEDIDOS];
    int inicio;
    int fim;
    int total;
} FilaPedidos;

/* Inicializa a fila de pedidos */
void inicializar_fila(FilaPedidos *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->total = 0;
}

/* Insere um novo pedido no fim da fila */
void enfileirar_pedido(FilaPedidos *fila, int numero_pedido, const char *nome_prato) {
    if (fila->total >= MAX_PEDIDOS) {
        printf("Fila de pedidos cheia!\n");
        return;
    }
    fila->fim = (fila->fim + 1) % MAX_PEDIDOS;
    fila->pedidos[fila->fim].numero_pedido = numero_pedido;
    strcpy(fila->pedidos[fila->fim].nome_prato, nome_prato);
    fila->total++;
    printf("Pedido #%d (%s) enviado para a cozinha.\n", numero_pedido, nome_prato);
}

/* Remove (desenfileira) e exibe o proximo prato que a cozinha deve preparar */
int desenfileirar_pedido(FilaPedidos *fila) {
    if (fila->total == 0) {
        printf("Nenhum pedido pendente na cozinha.\n");
        return 0;
    }
    Pedido atual = fila->pedidos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_PEDIDOS;
    fila->total--;

    printf(">>> Proximo prato a preparar: #%d - %s\n", atual.numero_pedido, atual.nome_prato);
    return 1;
}

int main(void) {
    FilaPedidos fila;
    inicializar_fila(&fila);

    enfileirar_pedido(&fila, 1, "Feijoada");
    enfileirar_pedido(&fila, 2, "Moqueca");
    enfileirar_pedido(&fila, 3, "Acai com peixe frito");

    printf("\n--- Cozinha comecando a preparar os pedidos ---\n");
    desenfileirar_pedido(&fila);
    desenfileirar_pedido(&fila);
    desenfileirar_pedido(&fila);
    desenfileirar_pedido(&fila); /* fila vazia */

    return 0;
}
