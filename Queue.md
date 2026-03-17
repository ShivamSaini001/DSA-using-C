# Queue
A Queue is a **linear data structure or Abstract Data Type (ADT)** that follows the principle of **FIFO (First In First Out)** in which insertion takes place at the **rear end** and deletion takes place at the **front end**.  
FIFO means the **element inserted first** will be **removed first**.  
A queue has mainly two ends--  
**1) Front:** The position from where elements are removed  
**2) Rear:** The position where elements are inserted

<img width="745" height="146" alt="image" src="https://github.com/user-attachments/assets/a3419eba-8867-463f-a80e-6f750754d755" />

## Simple Real-Life Example
Think about a queue of people at a ticket counter.
- The first person in the line gets served first
- New people join at the end of the line

## Applications of Queue
1) CPU Scheduling
2) Printer Spooling
3) Device Scheduling
4) Call Center Systems
5) Network Data Packets
6) In Implementing BFS(Breadth First Search)

## Basic Operations of Queue
1) Enqueue (Insertion)- To add an element at the rear end of the queue
2) Dequeue (Deletion)- To remove an element from front of the queue
3) Peek (Front)- To print Front element of the queue
4) Display- To print all elements in queue from Front to Rear
5) isEmpty()
6) isFull()

## Queue Implementation
A queue can be implemented using--  
1️⃣ Array  
2️⃣ Linked List  

## Types of Queue
There are **four main types of queues** in Data Structures:
1) Simple Queue (Linear Queue)
2) Circular Queue
3) Priority Queue
4) Deque (Double Ended Queue)


## 1) Simple Queue (Linear Queue):
A Simple Queue is also called **Linear Queue**.

### Time Complexity
| Operation | Complexity |
|-----------|------------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek | O(1) |

### 1️⃣ Array Representation of Simple Queue

<img src="asserts/Simple Queue.png" />

### Queue Overflow and Underflow
**1. Queue Overflow**  
<img src="asserts/Simple Queue Overflow.png" alt="Simple Queue Overflow"/>

Occurs when we try to insert element into a full queue.
**Condition:**
_rear == MAX - 1_

**Limitation of Simple Queue**  
After multiple dequeue operations--
- Front moves forward
- Empty spaces cannot be reused
- Even if space exists, queue may show **overflow**

**2. Queue Underflow**  
<img src="asserts/Simple Queue Underflow.png" alt="Simple Queue Underrflow"/>

Occurs when we try to remove element from an empty queue.
**Condition:**
_front == -1 && rear == -1_

### Code (Call By Value Concept):

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

### 2️⃣ Linked List Representation of Simple Queue 

In this implementation, a **queue is created using a linked list**, where:
- Each element is stored in a **node**
- Nodes are connected using **pointers**
- We maintain **two pointers**:
  - **Front** (for deletion)
  - **Rear** (for insertion)

Each node contains:
- **Data->** Stores value
- **Next->** Points to next node

### Queue Overflow and Underflow
**1. Queue Overflow**  
Occurs when we try to **insert new node** into a queue but **new node cannot be created**.

**2. Queue Underflow**  
<img src="#" alt="#"/>

Occurs when we try to remove element from an empty queue.
**Condition:**
_front == NULL && rear == NULL_


### Code (Call By Value Concept):

```C
    #include<stdio.h>
    #include<stdlib.h>
    
    typedef struct Node{
        int data;
        struct Node *next;
    }Node;
    
    Node * enqueue(Node *front, Node *rear);
    Node * dequeue(Node *front, Node *rear);
    void peek(Node *front);
    void display(Node *front);
    
    void main(){
        Node *front = NULL, *rear = NULL;
        int ch;
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
                    rear = enqueue(front, rear);
                    if(front==NULL){
                        front = rear;
                    }
                    break;
                case 2:
                    front = dequeue(front, rear);
                    if(front == NULL){
                        rear = NULL;
                    }
                    break;
                case 3:
                    peek(front);
                    break;
                case 4:
                    display(front);
                    break;
           }
        }while(ch < 5);
    }
    
    
    Node * enqueue(Node *front, Node *rear){
        int x;
        printf("Enter data: ");
        scanf("%d", &x);
        Node *newNode = NULL;
        newNode = (Node *) malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Memory cannot be allocated(Overflow)!\n");
        }
        else{
            newNode->data = x;
            newNode->next = NULL;
            if(front == NULL && rear == NULL){
                rear = newNode;
            }
            else{
                rear->next = newNode;
                rear = newNode;
            }
        }
        return rear;
    }
    
    Node * dequeue(Node *front, Node *rear){
        if(front == NULL && rear == NULL){
            printf("Queue is empty(Underflow)!\n");
        }
        else{
            Node *temp = front;
            printf("Deleted element is: %d", temp->data);
            front = front->next;
            free(temp);
        }
        return front;
    }
    
    void peek(Node *front){
        if(front == NULL){
            printf("Queue is empty(Underflow)!\n");
        }
        else{
            printf("Peak element is: %d", front->data);
        }
    }
    
    void display(Node *front){
        if(front == NULL){
            printf("Queue is empty(Underflow)!\n");
        }
        else{
            do{
                printf("%d -> ", front->data);
                front = front->next;
            }while(front != NULL);
            printf("NULL");
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

**Deque** stands for **Double Ended Queue**.
A **Deque** is a linear data structure that allows **insertion and deletion of elements from both the front and rear ends**.

### Basic Operations of Deque

| Operation	| Description |
|-----------|-------------|
| InsertFront | Add element at the front |
| InsertRear | Add element at the rear |
| DeleteFront | Remove element from front |
| DeleteRear | Remove element from rear |
| GetFront | Read the front element |
| GetRear | Read the rear element |
| isEmpty | Check if deque is empty |
| isFull | Check if deque is full |


### Types of Deque
There are **two main types of Deque**.
1) **Input Restricted Deque**
   - Insertion allowed only at one end
        - Insertion → Rear only
   - Deletion allowed at both ends
        - Deletion → Front or Rear

3) **Output Restricted Deque**
    - Deletion allowed only at one end
        - Deletion → Front only
    - Insertion allowed at both ends
        - Insertion → Front and Rear
            

### Deque Representation
1) Array
2) Doubly Linked List


### Applications of Deque
1) Sliding Window Algorithm
2) Palindrome Checking
3) Undo / Redo Systems
4) Job Scheduling
5) Breadth First Search (BFS)


