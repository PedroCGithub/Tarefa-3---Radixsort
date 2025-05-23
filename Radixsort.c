#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50
#define MAX_VALUE 10000

// Função para encontrar o maior elemento do array
int achaMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função para realizar a ordenação por contagem usando o Counting Sort npara um dígito específico
void countingSort(int arr[], int n, int exp) {
    int saida[n]; // Array de saída
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
        saida[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para arr[], agora contendo números ordenados pelo dígito atual
    for (int i = 0; i < n; i++) {
        arr[i] = saida[i];
    }
}


void radixsort(int arr[], int n) {
    // Encontra o número máximo para saber o número de dígitos
    int max = achaMax(arr, n);

    // Realiza a ordenação por contagem para cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    srand(time(NULL));

    printf("Array original randomizado:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
        printf("%d ", arr[i]);
    }

    radixsort(arr, n);

    printf("\nArray ordenado:\n");
        for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}