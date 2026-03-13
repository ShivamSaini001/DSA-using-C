# Queue

A Queue is a **linear data structure** that follows the principle of **FIFO (First In First Out)**.
i.e., The **element inserted first** will be **removed first**.

A queue has mainly two ends--  
**1) Front:** The position from where elements are removed  
**2) Rear:** The position where elements are inserted

<img width="745" height="146" alt="image" src="https://github.com/user-attachments/assets/a3419eba-8867-463f-a80e-6f750754d755" />

## Applications of Queue
1) Processor Scheduling
2) Device Scheduling
3) In Implementing BFS(Breadth First Search)

## Basic Operations of Queue
1) Enqueue (Insertion)- To add an element at the rear end of the queue
2) Dequeue (Deletion)- To remove an element from front of the queue
3) Peek (Front)- To print Front element of the queue
4) Display- To print all elements in queue from Front to Rear
5) isEmpty()
6) isFull()


## Simple Queue
```C
    #define MAX 10
    #include<stdio.h>
    
    int enqueue(int queue[], int front, int rear);
    int dequeue(int queue[], int front, int rear);
    void peek(int queue[], int front, int rear);
    void display(int queue[], int front, int rear);
    
    
    void main(){
        int queue[MAX], front=-1, rear=-1, ch;
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
                    rear = enqueue(queue, front, rear);
                    if(front==-1){
                        front++;
                    }
                    break;
                case 2:
                    front = dequeue(queue, front, rear);
                    if(front == -1){
                        rear = -1;
                    }
                    break;
                case 3:
                    peek(queue, front, rear);
                    break;
                case 4:
                    display(queue, front, rear);
                    break;
           }
        }while(ch < 5);
    }
    
    int enqueue(int queue[], int front, int rear){
        if(rear == MAX-1){
            printf("Queue is full!\n");
        }
        else{
            int data;
            printf("Enter a value: ");
            scanf("%d",&data);
            rear++;
            queue[rear]=data;
        }
        return rear;
    }
    
    int dequeue(int queue[], int front, int rear){
        if(front == -1 && rear == -1){
            printf("Queue is empty!\n");
        }
        else{
            printf("Deleted element is %d\n", queue[front]);
            if(front == rear){
                front = -1;
            }
            else{
                front++;
            }
        }
      return front;
    }
    
    void peek(int queue[], int front, int rear){
        if(front == -1 && rear == -1){
            printf("Queue is empty!\n");
        }
        else{
            printf("Peek element is: %d\n", queue[front]);
        }
    }
    
    void display(int queue[], int front, int rear){
        if(front == -1 && rear == -1){
            printf("Queue is empty!\n");
        }
        else{
            while(front <= rear){
                printf("%d ",queue[front]);
                front++;
            }
        }
    }
```


## Circular Queue

```C
    #define MAX 10
    #include<stdio.h>
    
    int enqueue(int queue[], int front, int rear);
    int dequeue(int queue[], int front, int rear);
    void peek(int queue[], int front, int rear);
    void display(int queue[], int front, int rear);
    
    
    void main(){
        int queue[MAX], front=-1, rear=-1, ch;
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
                    rear = enqueue(queue, front, rear);
                    if(front==-1){
                        front++;
                    }
                    break;
                case 2:
                    front = dequeue(queue, front, rear);
                    if(front == -1){
                        rear = -1;
                    }
                    break;
                case 3:
                    peek(queue, front, rear);
                    break;
                case 4:
                    display(queue, front, rear);
                    break;
           }
        }while(ch < 5);
    }
    
    int enqueue(int queue[], int front, int rear){
        if((rear+1)%MAX == front){
            printf("Queue is full!");
        }
        else{
            int data;
            printf("Enter a value: ");
            scanf("%d",&data);
            rear = (rear+1)%MAX;
            queue[rear]=data;
        }
        return rear;
    }
    
    int dequeue(int queue[], int front, int rear){
        if(front == -1 && rear == -1){
            printf("Queue is empty!");
        }
        else{
            printf("Deleted element is %d\n", queue[front]);
            if(front == rear){
                front = -1;
            }
            else{
                front=(front+1)%MAX;
            }
        }
      return front;
    }
    
    void peek(int queue[], int front, int rear){
        if(front == -1 && rear == -1){
            printf("Queue is empty!");
        }
        else{
            printf("Peek element is: %d\n", queue[front]);
        }
    }
    
    void display(int queue[], int front, int rear){
        if(front == -1 && rear == -1){
            printf("Queue is empty!");
        }
        else{
            while(rear != front){
                printf("%d ",queue[front]);
                front = (front+1)%MAX;
            }
            printf("%d \n",queue[front]);
        }
    }
```


## Deque (Data Structure)






