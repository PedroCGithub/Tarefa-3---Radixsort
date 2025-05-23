#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o maior elemento do array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função para realizar a ordenação por contagem (Counting Sort) para um dígito específico
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Array de saída
    int count[10] = {0}; // Inicializa o array de contagem

    // Armazena a contagem de ocorrências em count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Muda count[i] para que contenha a posição atual do dígito no output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para arr[], agora contendo números ordenados pelo dígito atual
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função principal que implementa o Radix Sort
void radixsort(int arr[], int n) {
    // Encontra o número máximo para saber o número de dígitos
    int max = getMax(arr, n);

    // Realiza a ordenação por contagem para cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Função para imprimir um array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Programa principal para testar as funções
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    radixsort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}