#include <stdio.h>
#include <time.h>

#define MAX 10000

long long comparacoes;
long long movimentacoes;

void criarVetorDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {

            comparacoes++;

            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                movimentacoes++;
            }
        }
    }
}

void selectionSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < tamanho; j++) {

            comparacoes++;

            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
            movimentacoes++;
        }
    }
}

void imprimirLinha() {
    printf("-------------------------------------------------------------------------\n");
}

void testarAlgoritmo(char nome[], void (*algoritmo)(int[], int), int tamanho) {

    int vetor[MAX];

    criarVetorDecrescente(vetor, tamanho);

    comparacoes = 0;
    movimentacoes = 0;

    clock_t inicio = clock();

    algoritmo(vetor, tamanho);

    clock_t fim = clock();

    double tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("| %-15s | %-7d | %-10.3f | %-12lld | %-13lld |\n",
           nome, tamanho, tempo_ms, comparacoes, movimentacoes);
}

int main() {

    imprimirLinha();
    printf("| %-15s | %-7s | %-10s | %-12s | %-14s |\n",
           "algoritmo", "tamanho", "tempo(ms)", "comparacoes", "movimentacoes");
    imprimirLinha();

    int tamanhos[] = {100, 1000, 10000};

    for (int i = 0; i < 3; i++)
        testarAlgoritmo("Bubble Sort", bubbleSort, tamanhos[i]);

    for (int i = 0; i < 3; i++)
        testarAlgoritmo("Selection Sort", selectionSort, tamanhos[i]);

    imprimirLinha();

    return 0;
}
