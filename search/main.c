#include <stdio.h>
#include <stdlib.h>

/*
    PARTE 1:

    Gerar um vetor de 20.000
    Fazer busca sequencial de 1.000 elementos, exibir quantidade média de comparações
    Fazer busca sequencial com sentinela de 1.000 elementos, exibir quantidade média de comparações

    PARTE 2:

    Gerar uma lista encadeada de 20.000
    Fazer busca sequencial de 1.0000 elementos, exibir quantidade média de comparações

    PARTE 3:

    Gerar uma lista encadeada de 20.000
    Fazer busca mover para frente de 1.000 elementos, exibir quantidade média de comparações
    Fazer busca transposição de 1.000 elementos, exibir quantidade média de comparações

    PARTE 4:

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
int searchSequencialLinkedList(void);
int searchMoverParaFrente(void);
int searchTransposicao(void);
int searchBinaria(void);

void quickSort(void);
void checkSort(void);

void measureSearch(int (*searchFunction)(int), char *functionName);

int main()
{
    setRandomArray();
    setRandomLinkedList();
    measureSearch(searchSequencialArray, "Busca sequencial em array não ordenado");
    measureSearch(searchSequencialSentinela, "Busca sequencial com sentinela em array não ordenado");
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
    ARRAY[LENGHT - 1] = value; // Coloco o value na última posição para ele sempre encontrar
    int i = 0;
    while (ARRAY[i] != value)
    {
        i++;
    }
    ARRAY[LENGHT-1] = aux; // Retorno para a última posição o valor salvo
    if (i == LENGHT-1)
    {
        return NOT_FOUND;
    }
    else
    {
        return i;
    }
}

int searchSequencialLinkedList(void)
{
}

int searchMoverParaFrente(void)
{
}

int searchTransposicao(void)
{
}

int searchBinaria(void)
{
}

void quickSort(void)
{
}

void checkSort(void)
{
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
