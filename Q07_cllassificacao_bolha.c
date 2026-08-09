//Questao 7 (Turismo)
// Uma agencia de viagens tem um vetor com os precos de 8 pacotes
//turisticos desordenados. Este programa implementa o algoritmo
//Bubble Sort para ordenar esses precos do mais barato para o mais caro.

#include <stdio.h>

#define N 8

// Ordena o vetor de precos em ordem crescente usando Bubble Sort 
void bubble_sort(float precos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int houve_troca = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (precos[j] > precos[j + 1]) {
                // troca os elementos de posicao 
                float temp = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = temp;
                houve_troca = 1;
            }
        }
        // otimizacao: se nao houve troca, o vetor ja esta ordenado 
        if (!houve_troca) {
            break;
        }
    }
}

// Exibe o vetor de precos formatado 
void exibir_precos(float precos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("R$ %.2f ", precos[i]);
    }
    printf("\n");
}

int main(void) {
    float precos[N] = {1899.90f, 599.00f, 3200.50f, 250.00f,
                        1200.00f, 899.99f, 450.75f, 2100.00f};

    printf("Precos dos pacotes (desordenados):\n");
    exibir_precos(precos, N);

    bubble_sort(precos, N);

    printf("\nPrecos dos pacotes (ordenados - mais barato ao mais caro):\n");
    exibir_precos(precos, N);

    return 0;
}
