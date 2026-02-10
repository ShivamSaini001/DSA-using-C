// Implement Stack using Linked List with the concept of call by Reference.

#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int data;
    struct Stack *next;
}Stack;

void push(Stack **top){
    int x;
    Stack *newNode = NULL;
    newNode = (Stack *)malloc(sizeof(Stack));
    if(newNode == NULL){
        printf("\nMemory is not allocated: ");
    }
    else{
        printf("Enter a integer number: ");
        scanf("%d", &x);
        newNode->data = x;
        newNode->next = *top;
        *top = newNode;
    }
}

void pop(Stack **top){
    if(*top == NULL){
        printf("\nStack is Empty!");
    }
    else{
        Stack *p = *top;
        printf("Poped element is: %d", p->data);
        *top = (*top)->next;
        free(p);
    }
    return top;
}

void display(Stack *top){
    if(top == NULL){
        printf("\nStack is Empty!");
    }
    else{
        printf("\nStack elements is: \n");
        while(top->next != NULL){
            printf("%d ", top->data);
            top = top->next;
        }
        printf("%d ", top->data);
    }
}

void peek(Stack *top){
    if(top == NULL){
        printf("\nStack is Empty!");
    }
    else{
        printf("\nPeek element is: %d", top->data);
    }
}

void main(){
    Stack *top = NULL;
    int ch;
    printf("\n1. Push \n");
    printf("2. Pop \n");
    printf("3. Display \n");
    printf("4. peek \n");
    printf("5. exit \n");
    do{
        printf("\n\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            peek(top);
            break;
        }
    }while(ch<=4);
}
