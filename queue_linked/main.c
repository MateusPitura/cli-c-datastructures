#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void enqueue(int value);
void dequeue(void);
void peek(void);
void showQueue(void);

void main(void)
{
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    showQueue();
    dequeue();
    showQueue();
    enqueue(6);
    showQueue();
    peek();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    peek();
    showQueue();
}

void enqueue(int value)
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
    tail->next = aux;
    tail = aux;
}
void dequeue(void)
{
    if (head == NULL)
    {
        printf("Queue empty, queue not dequeue\n");
        return;
    }
    struct node *aux;
    aux = head;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    free(aux);
}
void peek(void)
{
    if (head == NULL)
    {
        printf("Queue empty, head not show\n");
        return;
    }
    printf("Front of queue: %d\n", head->data);
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