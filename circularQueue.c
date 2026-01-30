// Implementig Circular Queue using call by value.
#define MAX 10
#include<stdio.h>

int enqueue(int cq[], int front, int rear){
    if((rear+1)% MAX == front){
        printf("Queue is Full!\n");
    }
    else{
        int data;
        printf("Enter a number: ");
        scanf("%d", &data);
        rear = (rear+1)% MAX;
        cq[rear] = data;
    }
    return rear;
}

int dequeue(int cq[], int front, int rear){
    if(front == -1 && rear == -1){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Deleted element is: %d", cq[front]);
        if(front == rear){
            front = -1;
        }
        else{
            front = (front + 1) % MAX;
        }
    }
    return front;
}

void peek(int cq[], int front, int rear){
    if(front == -1 && rear == -1){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Peak element is: %d", cq[rear]);
    }
}

void display(int cq[], int front, int rear){
    if(front == -1 && rear == -1){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Circular Queue elements are:\n");
        while(front != rear){
            printf("%d ", cq[front]);
            front = (front + 1) % MAX;
        }
        // if front == rear
        printf("%d ", cq[front]);
    }
}

void main(){
    int cq[MAX], front = -1, rear = -1, ch;
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                rear = enqueue(cq, front, rear);
                if(front == -1){
                    front ++;
                }
                break;
            case 2:
                front = dequeue(cq, front, rear);
                if(front == -1){
                    rear = -1;
                }
                break;
            case 3:
                peek(cq, front, rear);
                break;
            case 4:
                display(cq, front, rear);
                break;
        }
    }while(ch <= 4);
}
