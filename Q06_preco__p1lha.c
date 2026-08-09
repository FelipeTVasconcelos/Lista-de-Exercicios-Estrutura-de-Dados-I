//Questao 5 (Logistica)
//Pilha (LIFO) para representar caixas empilhadas em um palete estreito.
//A ultima caixa colocada e a primeira a ser retirada.
//Cada caixa possui um codigo_rastreio (string).
//Funcoes principais é empilhar_caixa(): adiciona uma caixa no topo da pilha e desempilhar_caixa(): remove a caixa do topo da pilha
//Implementada com pilha estatica (vetor).

#include <stdio.h>
#include <string.h>

#define MAX_CAIXAS 30
#define TAM_CODIGO 30

// Estrutura da pilha de caixas 
typedef struct {
    char codigos[MAX_CAIXAS][TAM_CODIGO];
    int topo; // indice do topo da pilha, -1 quando vazia
} PilhaCaixas;

// Inicializa a pilha vazia 
void inicializar_pilha(PilhaCaixas *pilha) {
    pilha->topo = -1;
}

// Verifica se a pilha esta cheia 
int pilha_cheia(PilhaCaixas *pilha) {
    return pilha->topo == MAX_CAIXAS - 1;
}

// Verifica se a pilha esta vazia 
int pilha_vazia(PilhaCaixas *pilha) {
    return pilha->topo == -1;
}

// Empilha (adiciona) uma caixa no topo do palete 
void empilhar_caixa(PilhaCaixas *pilha, const char *codigo_rastreio) {
    if (pilha_cheia(pilha)) {
        printf("Palete cheio! Nao e possivel empilhar mais caixas.\n");
        return;
    }
    pilha->topo++;
    strcpy(pilha->codigos[pilha->topo], codigo_rastreio);
    printf("Caixa [%s] empilhada no palete.\n", codigo_rastreio);
}

// Desempilha (remove) a caixa do topo do palete
int desempilhar_caixa(PilhaCaixas *pilha, char *codigo_saida) {
    if (pilha_vazia(pilha)) {
        printf("Palete vazio! Nao ha caixas para retirar.\n");
        return 0;
    }
    strcpy(codigo_saida, pilha->codigos[pilha->topo]);
    pilha->topo--;
    return 1;
}

int main(void) {
    PilhaCaixas palete;
    inicializar_pilha(&palete);

    empilhar_caixa(&palete, "BR-001");
    empilhar_caixa(&palete, "BR-002");
    empilhar_caixa(&palete, "BR-003");

    printf("\n--- Retirando caixas do palete (LIFO) ---\n");
    char codigo[TAM_CODIGO];
    while (desempilhar_caixa(&palete, codigo)) {
        printf("Caixa retirada: %s\n", codigo);
    }

    // Testa pilha vazia 
    desempilhar_caixa(&palete, codigo);

    return 0;
}
