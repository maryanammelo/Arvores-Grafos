#include <stdio.h>

int pesquisaSequencial(int arr[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        printf("--> Verificando posicao [%d] do array: %d == %d?\n", i, arr[i], alvo);
        if(arr[i] != alvo) {
        	printf("Valor %d != %d\n\n", arr[i], alvo);
		}
        if (arr[i] == alvo) {        	
        	printf("Valor %d == %d\n", arr[i], alvo);
            printf("\nValor encontrado na posicao %d\n", i);
            return i;
        }
    }
    printf("\nValor nao encontrado no vetor\n");
    return -1;
}

int main() {
    int dados[] = {55, 12, 89, 33, 21, 90, 44};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 76;

    printf("\nIniciando pesquisa sequencial...\n\n");
    int resultado = pesquisaSequencial(dados, tamanho, alvo);

    return 0;
}
