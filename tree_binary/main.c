#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *root = NULL;

void insert(int value);
void printEmOrdem(struct node *aux);
int isEmpty(void);
void binarySearch(int value);

int main(void)
{
    isEmpty();
    printEmOrdem(root);
    binarySearch(2);
    insert(2);
    insert(2);
    insert(6);
    insert(6);
    insert(1);
    insert(1);
    insert(4);
    insert(4);
    insert(3);
    insert(3);
    insert(8);
    insert(8);
    isEmpty();
    printEmOrdem(root);
    binarySearch(2);
    binarySearch(6);
    binarySearch(1);
    binarySearch(4);
    binarySearch(3);
    binarySearch(8);
    binarySearch(5);
}

void insert(int value)
{
    struct node *aux, *temp;
    aux = (struct node *)malloc(sizeof(struct node));
    aux->data = value;
    aux->left = NULL;
    aux->right = NULL;
    if (root == NULL)
    { // Não há nenhum nó na árvore
        root = aux;
        return;
    }
    temp = root;
    while (1)
    {
        if (aux->data == temp->data)
        {
            printf("Repeated value, %d not inserted\n", value);
            return;
        }
        if (aux->data < temp->data)
        { // Se for menor vou para esquerda
            if (temp->left == NULL)
            { // Se não há um elemento na esquerda
                temp->left = aux;
                return;
            }
            temp = temp->left;
        }
        else
        { // Se for maior vou para direita
            if (temp->right == NULL)
            { // Se não há um elemento na direita
                temp->right = aux;
                return;
            }
            temp = temp->right;
        }
    }
}

void printEmOrdem(struct node *aux)
{ // Para usar chame printEmOrdem(root)
    if (aux == root)
    {
        printf("Em ordem: ");
    }
    if (aux != NULL)
    {
        printEmOrdem(aux->left);
        printf("| %d |", aux->data);
        printEmOrdem(aux->right);
    }
    if (aux == NULL)
    {
        printf("\n");
    }
}

int isEmpty(void)
{
    if (root == NULL)
    {
        printf("Tree empty\n");
        return 1;
    }
    return 0;
}

void binarySearch(int value)
{
    struct node *temp;
    if (isEmpty() == 1)
    {
        return;
    }
    temp = root;
    while (1)
    {
        if (value == temp->data)
        {
            printf("Value %d found\n", value);
            return;
        }
        if (value < temp->data)
        { // Se for menor vou para esquerda
            if (temp->left == NULL)
            { // Se não há um elemento na esquerda
                printf("Value %d NOT found\n", value);
                return;
            }
            temp = temp->left;
        }
        else
        { // Se for maior vou para direita
            if (temp->right == NULL)
            { // Se não há um elemento na direita
                printf("Value %d NOT found\n", value);
                return;
            }
            temp = temp->right;
        }
    }
}