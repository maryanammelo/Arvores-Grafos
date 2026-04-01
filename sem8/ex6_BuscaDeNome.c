#include <stdio.h>

int pesquisaSequencial(char arr[], int tamanho, char alvo[]) {
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
    char dados[] = {"Daniel", "Ana", "Eduarda", "Carlos", "Bruna"};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    char alvo[] = "Ana";

    printf("\nIniciando pesquisa sequencial...\n\n");
    char resultado = pesquisaSequencial(dados, tamanho, alvo);
    printf("Resultado: %s , na posiçao %d ", alvo, resultado);
    return 0;
}

