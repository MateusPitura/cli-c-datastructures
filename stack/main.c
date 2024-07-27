#include <stdio.h>

#define SIZE 3
int stack[SIZE];
int top = -1;

void push(int value);
int empty();
void pop();
int getTop();
void showStack();

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
    getTop();
    showStack();
    */
    #define MAX_INPUT 100
    char input[MAX_INPUT] = "{ a * ( b - c }"; //Incorrect
    //char input[MAX_INPUT] = "x + ( y - b ) * c - [ ( d + e )"; //Incorrect
    //char input[MAX_INPUT] = "x + ( y - b ) * c - [ ( d + e ) ]"; //Correct
    //char input[MAX_INPUT] = "{ x + ( y - b ) * c - [ ( d + e ) ] }"; //Correct
    int i;
    for (i = 0; i < MAX_INPUT; i++)
    {
        char currentChar = input[i];
        if (currentChar == 123 || currentChar == 40 || currentChar == 91) // {: 123 (: 40 [:91
        {
            push(currentChar);
        }
        else if (currentChar == 125 || currentChar == 41 || currentChar == 93)
        {
            char topChar = getTop();
            if (topChar == 123 && currentChar == 125) // }: 125
            {
                pop();
            }
            else if (topChar == 40 && currentChar == 41) // ): 41
            {
                pop();
            }
            else if (topChar == 91 && currentChar == 93) // ]:92
            {
                pop();
            }
            else
            {
                printf("Incorrect expression\n");
                return -1;
            }
        }
    }
    if(empty())
    {
        printf("Correct expression\n");   
        return 0;
    }
    printf("Incorrect expression\n");
    return -1;
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

int getTop()
{
    if (empty())
    {
        printf("Top not show\n");
        return -1;
    }
    printf("Top: %d\n", stack[top]);
    return stack[top];
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