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
void bubbleSortBeta(void);
void bubbleSortAlpha(void);
void bubbleSortSigma(void);
void insertionSort(void);
void selectionSort(void);

int main(void)
{
    printf("Length: %d\n\n", LENGHT);
    measureTime(bubbleSortBeta, "bubbleSortBeta");
    measureTime(bubbleSortAlpha, "bubbleSortAlpha");
    measureTime(bubbleSortSigma, "bubbleSortSigma");
    measureTime(insertionSort, "insertionSort");
    measureTime(selectionSort, "selectionSort");
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