#include <stdio.h>

#define SIZE 5
int array[SIZE];
int count = 0;

void insert(int value);
void getByIndex(int index);
void removeByIndex(int index);
void removeByValue(int value);
void showList(void);

int main(void){
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
}

void insert(int value){
    if(count == SIZE){
        printf("List full. Value not inserted: %d\n", value);
        return;
    }
    int i;
    for(i=0; i<count; i++){
        if(value < array[i]){ // Quando true, i conterá a posição que value deve ocupar
            int j;
            for(j=count; j>i; j--){ // Movimenta todos os valores para direita
                array[j] = array[j-1];
            }
            break;
        }
    }
    count++;
    array[i] = value;
}

void getByIndex(int index){
    if(index < count && index >=0){
        printf("%d\n", array[index]);
    } else {
        printf("Invalid index\n");
    }
}

void removeByIndex(int index){

}

void removeByValue(int value){
    
}

void showList(void){
    int i;
    printf("List: ");
    for(i=0; i<count; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

