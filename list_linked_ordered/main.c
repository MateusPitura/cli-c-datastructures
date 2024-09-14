#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int value);
void getIndexByValue(int value);
void removeByIndex(int index);
void removeByValue(int value);
void showList(void);

void main(void)
{
    showList();
    getIndexByValue(2);
    removeByIndex(0);
    removeByValue(2);
    insert(2);
    showList();
    insert(4);
    showList();
    insert(7);
    showList();
    insert(1);
    insert(3);
    insert(8);
    showList();
    getIndexByValue(1);
    getIndexByValue(4);
    getIndexByValue(8);
    removeByIndex(0);
    removeByIndex(-1);
    removeByIndex(3);
    removeByIndex(4);
    removeByIndex(2);
    removeByValue(2);
    removeByValue(7);
    removeByValue(8);
    removeByValue(10);
    showList();
}

void insert(int value)
{
    struct node *aux;
    aux = (struct node *)malloc(sizeof(struct node));
    aux->data = value;
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL && current->data < value)
    {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) // Vazia ou com apenas 1 elemento
    {
        aux->next = head;
        head = aux;
        return;
    }
    aux->next = current;
    previous->next = aux;
}

void getIndexByValue(int value)
{
    if (head == NULL)
    {
        printf("List empty, index not get\n");
        return;
    }
    struct node *current = head;
    struct node *previous = NULL;
    int index = 0;
    while (current != NULL && current->data <= value)
    {
        if (current->data == value)
        {
            printf("Index of %d is: %d\n", value, index);
            return;
        }
        index++;
        previous = current;
        current = current->next;
    }
    printf("Value %d not found, index not get\n", value);
}

void removeByIndex(int index)
{
    if (head == NULL)
    {
        printf("List empty, index not removed\n");
        return;
    }
    struct node *current = head;
    struct node *previous = NULL;
    int i;
    for (i = 0; i <= index && current != NULL; i++)
    {
        if (i == index) // Se o elemento atual está na posição informada
        {
            if (current == head) // O elemento atual é o primeiro da lista
            {
                head = head->next; // Altera o início da fila
            }
            else
            {
                previous->next = current->next; // Remoção
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Invalid index, index not removed\n");
}

void removeByValue(int value)
{
    if (head == NULL)
    {
        printf("List empty, value not removed\n");
        return;
    }
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL && current->data <= value)
    {
        if (current->data == value) // O valor atual é o procurado
        {
            if (current == head) // Se o valor atual for o primeiro da lista
            {
                head = head->next; // Altera o início da lista
            }
            else
            {
                previous->next = current->next; // Remoção
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Value %d not found, value not removed\n", value);
}

void showList(void)
{
    if (head == NULL)
    {
        printf("List empty, list not show\n");
        return;
    }
    struct node *temp = head;
    printf("----------\n");
    while (temp != NULL)
    {
        printf("List: %d\n", temp->data);
        temp = temp->next;
    }
    printf("----------\n");
}
