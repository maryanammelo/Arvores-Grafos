#include <stdio.h>

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
    int dados[] = {11987654321, 11991234567, 11993456789, 11995678901, 11997890123};  
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 11997890123;

    printf("Iniciando pesquisa binaria...\n");
    int resultado = pesquisaBinaria(dados, 0, tamanho - 1, alvo);

    return 0;
}

