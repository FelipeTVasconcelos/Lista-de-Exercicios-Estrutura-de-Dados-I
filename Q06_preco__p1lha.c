//Sistema que registra o histórico de preços antigos de um produto utilizando a estrutura de dados Pilha Encadeada (LIFO - Last In,First Out). A cada alteração realizada, o preço anterior é salvo no topo da pilha, permitindo que a operação de "Desfazer" restaure sucessivamente o último preço modificado.

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha encadeada
typedef struct No {
    float preco_antigo;
    struct No* proximo;
} No;

// Estrutura da Pilha
typedef struct {
    No* topo;
} Pilha;

// Função para inicializar a pilha
Pilha* criar_pilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

// Função para empilhar um novo preço antigo (registrar uma alteração)
void empilhar_preco(Pilha* p, float preco) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    novo->preco_antigo = preco;
    novo->proximo = p->topo; // O novo nó aponta para o antigo topo
    p->topo = novo;          // O topo passa a ser o novo nó
    printf("Alteração registrada: preço antigo (R$ %.2f) empilhado.\n", preco);
}

// Função para desempilhar (realizar a ação de Undo / Desfazer)
int desfazer_alteracao(Pilha* p, float* preco_restaurado) {
    if (p->topo == NULL) {
        printf("Nenhuma alteração para desfazer (pilha vazia).\n");
        return 0; // Indica falha por pilha vazia
    }
    
    No* temp = p->topo;
    *preco_restaurado = temp->preco_antigo; // Recupera o preço do topo
    p->topo = temp->proximo;                // Atualiza o topo para o nó anterior
    free(temp);                             // Libera a memória do nó removido
    return 1; // Sucesso
}

// Função para exibir o histórico de preços salvos na pilha
void exibir_historico(Pilha* p) {
    if (p->topo == NULL) {
        printf("Histórico de alterações vazio.\n");
        return;
    }
    printf("\n--- Histórico de Preços Antigos (Topo -> Base) ---\n");
    No* atual = p->topo;
    while (atual != NULL) {
        printf("R$ %.2f\n", atual->preco_antigo);
        atual = atual->proximo;
    }
    printf("--------------------------------------------------\n");
}

// Função para liberar a memória da pilha ao finalizar o programa
void liberar_pilha(Pilha* p) {
    No* atual = p->topo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(p);
}

// Função principal de teste
int main() {
    Pilha* historico_undo = criar_pilha();
    float preco_atual = 100.00;

    printf("Preço inicial do produto: R$ %.2f\n\n", preco_atual);

    // Simulando alterações de preço pelo usuário
    printf("--- Simulando edições no preço ---\n");
    
    // Alteração 1: Preço muda de 100.00 para 120.00
    empilhar_preco(historico_undo, preco_atual);
    preco_atual = 120.00;
    printf("Preço atualizado para: R$ %.2f\n\n", preco_atual);

    // Alteração 2: Preço muda de 120.00 para 89.90
    empilhar_preco(historico_undo, preco_atual);
    preco_atual = 89.90;
    printf("Preço atualizado para: R$ %.2f\n\n", preco_atual);

    // Alteração 3: Preço muda de 89.90 para 99.90
    empilhar_preco(historico_undo, preco_atual);
    preco_atual = 99.90;
    printf("Preço atualizado para: R$ %.2f\n\n", preco_atual);

    exibir_historico(historico_undo);

    // Simulando ações de "Desfazer" (Undo)
    printf("--- Simulando ações de 'Desfazer' (Undo) ---\n");
    float preco_desfeito;

    // 1º Undo
    if (desfazer_alteracao(historico_undo, &preco_desfeito)) {
        preco_atual = preco_desfeito;
        printf(" -> Undo realizado! Preço restaurado para: R$ %.2f\n", preco_atual);
    }

    // 2º Undo
    if (desfazer_alteracao(historico_undo, &preco_desfeito)) {
        preco_atual = preco_desfeito;
        printf(" -> Undo realizado! Preço restaurado para: R$ %.2f\n", preco_atual);
    }

    exibir_historico(historico_undo);

    // Liberando memória
    liberar_pilha(historico_undo);

    return 0;
}
