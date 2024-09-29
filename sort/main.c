#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LENGHT 19999

int ARRAY[LENGHT];

void setRandomArray(void);
int checkSort(void);
void swap(int a, int b);
void measureTime(void (*sortFunction)(void), char *functionName);
void showArray(void);
void bubbleSortBeta(void);
void bubbleSortAlpha(void);
void bubbleSortSigma(void);
void insertionSort(void);
void selectionSort(void);
void mergeSort(int start, int end);
void mergeSortExchange(int start, int end, int middle);
void handleMergeSort(void);
void quickSort(int p, int r);
int quickSortPartition(int p, int r);
void handleQuickSort(void);

int main(void)
{
    printf("Length: %d\n\n", LENGHT);
    measureTime(bubbleSortBeta, "bubbleSortBeta");
    measureTime(bubbleSortAlpha, "bubbleSortAlpha");
    measureTime(bubbleSortSigma, "bubbleSortSigma");
    measureTime(insertionSort, "insertionSort");
    measureTime(selectionSort, "selectionSort");
    measureTime(handleQuickSort, "quickSort");
    measureTime(handleMergeSort, "mergeSort");
}

void bubbleSortBeta(void)
{
    int i, j;
    for (i = 1; i <= LENGHT; i++)
    { // Professor: i<=LENGHT+1
        for (j = 0; j <= LENGHT - 1; j++)
        { // Professor: j<=LENGHT
            if (ARRAY[j] > ARRAY[j + 1])
            {
                swap(j, j + 1);
            }
        }
    }
}

void bubbleSortAlpha(void)
{
    int i, j;
    for (i = 1; i <= LENGHT - 1; i++)
    {
        for (j = LENGHT - 1; j >= i; j--)
        {
            if (ARRAY[j] < ARRAY[j - 1])
            { // Professor: ARRAY[j]>ARRAY[j-1]
                swap(j, j - 1);
            }
        }
    }
}

void bubbleSortSigma(void)
{
    int i, j, change = 1;
    for (i = 1; i <= LENGHT && change == 1; i++)
    {
        change = 0;
        for (j = 0; j <= LENGHT - i - 1; j++)
        {
            if (ARRAY[j] > ARRAY[j + 1])
            {
                swap(j, j + 1);
                change = 1;
            }
        }
    }
}

void insertionSort(void)
{
    int i, j, pivot, change;
    for (i = 1; i <= LENGHT - 1; i++)
    {
        pivot = ARRAY[i];
        j = i - 1;
        change = 0;
        while (change == 0 && j >= 0)
        {
            if (ARRAY[j] > pivot)
            {
                swap(j, j + 1);
                j--;
            }
            else
            {
                change = 1;
            }
        }
    }
}

void selectionSort(void)
{
    int i, j, pivot;
    for (i = 0; i <= LENGHT - 1; i++)
    {
        pivot = i;
        for (j = i + 1; j < LENGHT; j++)
        {
            if (ARRAY[pivot] > ARRAY[j])
            {
                pivot = j;
            }
        }
        swap(pivot, i);
    }
}

void mergeSort(int start, int end)
{ // A primeira chamada será 0 e LENGTH-1;
    if (start < end)
    {
        int middle = (start + end) / 2;
        mergeSort(start, middle);
        mergeSort(middle + 1, end);
        mergeSortExchange(start, end, middle);
    }
}

void mergeSortExchange(int start, int end, int middle)
{
    int aux[LENGHT];
    int arrayStart1 = start;
    int arrayStart2 = middle + 1;
    int freePosition = start;
    while (arrayStart1 <= middle && arrayStart2 <= end)
    {
        if (ARRAY[arrayStart1] <= ARRAY[arrayStart2])
        {
            aux[freePosition] = ARRAY[arrayStart1];
            arrayStart1++;
        }
        else
        {
            aux[freePosition] = ARRAY[arrayStart2];
            arrayStart2++;
        }
        freePosition++;
    }
    int i;
    for (i = arrayStart1; i <= middle; i++)
    {
        aux[freePosition] = ARRAY[i];
        freePosition++;
    }
    for (i = arrayStart2; i <= end; i++)
    {
        aux[freePosition] = ARRAY[i];
        freePosition++;
    }
    for (i = start; i <= end; i++)
    {
        ARRAY[i] = aux[i];
    }
}

void handleMergeSort(void)
{
    mergeSort(0, LENGHT - 1);
}

void quickSort(int head, int tail)
{ // A primeira chamada será 0 e LENGTH-1
    if (head < tail)
    {
        int pivot = quickSortPartition(head, tail);
        quickSort(head, pivot);     // Low side: todos os elementos são penores que o pivot
        quickSort(pivot + 1, tail); // High side
    }
}

int quickSortPartition(int head, int tail)
{
    int i = head - 1;
    int j = tail + 1;
    int pivot = ARRAY[(head + tail) / 2]; // O pivot será o meio do array
    while (i < j)
    {
        do
        {
            j--;
        } while (ARRAY[j] > pivot);
        do
        {
            i++;
        } while (ARRAY[i] < pivot);
        if (i < j)
        {
            swap(i, j);
        }
    }
    return j;
}

void handleQuickSort(void)
{
    quickSort(0, LENGHT - 1);
}

void setRandomArray(void)
{
    srand(10); // Define a seed dos números aleatórios, fixa para melhor comparação
    int i;
    for (i = 0; i < LENGHT; i++)
    {
        ARRAY[i] = rand() % (LENGHT * 10); // Gera números de 0 a 199.989
    }
}

int checkSort(void)
{
    int i, count = 0;
    for (i = 0; i < LENGHT - 1; i++)
    {
        // printf("%d |", ARRAY[i]);
        if (ARRAY[i] > ARRAY[i + 1])
        { // Confere se o primeiro valor é maior que o segundo e assim por diante
            count++;
        }
    }
    if (count == 0)
    {
        return 1; // Sucesso
    }
    printf("Unsorted\n");
    return 0; // Falha
}

void swap(int a, int b)
{
    int aux = ARRAY[a];
    ARRAY[a] = ARRAY[b];
    ARRAY[b] = aux;
}

void measureTime(void (*sortFunction)(void), char *functionName)
{
    setRandomArray();
    long timeCurrent = clock();             // Pega o tempo passado desde o ínicio do programa
    sortFunction();                         // Executa a função recebida como parâmetro
    long timeSpent = clock() - timeCurrent; // Calcula o tempo usado para ordenar
    if (!checkSort())
    {
        return;
    }
    printf("Time spent by %s (unsorted): %f seconds\n", functionName, (float)timeSpent / CLOCKS_PER_SEC);
    // Calcula novamente o tempo gasto porém com o array ordenado
    timeCurrent = clock();
    sortFunction();
    timeSpent = clock() - timeCurrent;
    if (!checkSort())
    {
        return;
    }
    printf("Time spent by %s (already sorted): %f seconds\n\n", functionName, (float)timeSpent / CLOCKS_PER_SEC);
}

void showArray(void)
{
    int i;
    for (i = 0; i < LENGHT; i++)
    {
        printf("%d |", ARRAY[i]);
    }
    printf("\n");
}