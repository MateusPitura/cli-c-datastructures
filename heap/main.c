#include <stdio.h>

#define LENGTH 11
int SIZE = 9;
int ARRAY[LENGTH] = {0, 4, 1, 3, 2, 9, 10, 14, 8}; // O array precisa começar no 1, então a 1ª posição fica vazia

void maxHeapify(int i); // Organiza o heap
void buildMaxHeap();
void maxHeap();
int removeHeap();
void swap(int a, int b);
void showHeap();
void increaseKey(int value, int i);
void insert(int value);

int main()
{
    showHeap();
    buildMaxHeap();
    showHeap();
    insert(16);
    maxHeap();
    showHeap();
    insert(7);
    showHeap();
    printf("1 bigger value: %d\n", removeHeap());
    printf("2 bigger value: %d\n", removeHeap());
    printf("3 bigger value: %d\n", removeHeap());
}

void maxHeapify(int i)
{

    int left = i * 2;
    int right = i * 2 + 1;
    int largest;
    if (left <= SIZE && ARRAY[left] > ARRAY[i])
    { // Verifica se o elemento a esquerda é maior que o pai
        largest = left;
    }
    else
    {
        largest = i;
    }
    if (right <= SIZE && ARRAY[right] > ARRAY[largest])
    { // Verifica se o elemento a direita é maior que o a esquerda ou ao pai
        largest = right;
    }
    if (largest != i)
    {
        swap(i, largest);
        maxHeapify(largest);
    }
}

void buildMaxHeap()
{
    int i;
    for (i = SIZE / 2; i > 0; i--)
    {
        maxHeapify(i);
    }
}

void insert(int value)
{
    ARRAY[SIZE] = -2147483647; // Insere um valor muito baixo
    increaseKey(value, SIZE);
    SIZE++;
}

void maxHeap()
{
    printf("Max value of Heap: %d\n", ARRAY[1]);
}

int removeHeap()
{
    int max = ARRAY[1];
    ARRAY[1] = ARRAY[SIZE];
    SIZE--;
    maxHeapify(1);
    return max;
}

void swap(int a, int b)
{
    int aux = ARRAY[a];
    ARRAY[a] = ARRAY[b];
    ARRAY[b] = aux;
}

void showHeap()
{
    int i;
    for (i = 1; i < LENGTH; i++)
    {
        printf("i[%d]: %d, ", i, ARRAY[i]);
    }
    printf("\n");
}

void increaseKey(int value, int i)
{
    if (value < ARRAY[i])
    {
        return;
    }
    ARRAY[i] = value;
    while (i > 1 && ARRAY[i / 2] < ARRAY[i])
    { // O filho é menor que o pai
        swap(i / 2, i);
        i = i / 2;
    }
}