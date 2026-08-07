/*
 * Questao 1 (E-commerce)
 * Lista encadeada para armazenar o carrinho de compras de um cliente.
 * Cada no contem: ID_produto (int), quantidade (int) e preco (float).
 *
 * Funcoes principais:
 *  - inserir_item(): insere um novo item no inicio da lista
 *  - calcular_total(): percorre a lista e soma (quantidade * preco) de cada item
 */

#include <stdio.h>
#include <stdlib.h>

/* Estrutura do no do carrinho */
typedef struct Item {
    int id_produto;
    int quantidade;
    float preco;
    struct Item *proximo;
} Item;

/* Insere um novo item no inicio da lista encadeada.
 * Recebe o ponteiro para o inicio da lista (por referencia) e os dados do item. */
void inserir_item(Item **inicio, int id_produto, int quantidade, float preco) {
    Item *novo = (Item *) malloc(sizeof(Item));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    novo->id_produto = id_produto;
    novo->quantidade = quantidade;
    novo->preco = preco;
    novo->proximo = *inicio;
    *inicio = novo;
}

/* Calcula o valor total do carrinho somando quantidade * preco de cada item */
float calcular_total(Item *inicio) {
    float total = 0.0f;
    Item *atual = inicio;
    while (atual != NULL) {
        total += atual->quantidade * atual->preco;
        atual = atual->proximo;
    }
    return total;
}

/* Exibe todos os itens do carrinho */
void exibir_carrinho(Item *inicio) {
    Item *atual = inicio;
    printf("---- Carrinho de Compras ----\n");
    while (atual != NULL) {
        printf("Produto: %d | Qtd: %d | Preco unit.: R$ %.2f\n",
               atual->id_produto, atual->quantidade, atual->preco);
        atual = atual->proximo;
    }
    printf("------------------------------\n");
}

/* Libera toda a memoria alocada pela lista */
void liberar_lista(Item *inicio) {
    Item *atual = inicio;
    while (atual != NULL) {
        Item *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main(void) {
    Item *carrinho = NULL;

    inserir_item(&carrinho, 101, 2, 29.90f);
    inserir_item(&carrinho, 102, 1, 149.99f);
    inserir_item(&carrinho, 103, 3, 9.50f);

    exibir_carrinho(carrinho);

    float total = calcular_total(carrinho);
    printf("Valor total do carrinho: R$ %.2f\n", total);

    liberar_lista(carrinho);
    return 0;
}
