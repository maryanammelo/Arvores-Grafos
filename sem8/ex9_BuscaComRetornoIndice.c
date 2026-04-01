#include <stdio.h>

int pesquisaSequencial(int arr[], int tamanho, int alvo){
  for (int i = 0; i < tamanho; i ++){
    printf("Verificando posicao [%d] do array: %d == %d? \n", i, arr[i], alvo);
    if(arr[i] != alvo){
      printf("Valor %d != %d \n\n", arr[i], alvo);
    }
    if(arr[i] == alvo){
      printf("Valor %d == %d \n", arr[i], alvo);
        printf("\n Valor encontrado na posicao %d \n", i);
      return i;
    }
  }
  printf("\n Valor nao encontraado no vetor\n");
  return -1;
}
int main() {
  int dados[] = {5, 10, 15, 20, 25, 30};
  int tamanho = sizeof(dados) / sizeof(dados[0]);
  int alvo = 20;

  printf("\n Iniciando pesquisa sequencial...\n\n");
  int resultado = pesquisaSequencial(dados, tamanho, alvo);
  
  return 0;
}
