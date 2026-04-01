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
    int dados[] = {10, 25, 10, 30, 45, 25, 60, 10};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int i, j;
    int temDuplicado = 0;
    printf("Verificando elementos duplicados...\n\n");

    for (i = 0; i < tamanho; i++) {
        int repetido = 0;

        for (j = 0; j < i; j++) {
            if (dados[i] == dados[j]) {
            repetido = 1;
            }
        }
        if (repetido == 0) {
        int contador = 0;

            for (j = 0; j < tamanho; j++) {
                if (dados[i] == dados[j]) {
                contador++;
                }
            }
            if (contador > 1) {
                printf("O valor %d aparece %d vezes\n", dados[i], contador);
                temDuplicado = 1;
            }
        }
    }
    if (temDuplicado == 0) {
        printf("Nao existem valores duplicados\n");
    }
    return 0;
}
