/*
 * Questao 10 (E-commerce)
 * Uma grande rede de lojas possui um vetor com 1000 IDs de clientes
 * rigorosamente ordenados de forma crescente. Este programa implementa
 * uma busca binaria para localizar rapidamente se um determinado ID de
 * cliente esta ativo na base de dados.
 */

#include <stdio.h>

#define N 1000

/* Busca binaria: divide o intervalo de busca pela metade a cada
 * iteracao, aproveitando que o vetor esta ordenado. Retorna o indice do
 * ID se encontrado, ou -1 caso contrario. Complexidade O(log n). */
int busca_binaria(int ids[], int n, int id_procurado) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (ids[meio] == id_procurado) {
            return meio;
        } else if (ids[meio] < id_procurado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; /* nao encontrado */
}

int main(void) {
    /* Gera um vetor de 1000 IDs de clientes, ordenados de forma crescente.
     * Ex.: IDs de 2 em 2, comecando em 1000 (1000, 1002, 1004, ...) */
    int ids_clientes[N];
    for (int i = 0; i < N; i++) {
        ids_clientes[i] = 1000 + i * 2;
    }

    int procurado1 = 2500; /* ID existente na base (ativo) */
    int procurado2 = 2501; /* ID inexistente (numero impar, nao esta na base) */

    int indice1 = busca_binaria(ids_clientes, N, procurado1);
    if (indice1 != -1) {
        printf("Cliente com ID %d esta ativo na base (posicao %d).\n", procurado1, indice1);
    } else {
        printf("Cliente com ID %d NAO foi encontrado na base.\n", procurado1);
    }

    int indice2 = busca_binaria(ids_clientes, N, procurado2);
    if (indice2 != -1) {
        printf("Cliente com ID %d esta ativo na base (posicao %d).\n", procurado2, indice2);
    } else {
        printf("Cliente com ID %d NAO foi encontrado na base.\n", procurado2);
    }

    return 0;
}
