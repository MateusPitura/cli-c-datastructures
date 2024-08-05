#include <stdio.h>

#define SIZE 3
int array[SIZE];
int front = 0;
int rear = -1;
int count = 0;

void enqueue(int value);
void dequeue(void);
void getFront(void);
void printQueue(void);

void main(void){
    dequeue();

    enqueue(10);
    enqueue(8);
    printQueue();

    enqueue(12);
    enqueue(14);

    printQueue();

    dequeue();
    printQueue();

    enqueue(14);
    printQueue();

    getFront();

    /*
    enqueue(16);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printQueue();
    dequeue();
    printQueue();
    enqueue(6);
    printQueue();
    getFront();
    */
}

void enqueue(int value){
    if(count == SIZE){
        printf("Queue full. Value not enqueued: %d\n", value);
        return;
    }
    count++;
    rear++;
    if(rear == SIZE){
        rear = 0;
    }
    array[rear] = value;
}

void dequeue(void){
    if(count == 0){
        printf("Queue empty\n");
        return;
    }
    count--;
    front++;
    if(front == SIZE){
        front = 0;
    }
}

void getFront(void){
    if(count == 0){
        printf("Queue empty");
        return;
    }
    printf("Front of queue: %d\n", array[front]);
}

void printQueue(void){
    if(count == 0){
        printf("Queue empty");
        return;
    }
    int i = front;
    int j;
    printf("Queue: ");
    for(j=0; j<count; j++){
        printf("%d ", array[i]);
        i++;
        if(i == SIZE){
            i=0;
        }
    }
    printf("\n");
}