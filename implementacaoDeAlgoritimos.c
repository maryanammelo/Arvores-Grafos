#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirArray(int arr[], int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

/* bubbleSort*/
void bubbleSort(int arr[], int n){
    printf("\n--- Bubble Sort ---\n");
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            printf("Comparando %d e %d\n",arr[j],arr[j+1]);
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                printf("Trocou -> ");
                imprimirArray(arr,n);
            }
        }
    }
}

/* selectionSort */
void selectionSort(int arr[], int n){
    printf("\n--- Selection Sort ---\n");
    for(int i=0;i<n-1;i++){
        int menor=i;
        for(int j=i+1;j<n;j++){
            printf("Comparando %d e %d\n",arr[menor],arr[j]);
            if(arr[j]<arr[menor]) menor=j;
        }
        if(menor!=i){
            int t=arr[i];
            arr[i]=arr[menor];
            arr[menor]=t;
            printf("Trocou -> ");
            imprimirArray(arr,n);
        }
    }
}

/* InsertionSort */
void insertionSort(int arr[], int n){
    printf("\n--- Insertion Sort ---\n");
    for(int i=1;i<n;i++){
        int chave=arr[i];
        int j=i-1;
        printf("Inserindo %d\n",chave);
        while(j>=0 && arr[j]>chave){
            printf("Comparando %d e %d\n",arr[j],chave);
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=chave;
        imprimirArray(arr,n);
    }
}

/*QuickSort */
int particionar(int arr[], int ini, int fim){
    int pivo=arr[fim];
    int i=ini-1;
    printf("Pivo %d\n",pivo);

    for(int j=ini;j<fim;j++){
        printf("Comparando %d e pivo %d\n",arr[j],pivo);
        if(arr[j]<pivo){
            i++;
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }

    int t=arr[i+1];
    arr[i+1]=arr[fim];
    arr[fim]=t;
    return i+1;
}

void quickSort(int arr[], int ini, int fim){
    if(ini<fim){
        int p=particionar(arr,ini,fim);
        quickSort(arr,ini,p-1);
        quickSort(arr,p+1,fim);
    }
}

/* mergeSort */
void merge(int arr[], int l, int m, int r){
    int i=l,j=m+1,k=0;
    int temp[r-l+1];

    while(i<=m && j<=r){
        printf("Comparando %d e %d\n",arr[i],arr[j]);
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=m) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];

    for(i=l,k=0;i<=r;i++,k++) arr[i]=temp[k];
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){

    int n;
    printf("Quantos numeros deseja inserir? ");
    scanf("%d",&n);

    int original[n];
    int arr[n];

    for(int i=0;i<n;i++){
        printf("Digite o numero %d: ",i+1);
        scanf("%d",&original[i]);
    }

    int opcao=-1;

    while(opcao!=0){

        printf("\n1 Bubble\n2 Selection\n3 Insertion\n4 Quick\n5 Merge\n0 Sair\nOpcao: ");
        scanf("%d",&opcao);

        for(int i=0;i<n;i++) arr[i]=original[i];

        clock_t inicio=clock();

        if(opcao==1) bubbleSort(arr,n);
        else if(opcao==2) selectionSort(arr,n);
        else if(opcao==3) insertionSort(arr,n);
        else if(opcao==4) quickSort(arr,0,n-1);
        else if(opcao==5) mergeSort(arr,0,n-1);

        clock_t fim=clock();

        if(opcao>=1 && opcao<=5){
            printf("Resultado: ");
            imprimirArray(arr,n);
            double tempo=(double)(fim-inicio)/CLOCKS_PER_SEC;
            printf("Tempo: %.6f\n",tempo);
        }
    }
    return 0;
}
