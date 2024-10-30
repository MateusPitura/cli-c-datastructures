#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define TRUE 1
#define FALSE 0

struct node
{
    int key;
    int value;
    struct node *next;
};

struct node *BUCKETS[SIZE];

int countCollisions = 0;
int countInserts = 0;

int generateHash(int key);
int regenerateHash(int position, int key);
void insert(int key, int value, int rehash);
void search(int key, int rehash);
void print(void);

int main(void)
{
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
    insert(12, 23, TRUE);
    insert(67, 89, TRUE);
    insert(45, 66, TRUE);
    insert(98, 27, TRUE);
    insert(21, 53, TRUE);
    insert(54, 81, TRUE);
    insert(16, 39, TRUE);
    insert(47, 62, TRUE);
    insert(33, 85, TRUE);
    insert(49, 73, TRUE);
    insert(64, 95, TRUE);
    insert(52, 34, TRUE);
    insert(87, 90, TRUE);
    insert(13, 67, TRUE);
    insert(58, 78, TRUE);
    insert(11, 25, TRUE);
    insert(72, 84, TRUE);
    insert(38, 41, TRUE);
    insert(93, 76, TRUE);
    insert(55, 63, TRUE);
    insert(14, 29, TRUE);
    insert(65, 88, TRUE);
    insert(40, 96, TRUE);
    insert(82, 37, TRUE);
    insert(77, 55, TRUE);
    insert(91, 19, TRUE);
    insert(24, 43, TRUE);
    insert(75, 68, TRUE);
    insert(18, 57, TRUE);
    insert(99, 21, TRUE);
    insert(59, 80, TRUE);
    insert(22, 60, TRUE);
    insert(46, 83, TRUE);
    insert(31, 69, TRUE);
    insert(94, 51, TRUE);
    insert(42, 53, TRUE);
    insert(26, 71, TRUE);
    insert(79, 44, TRUE);
    insert(17, 63, TRUE);
    insert(35, 97, TRUE);
    insert(61, 86, TRUE);
    insert(74, 49, TRUE);
    insert(53, 20, TRUE);
    insert(36, 70, TRUE);
    insert(85, 59, TRUE);
    insert(28, 64, TRUE);
    insert(48, 32, TRUE);
    insert(30, 75, TRUE);
    insert(62, 88, TRUE);
    insert(95, 47, TRUE);
    insert(27, 40, TRUE);
    insert(66, 52, TRUE);
    insert(20, 35, TRUE);
    insert(50, 82, TRUE);
    insert(39, 91, TRUE);
    insert(15, 42, TRUE);
    insert(68, 79, TRUE);
    insert(37, 61, TRUE);
    insert(44, 56, TRUE);
    insert(70, 84, TRUE);
    insert(57, 92, TRUE);
    insert(43, 26, TRUE);
    insert(90, 33, TRUE);
    insert(19, 58, TRUE);
    insert(32, 48, TRUE);
    insert(76, 50, TRUE);
    insert(89, 54, TRUE);
    insert(29, 69, TRUE);
    insert(41, 65, TRUE);
    print();
    printf("Colissions: %d, inserts: %d, avg: %.2f\n", countCollisions, countInserts, (float)countCollisions / countInserts);
    printf("\n");
    search(25, TRUE); // 0 ocorrências
    search(9, TRUE);  // 0 ocorrência
    search(20, TRUE); // 1 ocorrência
    search(29, TRUE); // 2 ocorrências
    search(75, TRUE); // 2 ocorrências
}

int generateHash(int key)
{
    return key % SIZE; // Irá gerar valores de 0 a 9
}

int regenerateHash(int position, int key)
{
    // Calculo 1: // colissions: 653, inserts: 99, avg: 6.60
    return (position + 1) % SIZE;
    // Calculo 2: colissions: 67, inserts: 91, avg: 0.74
    // int aux = 1 + generateHash(key) % (SIZE - 1);
    // return (position + aux) % SIZE;
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
            hash = regenerateHash(hash, key);
        }
        if (count < SIZE)
        {
            countCollisions += count;
            countInserts++;
            BUCKETS[hash] = newElement;
        }
        else
        {
            printf("Buckets full. Key %d, value %d not inserted\n", key, value);
        }
    }
}

void search(int key, int rehash)
{
    int hash = generateHash(key);
    struct node *aux = BUCKETS[hash];
    printf("SEARCH");
    if (aux == NULL)
    {
        printf(": key %d not found, caused by first hash igual to null\n", key);
        return;
    }
    if (rehash == FALSE)
    {
        while (aux != NULL)
        {
            printf(" -> Key: %d, value: %d", aux->key, aux->value);
            aux = aux->next;
        }
        printf("\n");
    }
    else if (rehash == TRUE)
    {
        int count = 0;
        while (aux->key != key && count < SIZE)
        {
            count++;
            hash = regenerateHash(hash, key);
            aux = BUCKETS[hash];
            if (aux == NULL)
            {
                printf(": key %d not found, caused by some hash igual to null\n", key);
                return;
            }
        }
        if (count < SIZE)
        {
            printf(": key: %d, value: %d\n", aux->key, aux->value);
        }
        else
        {
            printf(": key %d not found, caused by search in all buckets\n", key);
        }
    }
}

void print(void)
{
    struct node *aux;
    printf("\n");
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
