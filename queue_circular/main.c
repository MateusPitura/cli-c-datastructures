#include <stdio.h>

#define SIZE 3
int array[SIZE];
int head = 0;
int tail = -1;
int count = 0;

void enqueue(int value);
void dequeue(void);
void peek(void);
void showQueue(void);

void main(void){
    dequeue();

    enqueue(10);
    enqueue(8);
    showQueue();

    enqueue(12);
    enqueue(14);

    showQueue();

    dequeue();
    showQueue();

    enqueue(14);
    showQueue();

    peek();

    enqueue(16);
    /*
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    showQueue();
    dequeue();
    showQueue();
    enqueue(6);
    showQueue();
    peek();
    */
}

void enqueue(int value){
    if(count == SIZE){
        printf("Queue full. Value not enqueued: %d\n", value);
        return;
    }
    count++;
    tail++;
    if(tail == SIZE){
        tail = 0;
    }
    array[tail] = value;
}

void dequeue(void){
    if(count == 0){
        printf("Queue empty\n");
        return;
    }
    count--;
    head++;
    if(head == SIZE){
        head = 0;
    }
}

void peek(void){
    if(count == 0){
        printf("Queue empty");
        return;
    }
    printf("Front of queue: %d\n", array[head]);
}

void showQueue(void){
    if(count == 0){
        printf("Queue empty");
        return;
    }
    int i = head;
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