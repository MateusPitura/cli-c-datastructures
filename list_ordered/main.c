#include <stdio.h>

#define SIZE 5
int array[SIZE];
int count = 0;

void insert(int value);
void getByIndex(int index);
void removeByIndex(int index);
void removeByValue(int value);
void showList(void);

int main(void)
{
    showList();
    insert(2);
    showList();
    insert(4);
    showList();
    insert(7);
    showList();
    insert(3);
    insert(8);
    showList();
    getByIndex(4);
    // removeByIndex(0);
    // removeByIndex(-1);
    // removeByIndex(3);
    // removeByIndex(4);
    // removeByIndex(2);
    // removeByValue(2);
    // removeByValue(7);
    // removeByValue(8);
    removeByValue(10);
    showList();
}

void insert(int value)
{
    if (count == SIZE)
    {
        printf("List full. Value not inserted: %d\n", value);
        return;
    }
    int i;
    for (i = 0; i < count; i++)
    {
        if (value < array[i])
        { // Quando true, i conterá a posição que value deve ocupar
            int j;
            for (j = count; j > i; j--)
            { // Movimenta todos os valores para direita
                array[j] = array[j - 1];
            }
            break;
        }
    }
    count++;
    array[i] = value;
}

void getByIndex(int index)
{
    if (index >= count || index < 0)
    { // Essa condição já valida se for vazia
        printf("Invalid index\n");
        return;
    }
    printf("%d\n", array[index]);
}

void removeByIndex(int index)
{
    if (index >= count || index < 0)
    {
        printf("Invalid index\n");
        return;
    }
    int i;
    for (i = index; i < count; i++)
    { // Movimenta todos os valores para esquerda
        array[i] = array[i + 1];
    }
    count--;
}

void removeByValue(int value)
{
    if (count == 0)
    {
        printf("List empty\n");
        return;
    }
    int i;
    for (i = 0; i < count; i++)
    {
        if (value == array[i])
        {
            removeByIndex(i);
            return;
        }
    }
    printf("Input %d not removed. Value not found\n", value);
}

void showList(void)
{
    if (count == 0)
    {
        printf("List empty\n");
        return;
    }
    int i;
    printf("List: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
