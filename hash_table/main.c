#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

struct node
{
    int key;
    int value;
    struct node *next;
};

struct node *BUCKETS[SIZE];

int generateHash(int key);
int regenerateHash(int position);
void insert(int key, int value, int rehash);
void search(int key);
void print(void);

int main(void)
{
    print();
    insert(23, 45, TRUE);
    insert(78, 92, TRUE);
    insert(34, 56, TRUE);
    insert(12, 89, TRUE);
    insert(67, 49, TRUE);
    insert(91, 15, TRUE);
    insert(40, 73, TRUE);
    insert(29, 58, TRUE);
    insert(86, 33, TRUE);
    insert(50, 20, TRUE);
    insert(14, 67, TRUE);
    insert(33, 90, TRUE);
    insert(55, 21, TRUE);
    insert(3, 78, TRUE);
    /*
    insert(47, 12, TRUE);
    insert(65, 84, TRUE);
    insert(23, 99, TRUE);
    insert(7, 54, TRUE);
    insert(88, 42, TRUE);
    insert(10, 76, TRUE);
    insert(59, 32, TRUE);
    insert(26, 11, TRUE);
    insert(97, 45, TRUE);
    insert(16, 63, TRUE);
    insert(82, 9, TRUE);
    insert(44, 69, TRUE);
    insert(31, 50, TRUE);
    insert(75, 18, TRUE);
    insert(92, 37, TRUE);
    insert(6, 81, TRUE);
    */
    print();
    search(20);
    search(25);
    search(29);
}

int generateHash(int key)
{
    return key % SIZE; // Irá gerar valores de 0 a 9
}

void insert(int key, int value, int rehash)
{
    struct node *newElement = (struct node *)malloc(sizeof(struct node));
    newElement->key = key;
    newElement->value = value;
    newElement->next = NULL;
    int hash = generateHash(key);
    if (rehash == FALSE)
    {
        struct node *oldElement = BUCKETS[hash];
        newElement->next = oldElement;
        BUCKETS[hash] = newElement;
    }
    else if (rehash == TRUE)
    {
        int count = 0;
        while (BUCKETS[hash] != NULL && count < SIZE)
        {
            count++;
            hash = regenerateHash(hash);
        }
        if (count < SIZE)
        {
            BUCKETS[hash] = newElement;
        }
        else
        {
            printf("Buckets full. Key %d, value %d not inserted\n", key, value);
        }
    }
}

int regenerateHash(int position)
{
    return (position + 1) % SIZE;
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
