#include <stdio.h>

int pesquisaSequencial(int arr[], int tamanho, int alvo) {
    int comparacoes =0;

    for (int i = 0;i < tamanho; i++) {
        comparacoes++;

        printf("Comparacao %d\n", comparacoes);
        printf("Verificando posicao [%d] do array: %d == %d?\n", i, arr[i], alvo);

        if (arr[i] != alvo) {
            printf("Valor %d != %d\n\n", arr[i], alvo);
        }

        if (arr[i] == alvo) {
            printf("Valor %d == %d\n", arr[i], alvo);
            printf("\nValor encontrado na posicao %d\n", i);
            printf("Total de comparacoes: %d\n", comparacoes);
            return i;
        }
    }
  printf("\nValor nao encontrado no vetor\n");
    printf("Total de comparacoes:%d\n", comparacoes);
    return -1;
}
int main() {
    int dados[] = {321, 105, 876, 432, 210, 654, 999, 111};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 432;

    printf("\nIniciando pesquisa sequencial...\n\n");
    int resultado = pesquisaSequencial(dados, tamanho, alvo);

    return 0;
}
