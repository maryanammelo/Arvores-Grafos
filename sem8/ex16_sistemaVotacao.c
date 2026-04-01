#include <stdio.h>

int pesquisaSequencial(int arr[], int tamanho, int alvo) {
    int contador = 0;

    for (int i = 0; i < tamanho; i++) {
        printf("--> Verificando posicao [%d] do array: %d == %d?\n", i, arr[i], alvo);

        if (arr[i] == alvo) {
            printf("Valor %d == %d\n\n", arr[i], alvo);
            contador++;
        } else {
            printf("Valor %d != %d\n\n", arr[i], alvo);
        }
    }

    return contador;
}

int main() {
    int dados[] = {3, 1, 4, 2, 5, 3, 2, 1, 4};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo;

    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &alvo);

    printf("\nIniciando pesquisa sequencial..\n\n");
    int resultado = pesquisaSequencial(dados, tamanho, alvo);

    printf("O valor %d apareceu %d vezes no vetor\n", alvo, resultado);

    return 0;
}
