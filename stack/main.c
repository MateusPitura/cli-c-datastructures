#include <stdio.h>

#define SIZE 3
int stack[SIZE];
int top = -1;

void push(int value);
int empty();
void pop();
void getTop();
void showStack();

int main(void)
{
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
    getTop();
    showStack();
    return 0;
}

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("Stack full. Value not pushed: %d\n", value);
        return;
    }
    top++;
    stack[top] = value;
}

int empty()
{
    if (top == -1)
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
    printf("Popped: %d\n", stack[top]);
    top--;
}

void getTop()
{
    if (empty())
    {
        printf("Top not show\n");
        return;
    }
    printf("Top: %d\n", stack[top]);
}

void showStack()
{
    if (empty())
    {
        printf("Stack not show\n");
        return;
    }
    int i;
    printf("----------\n");
    for (i = top; i >= 0; i--)
    {
        printf("Stack[%d]: %d\n", i, stack[i]);
    }
    printf("----------\n");
}