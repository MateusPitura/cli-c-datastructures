#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

struct node *head = NULL;
struct node *tail = NULL;

void insert(int value, int side); // 0: start, 1: end
void removeByValue(int value);
void showList(void);

int main()
{
    // showList();
    // removeByValue(2);
    // insert(2, 1);
    // removeByValue(10);
    // removeByValue(2);
    // showList();
    // insert(4, 0);
    // showList();
    // insert(6, 1);
    // showList();
    // removeByValue(10);
    // removeByValue(6);
    // insert(1, 0);
    // showList();
    // insert(3, 1);
    // showList();
    // insert(5, 0);
    // showList();
    // insert(7, 1);
    // removeByValue(10);
    // showList();
    // removeByValue(7);
    // showList();
    // removeByValue(4);
    // showList();
    showList();
    insert(7, 0);
    showList();
    insert(9, 0);
    showList();
    insert(3, 1);
    showList();
    insert(8, 1);
    showList();
    removeByValue(9);
    showList();
    removeByValue(3);
    showList();
    removeByValue(8);
    showList();
}

void insert(int value, int side)
{
    struct node *aux;
    aux = (struct node *)malloc(sizeof(struct node));
    aux->data = value;
    aux->next = NULL;
    aux->previous = NULL;
    if (head == NULL)
    { // A lista está vazia
        head = aux;
        tail = aux;
        return;
    }
    if (side == 0)
    { // Start
        aux->next = head;
        head->previous = aux;
        head = aux;
        return;
    }
    else if(side == 1)// End
    {
        tail->next = aux;
        aux->previous = tail;
        tail = aux;
        return;
    }
    printf("Invalid side");
}

void removeByValue(int value)
{
    if (head == NULL)
    {
        printf("List empty, value %d not removed\n", value);
        return;
    }
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            if (current->previous == NULL)
            { // É o primero
                head = current->next;
                if(head != NULL){ // Não era o único
                    head->previous = NULL;
                } else { // Era o único
                    tail = NULL;
                }
            } else { // Não é o primeiro
                current->previous->next = current->next;
                if(current->next != NULL){ // Não era o último
                    current->next->previous = current->previous;
                } else { // Era o último
                    tail = current->previous;
                }
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Value %d not found, not removed\n", value);
}

void showList(void)
{
    if (head == NULL)
    {
        printf("List empty, list not show\n");
        return;
    }
    struct node *temp = head;
    printf("\n");
    printf("List:");
    while (temp != NULL)
    {
        printf(" %d |", temp->data);
        temp = temp->next;
    }
    printf("\n------------------------------\n");
}
