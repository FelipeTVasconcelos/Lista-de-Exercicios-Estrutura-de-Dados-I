/*
 * Questao 8 (Comercio)
 * Um supermercado registrou o horario de chegada de 10 fornecedores em
 * formato de minutos decorridos no dia (ex: 480 para 08:00). Este
 * programa usa o Insertion Sort para ordenar esses horarios em ordem
 * cronologica crescente.
 */
 
#include <stdio.h>

#define N 10

/* Ordena o vetor de horarios (em minutos) em ordem crescente usando Insertion Sort */
void insertion_sort(int horarios[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = horarios[i];
        int j = i - 1;

        /* desloca os elementos maiores que a chave uma posicao a frente */
        while (j >= 0 && horarios[j] > chave) {
            horarios[j + 1] = horarios[j];
            j--;
        }
        horarios[j + 1] = chave;
    }
}

/* Converte minutos decorridos no dia para o formato HH:MM e exibe */
void exibir_horarios(int horarios[], int n) {
    for (int i = 0; i < n; i++) {
        int hh = horarios[i] / 60;
        int mm = horarios[i] % 60;
        printf("%02d:%02d  ", hh, mm);
    }
    printf("\n");
}

int main(void) {
    /* Horarios de chegada em minutos decorridos no dia */
    int horarios[N] = {480, 375, 610, 495, 420, 555, 360, 700, 405, 530};

    printf("Horarios de chegada (desordenados):\n");
    exibir_horarios(horarios, N);

    insertion_sort(horarios, N);

    printf("\nHorarios de chegada (ordenados cronologicamente):\n");
    exibir_horarios(horarios, N);

    return 0;
}
