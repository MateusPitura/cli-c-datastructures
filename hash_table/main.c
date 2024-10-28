#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct node
{
    int key;
    int value;
    struct node *next;
};

struct node *BUCKETS[SIZE];

int generateHash(int key);
void insert(int key, int value);
void search(int key);
void print(void);

int main(void)
{
    print();
    insert(23, 45);
    insert(78, 92);
    insert(34, 56);
    insert(12, 89);
    insert(67, 49);
    insert(91, 15);
    insert(40, 73);
    insert(29, 58);
    insert(86, 33);
    insert(50, 20);
    insert(14, 67);
    insert(33, 90);
    insert(55, 21);
    insert(3, 78);
    insert(47, 12);
    insert(65, 84);
    insert(23, 99);
    insert(7, 54);
    insert(88, 42);
    insert(10, 76);
    insert(59, 32);
    insert(26, 11);
    insert(97, 45);
    insert(16, 63);
    insert(82, 9);
    insert(44, 69);
    insert(31, 50);
    insert(75, 18);
    insert(92, 37);
    insert(6, 81);
    print();
    search(20);
    search(25);
    search(29);
}

int generateHash(int key)
{
    return key % SIZE; // Irá gerar valores de 0 a 9
}

void insert(int key, int value)
{
    struct node *newElement = (struct node *)malloc(sizeof(struct node));
    newElement->key = key;
    newElement->value = value;
    newElement->next = NULL;
    int hash = generateHash(key);
    struct node *oldElement = BUCKETS[hash];
    newElement->next = oldElement;
    BUCKETS[hash] = newElement;
}

void search(int key)
{
    int hash = generateHash(key);
    struct node *aux = BUCKETS[hash];
    if (aux == NULL)
    {
        printf("Key %d not found\n", key);
        return;
    }
    printf("SEARCH BY KEY %d", key);
    while (aux != NULL)
    {
        printf(" -> Key: %d, value: %d", aux->key, aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void print(void)
{
    struct node *aux;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        aux = BUCKETS[i];
        printf("BUCKET[%d]: ", i);
        while (aux != NULL)
        {
            printf("-> %d ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }
    printf("\n");
}
