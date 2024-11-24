#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
    int height;
};

struct node *root = NULL;

void insert(int value);
void binarySearch(int value);
int isEmpty(void);
void printEmOrdem();
void printPreOrdem();
void printPosOrdem();
void rightRotation(struct node *x);
void leftRotation(struct node *x);

int main(void)
{
    isEmpty();
    printEmOrdem(root);
    binarySearch(2);
    insert(300);
    insert(200);
    insert(100);
    insert(150);
    insert(120);
    insert(400);
    insert(500);
    insert(130);
    insert(170);
    insert(50);
    insert(190);
    isEmpty();
    printEmOrdem(root);
    printPreOrdem(root);
    printPosOrdem(root);
    printf("\n");
    binarySearch(300);
    binarySearch(200);
    binarySearch(100);
    binarySearch(150);
    binarySearch(120);
    binarySearch(400);
    binarySearch(500);
    binarySearch(130);
    binarySearch(170);
    binarySearch(50);
    binarySearch(190);
    binarySearch(2);
}

void rightRotation(struct node *x)
{
    struct node *y = x->left;
    struct node *z = y->right;
    y->right = x;
    x->left = z;
}

void leftRotation(struct node *x)
{
    struct node *y = x->right;
    struct node *z = y->left;
    y->left = x;
    x->right = z;
}

void insert(int value)
{
    struct node *pp = NULL;
    struct node *p = root;
    struct node *payoung = NULL;
    struct node *ayoung = root;
    struct node *q;
    struct node *son;
    int imbal;
    if (p == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = value;
        return;
    }
    while (p != NULL)
    {
        if (value < p->data)
        {
            q = p->left;
        }
        else
        {
            q = p->right;
        }
        if (q != NULL)
        {
            if (q->height != 0)
            {
                payoung = p;
                ayoung = q;
            }
        }
        pp = p;
        p = q;
    }
    q = (struct node *)malloc(sizeof(struct node));
    q->data = value;
    if (value < pp->data)
    {
        pp->left = q;
    }
    else
    {
        pp->right = q;
    }
    if (value < ayoung->data)
    {
        son = ayoung->left;
    }
    else
    {
        son = ayoung->right;
    }
    p = son;
    while (p != q)
    {
        if (value < p->data)
        {
            p->height = 1;
            p = p->left;
        }
        else
        {
            p->height = -1;
            p = p->right;
        }
    }
    if (value < ayoung->data)
    {
        imbal = 1;
    }
    else
    {
        imbal = -1;
    }
    if (ayoung->height == 0)
    {
        ayoung->height = imbal;
        return;
    }
    if (ayoung->height != imbal)
    {
        ayoung->height = 0;
        return;
    }
    if (son->height == imbal)
    {
        p = son;
        if (imbal == 1)
        {
            rightRotation(ayoung);
        }
        else
        {
            leftRotation(ayoung);
        }
        ayoung->height = 0;
        son->height = 0;
    }
    else
    {
        if (imbal == 1)
        {
            p = son->right;
            leftRotation(son);
            ayoung->left = p;
            rightRotation(ayoung);
        }
        else
        {
            p = son->left;
            rightRotation(son);
            ayoung->right = p;
            leftRotation(ayoung);
        }
        if (p->height == 0)
        {
            ayoung->height = 0;
            son->height = 0;
        }
        else
        {
            if (p->height == imbal)
            {
                ayoung->height = -imbal;
                son->height = 0;
            }
            else
            {
                ayoung->height = 0;
                son->height = imbal;
            }
        }
        p->height = 0;
    }
    if (payoung == NULL)
    {
        root = p;
    }
    else
    {
        if (ayoung == payoung->right)
        {
            payoung->right = p;
        }
        else
        {
            payoung->left = p;
        }
    }
    return;
}

void printEmOrdem(struct node *aux)
{ // Para usar chame printEmOrdem(root)
    if (aux == root)
    {
        printf("\nEm ordem: ");
    }
    if (aux != NULL)
    {
        printEmOrdem(aux->left);
        printf("%d | ", aux->data);
        printEmOrdem(aux->right);
    }
}

void printPreOrdem(struct node *aux)
{ // Para usar chame printPreOrdem(root)
    if (aux == root)
    {
        printf("\nPré ordem: ");
    }
    if (aux != NULL)
    {
        printf("%d | ", aux->data);
        printPreOrdem(aux->left);
        printPreOrdem(aux->right);
    }
}

void printPosOrdem(struct node *aux)
{ // Para usar chame printPosOrdem(root)
    if (aux == root)
    {
        printf("\nPós ordem: ");
    }
    if (aux != NULL)
    {
        printPosOrdem(aux->left);
        printPosOrdem(aux->right);
        printf("%d | ", aux->data);
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