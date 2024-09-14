#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void enqueue(int value, int side);
void dequeue(int side);
void peek(int side);
void showQueue(void);

void main(void)
{
    
    dequeue(0);
    enqueue(1, 0);
    enqueue(2, 0);
    enqueue(3, 0);
    enqueue(4, 0);
    enqueue(5, 0);
    showQueue();
    dequeue(0);
    showQueue();
    enqueue(6, 0);
    showQueue();
    peek(0);
    dequeue(0);
    dequeue(0);
    dequeue(0);
    dequeue(0);
    dequeue(0);
    dequeue(0);
    peek(0);
    showQueue();
    
    /*
    dequeue(1);
    enqueue(1, 1);
    enqueue(2, 1);
    enqueue(3, 1);
    enqueue(4, 1);
    enqueue(5, 1);
    showQueue();
    dequeue(1);
    showQueue();
    enqueue(6, 1);
    showQueue();
    peek(1);
    dequeue(1);
    dequeue(1);
    dequeue(1);
    dequeue(1);
    dequeue(1);
    dequeue(1);
    peek(1);
    showQueue();
    */
}

void enqueue(int value, int side)
{
    struct node *aux;
    aux = (struct node *)malloc(sizeof(struct node));
    aux->data = value;
    aux->next = NULL;
    if (head == NULL)
    {
        head = aux;
        tail = aux;
        return;
    }
    if (side == 1)
    {
        aux->next = head;
        head = aux;
    }
    else
    {
        tail->next = aux;
        tail = aux;
    }
}

void dequeue(int side)
{
    if (head == NULL)
    {
        printf("Queue empty, queue not dequeue\n");
        return;
    }
    struct node *aux;
    if (side == 1 && head->next != NULL)
    {
        struct node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        aux = tail;
        tail = temp;
    }
    else
    {
        aux = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
    }
    free(aux);
}

void peek(int side)
{
    if (head == NULL)
    {
        printf("Queue empty, not peek\n");
        return;
    }
    if (side == 1)
    {
        printf("Rear of queue: %d\n", tail->data);
    }
    else
    {
        printf("Front of queue: %d\n", head->data);
    }
}

void showQueue(void)
{
    if (head == NULL)
    {
        printf("Queue empty, queue not show\n");
        return;
    }
    struct node *temp = head;
    printf("----------\n");
    while (temp != NULL)
    {
        printf("Queue: %d\n", temp->data);
        temp = temp->next;
    }
    printf("----------\n");
}