#include <stdio.h>

void bubbleSort(int arr[], int n) {
int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
        if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
}
}
}
}

int pesquisaBinaria(int arr[], int esquerda, int direita, int alvo) {
    int comparacoes = 0;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        printf("\n--> Comparacao %d:\n", ++comparacoes);
        printf("Intervalo atual: esquerda = %d, direita = %d\n", esquerda, direita);
        printf("Indice do meio: %d (alvo = %d)\n", meio, arr[meio]);

        if (arr[meio] == alvo) {
            printf("Valor encontrado na posicao %d\n", meio);
            return meio;
        } else if (arr[meio] < alvo) {
            printf("%d eh maior que %d, indo para a metade direita\n", alvo, arr[meio]);
            esquerda = meio + 1;
        } else {
            printf("%d eh menor que %d, indo para a metade esquerda\n", alvo, arr[meio]);
            direita = meio - 1;
        }
    }
    printf("Valor nao encontrado no vetor\n");
    return -1;
}

int main() {
    int dados[] = {45, 12, 78, 3, 56, 89, 23, 6};
    printf("vetor antes da ordenaçao: [45, 12, 78, 3, 56, 89, 23, 6] \n");
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 55;

    printf("Iniciando pesquisa binaria...\n");
    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, alvo);
    printf("vetor depois da ordenaçao: %i", &resultado);
    
    return 0;
}

