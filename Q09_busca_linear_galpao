/*
 * Questao 9 (Logistica)
 * Um galpao possui 15 posicoes de armazenamento nao ordenadas, cada uma
 * com um codigo_barras (int). Este programa implementa uma busca linear
 * que retorna o indice do vetor onde o codigo digitado pelo operador se
 * encontra, ou -1 se nao existir.
 */

#include <stdio.h>

#define N 15

/* Busca linear: percorre o vetor sequencialmente ate encontrar o codigo
 * ou chegar ao fim. Retorna o indice se encontrado, ou -1 caso contrario. */
int busca_linear(int codigos[], int n, int codigo_procurado) {
    for (int i = 0; i < n; i++) {
        if (codigos[i] == codigo_procurado) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int codigos_barras[N] = {
        78912, 34567, 90123, 45678, 11223,
        99887, 55443, 22110, 67890, 13579,
        24680, 36925, 48120, 75310, 86420
    };

    int procurado1 = 67890; /* codigo existente */
    int procurado2 = 10101; /* codigo inexistente */

    int indice1 = busca_linear(codigos_barras, N, procurado1);
    if (indice1 != -1) {
        printf("Codigo %d encontrado na posicao %d.\n", procurado1, indice1);
    } else {
        printf("Codigo %d nao encontrado no galpao.\n", procurado1);
    }

    int indice2 = busca_linear(codigos_barras, N, procurado2);
    if (indice2 != -1) {
        printf("Codigo %d encontrado na posicao %d.\n", procurado2, indice2);
    } else {
        printf("Codigo %d nao encontrado no galpao.\n", procurado2);
    }

    return 0;
}
