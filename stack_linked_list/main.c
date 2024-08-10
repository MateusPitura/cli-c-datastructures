#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 100

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *topTemp = NULL;

void push(int value);
int empty();
void pop();
int getTop();
void showStack();
char *reverse(void);

int main(void)
{
    /*
    push(3);
    push(4);
    push(2);
    push(7);
    showStack();
    pop();
    pop();
    push(7);
    showStack();
    pop();
    getTop();
    pop();
    pop();
    pop();
    getTop();
    showStack();
    return 0;
    */
    
    push('a');
    push('b');
    push('c');
    showStack();
    reverse();
    struct node *temp = topTemp;
    printf("----------\n");
    printf("REVERSE\n");
    while (temp != NULL)
    {
        printf("Stack: %d\n", temp->data);
        temp = temp->next;
    }
    printf("----------\n");    
    
}

char *reverse(void)
{
    struct node *head = top;
    while (head != NULL)
    {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = head->data;
        temp->next = topTemp;
        topTemp = temp;
        head = head->next;
    }
}

void push(int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = top;
    top = temp;
}

int empty()
{
    if (top == NULL)
    {
        printf("Stack empty. ");
        return 1;
    }
    return 0;
}

void pop()
{
    if (empty())
    {
        printf("Stack not popped\n");
        return;
    }
    printf("Popped: %d\n", top->data);
    struct node *temp;
    temp = top;
    top = top->next;
    free(temp);
}

int getTop()
{
    if (empty())
    {
        printf("Top not show\n");
        return -1;
    }
    printf("Top: %d\n", top->data);
    return top->data;
}

void showStack()
{
    if (empty())
    {
        printf("Stack not show\n");
        return;
    }
    struct node *temp = top;
    printf("----------\n");
    while (temp != NULL)
    {
        printf("Stack: %d\n", temp->data);
        temp = temp->next;
    }
    printf("----------\n");
}