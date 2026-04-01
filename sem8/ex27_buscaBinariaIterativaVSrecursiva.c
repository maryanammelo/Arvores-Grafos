#include <stdio.h>
//A iterativa é atraves do uso do while, que usa menos memoria, pois nao fica chamando a funçao varias vezes. Ja a recursiva utiliza mais
// memoria visto que cada chamada da funçao fica guardada na pilha de execuçao.
int buscaBinariaIterativa(int arr[], int tamanho, int alvo) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (arr[meio] == alvo) {
            return meio;
        }
        if (arr[meio] < alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}
int buscaBinariaRecursiva(int arr[], int esquerda, int direita, int alvo) {
    if (esquerda > direita) {
        return -1;
    }
    int meio = (esquerda + direita) / 2;

    if (arr[meio] == alvo) {
        return meio;
    }

    if (arr[meio] < alvo) {
        return buscaBinariaRecursiva(arr, meio + 1, direita, alvo);
    } else {
        return buscaBinariaRecursiva(arr, esquerda, meio - 1, alvo);
    }
}

int main() {
    int dados[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int alvo = 10;

    int resultadoIterativo = buscaBinariaIterativa(dados, tamanho, alvo);
    int resultadoRecursivo = buscaBinariaRecursiva(dados, 0, tamanho - 1, alvo);

    if (resultadoIterativo != -1) {
        printf("Busca binaria iterativa: valor encontrado na posicao %d\n", resultadoIterativo);
    } else {
        printf("Busca binaria iterativa: valor nao encontrado\n");
    }
    if (resultadoRecursivo != -1) {
        printf("Busca binaria recursiva: valor encontrado na posicao %d\n", resultadoRecursivo);
    } else {
        printf("Busca binaria recursiva: valor nao encontrado\n");
    }
    return 0;
}
