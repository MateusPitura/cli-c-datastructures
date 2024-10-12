#include <stdio.h>
#include <stdlib.h>

/*
    PARTE 1: OK

    Gerar um vetor de 20.000
    Fazer busca sequencial de 1.000 elementos, exibir quantidade média de comparações
    Fazer busca sequencial com sentinela de 1.000 elementos, exibir quantidade média de comparações

    PARTE 2: OK

    Gerar uma lista encadeada de 20.000
    Fazer busca sequencial de 1.0000 elementos, exibir quantidade média de comparações

    PARTE 3:

    Gerar uma lista encadeada de 20.000
    Fazer busca mover para frente de 1.000 elementos, exibir quantidade média de comparações
    Fazer busca transposição de 1.000 elementos, exibir quantidade média de comparações

    PARTE 4: OK

    Gerar um vetor de 20.000
    Ordenar e conferir
    Fazer busca binária de 1.000 elementos, exibir quantidade média de comparações
*/

#define LENGHT 20000
#define SEARCH_AMOUNT 1000
#define NOT_FOUND -1

int ARRAY[LENGHT];

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void setRandomArray(void);
void setRandomLinkedList(void);
void insertLinkedList(int value);
void printArray(void);
void printLinkedList(void);

int searchSequencialArray(int value);
int searchSequencialSentinela(int value); // Evita de se fazer 2 comparações por loop (uma é do ARRAY[i] == value e outra do i < LENGHT)
int searchSequencialLinkedList(int value);
int searchMoverParaFrente(void);
int searchTransposicao(void);
int searchBinaria(int value);

void quickSort(int p, int r);
int quickSortPartition(int p, int r);
void swap(int a, int b);
int checkSort(void);

void measureSearch(int (*searchFunction)(int), char *functionName);

void main(void)
{
    setRandomArray();
    setRandomLinkedList();
    measureSearch(searchSequencialArray, "Busca sequencial em array não ordenado");
    measureSearch(searchSequencialSentinela, "Busca sequencial com sentinela em array não ordenado");
    measureSearch(searchSequencialLinkedList, "Busca sequencial em lista ligada não ordenada");
    quickSort(0, LENGHT - 1);
    if (checkSort() == 0)
    {
        return;
    }
    measureSearch(searchBinaria, "Busca binaria em array ordenado");
}

int searchSequencialArray(int value)
{
    int i;
    for (i = 0; i < LENGHT; i++)
    {
        if (ARRAY[i] == value)
        {
            return i;
        }
    }
    return NOT_FOUND;
}

int searchSequencialSentinela(int value)
{
    int aux = ARRAY[LENGHT - 1]; // Salvo temporariamente o aux
    ARRAY[LENGHT - 1] = value;   // Coloco o value na última posição para ele sempre encontrar
    int i = 0;
    while (ARRAY[i] != value)
    {
        i++;
    }
    ARRAY[LENGHT - 1] = aux; // Retorno para a última posição o valor salvo
    if (i == LENGHT - 1)
    {
        return NOT_FOUND;
    }
    else
    {
        return i;
    }
}

int searchSequencialLinkedList(int value)
{
    if (head == NULL)
    {
        printf("Stack empty\n");
        return NOT_FOUND;
    }
    struct node *aux = head;
    int count = 0;
    while (aux != NULL)
    {
        if (aux->data == value)
        {
            return count;
        }
        count++;
        aux = aux->next;
    }
    return NOT_FOUND;
}

int searchMoverParaFrente(void)
{
}

int searchTransposicao(void)
{
}

int searchBinaria(int value)
{
    int count = 0;
    int start = 0;
    int end = LENGHT - 1;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (ARRAY[middle] == value)
        {
            return count;
        }
        if (ARRAY[middle] < value)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
        count++;
    }
    return NOT_FOUND;
}

void quickSort(int head, int tail)
{
    if (head < tail)
    {
        int pivot = quickSortPartition(head, tail);
        quickSort(head, pivot);
        quickSort(pivot + 1, tail);
    }
}

int quickSortPartition(int head, int tail)
{
    int i = head - 1;
    int j = tail + 1;
    int pivot = ARRAY[(head + tail) / 2];
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

void swap(int a, int b)
{
    int aux = ARRAY[a];
    ARRAY[a] = ARRAY[b];
    ARRAY[b] = aux;
}

int checkSort(void)
{
    int i, count = 0;
    for (i = 0; i < LENGHT - 1; i++)
    {
        if (ARRAY[i] > ARRAY[i + 1])
        {
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

void measureSearch(int (*searchFunction)(int), char *message)
{
    srand(20);
    int i, aux, fails = 0, count = 0;
    for (i = 0; i < SEARCH_AMOUNT; i++)
    {
        int aux = searchFunction(rand() % LENGHT); // Gera números de 0 a 19.999
        if (aux == NOT_FOUND)
        {
            fails++;
            count += LENGHT;
            continue;
        }
        count += aux;
    }
    printf("%s: %d | Fails: %d\n", message, count / SEARCH_AMOUNT, fails);
}

void setRandomArray(void)
{
    srand(10);
    int i;
    for (i = LENGHT - 1; i >= 0; i--)
    {
        ARRAY[i] = rand() % LENGHT;
    }
}

void printArray(void)
{
    int i = 0;
    for (i = 0; i < LENGHT; i++)
    {
        printf("%d | ", ARRAY[i]);
    }
    printf("\n");
}

void insertLinkedList(int value)
{
    struct node *aux = (struct node *)malloc(sizeof(struct node));
    aux->data = value;
    aux->next = head;
    head = aux;
}

void setRandomLinkedList(void)
{
    srand(10);
    int i;
    for (i = 0; i < LENGHT; i++)
    {
        insertLinkedList(rand() % LENGHT);
    }
}

void printLinkedList(void)
{
    if (head == NULL)
    {
        printf("Stack empty\n");
        return;
    }
    struct node *aux = head;
    while (aux != NULL)
    {
        printf("%d |", aux->data);
        aux = aux->next;
    }
}
