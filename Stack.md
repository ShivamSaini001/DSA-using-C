# Stack Notes

A **Stack** is a **linear data structure or abstract data type (ADT) that follows the Last In First Out (LIFO) principle** in which **insertion** and **deletion** operations are performed only at one end called the **TOP** of the stack.  
Stack is also called an **Abstract Data Type (ADT)** because it defines operations but not implementation.

## Basic Operations of Stack
There are **five** main operations.

| Operation | Description |
|-----------|-------------|
| Push | Insert an element on top of the stack |
| Pop | Remove the top element from the stack |
| Peek | View the top element without removing it |
| isEmpty | Check if stack is empty |
| isFull | Check if stack is full (in array implementation) |

## Time Complexity
All operations are **constant time**.
| Operation | Time Complexity |
|-----------|-----------------|
| Push | O(1) |
| Pop | O(1) |
| Peek | O(1) |

## Applications of Stack
Stacks are used in many real world and programming situations.
1) Expression Evaluation
2) Function Calls (Call Stack)
3) Undo / Redo Operations
4) Parenthesis Checking
5) Backtracking

## Types of Stack
1) **Fixed Size Stack**
   - A fixed size stack has a predefined capacity.
   - Once it becomes full, no more elements can be added (this causes overflow).
   - If the stack is empty and we try to remove an element, it causes underflow.
   - Typically implemented using a static array.
     
3) **Dynamic Size Stack**
   - A dynamic size stack can grow and shrink automatically as needed.
   - If the stack is full, its capacity expands to allow more elements.
   - As elements are removed, memory usage can shrink as well.
   - Can be implemented using:
     - **Linked List** → grows/shrinks naturally.
     - **Dynamic Array** (like vector in C++ or ArrayList in Java) → resizes automatically.

**Note:** We generally use dynamic stacks in practice, as they can grow or shrink as needed without overflow issues.

## Coding Interview Questions
1) Reverse a string using stack
2) Check balanced parentheses: e.g., **( [ { } ] )**
3) Convert infix to postfix expression
4) Evaluate postfix expression
5) Implement two stacks in one array

## Stack Implementation
A stack can be implemented in two ways:  
1️⃣ Array Implementation  
2️⃣ Linked List Implementation  






## **Problem statement-1:**
Write a C program to implement stack using static memory allocation(Array) with call by value concept(By Returninig).

## **Objective:**
To understand the concept of Stack using Array.

## Assumptions:
Let we have an Array named as stack and a local variable top.

## **Algorithm for push operation:**

<pre>
  Step-1: START
  Step-2: Recieved Parameters Stack[], top, MAX
          Declare variable X
  Step-3: check if(top == MAX-1)
          then, print "Stack is Full"
                goto step-7
  Step-4: Input X
  Step-5: set top = top+1
  Step-7: set Stack[top] = X
  Step-7: return top
  step-8: STOP
</pre>

## **Algorithm for pop operation:**

<pre>
  Step-1: START
  Step-2: Recieved Parameters Stack[], top, MAX
  Step-3: check if(top == -1)
          then, print "Stack is Empty"
                goto step-6
  Step-4: print Stack[top]
  Step-5: set top = top-1
  Step-6: return top
  step-7: STOP
</pre>

## **Algorithm for peek operation:**

<pre>
  Step-1: START
  Step-2: Recieved Parameters Stack[], top
  Step-3: check if(top == -1)
          then, print "Stack is Empty"
                goto step-5
  Step-4: print Stack[top]
  step-5: STOP
</pre>

## **Algorithm for display operation:**

<pre>
  Step-1: START
  Step-2: Recieved Parameters Stack[], top
  Step-3: check if(top == -1)
          then, print "Stack is Empty"
                goto step-7
  Step-4: Repeat step-5 and step-6 while(top != -1)
  Step-5: print Stack[top]
  Step-6: top = top-1
  step-7: STOP
</pre>

## **Code:**

```c
//Stack Implementation using stack (call by value)

  #define MAX 10
  #include<stdio.h>
  #include<conio.h>
  
  int push(int stack[], int top){
      if(top == MAX-1){
          printf("Stack is full(Overflow)!\n");
      }else{
          int data;
          printf("Enter the Element: ");
          scanf("%d", &data);
          top++;
          stack[top] = data;
      }
      return top;
  }
  
  int pop(int stack[], int top){
      if(top == -1){
          printf("Stack is empty (Underflow):\n ");
      }else{
          printf("Deleted element is: %d", stack[top]);
          top--;
      }
      return top;
  }
  
  void peek(int stack[], int top){
      if(top == -1){
          printf("Stack is empty: \n");
      }else{
          printf("Peek element is: %d", stack[top]);
      }
  }
  
  void display(int stack[], int top){
      if(top == -1){
          printf("Stack is empty: \n");
      }else{
          printf("Stack elements are: \n");
          while(top >= 0){
              printf("%d ", stack[top]);
              top--;
          }
      }
  }
  
  
  void main(){
      int stack[MAX], top = -1;
      int ch;

      printf("\n1. push\n");
      printf("2. pop\n");
      printf("3. peek\n");
      printf("4. display\n");
      printf("5. Exit\n");
      do{
          printf("Enter your choice: ");
          scanf("%d", &ch);
          switch(ch){
              case 1:
                  top = push(stack, top);
                  break;
              case 2:
                  top = pop(stack, top);
                  break;
              case 3:
                  peek(stack, top);
                  break;
              case 4:
                  display(stack, top);
                  break;
          }
      }while(ch <= 4);
  }

```


## **Problem statement-2:**
Write a C program to implement stack using static memory allocation(Array) with call by reference concept(without returninig).

## **Objective:**
To understand the concept of Stack using Array.

## Assumptions:
Let we have an Array named as stack and a local variable top.

## **Code:**

```c
  //Stack Implementation using stack (call by reference)

    #define MAX 10
    #include<stdio.h>
    #include<conio.h>
  
    void push(int stack[], int *top){
        if(*top == MAX-1){
            printf("Stack is full(Overflow)!\n");
        }else{
            int data;
            printf("Enter the Element: ");
            scanf("%d", &data);
            (*top)++;
            stack[*top] = data;
        }
    }
  
    void pop(int stack[], int *top){
        if(*top == -1){
            printf("Stack is empty (Underflow):\n ");
        }else{
            printf("Deleted element is: %d", stack[*top]);
            (*top)--;
        }
    }
  
    void peek(int stack[], int *top){
        if(*top == -1){
            printf("Stack is empty: \n");
        }else{
            printf("Peek element is: %d", stack[*top]);
        }
    }
  
    void display(int stack[], int *top){
        if(*top == -1){
            printf("Stack is empty: \n");
        }else{
            int temp = *top;
            printf("Stack elements are: \n");
            while(temp >= 0){
                printf("%d ", stack[temp]);
                temp--;
            }
        }
    }
  
    void main(){
        int stack[MAX], top = -1;
        int ch;
  
        printf("\n1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("5. Exit\n");
        do{
            printf("\nEnter your choice: ");
            scanf("%d", &ch);
            switch(ch){
                case 1:
                    push(stack, &top);
                    break;
                case 2:
                    pop(stack, &top);
                    break;
                case 3:
                    peek(stack, &top);
                    break;
                case 4:
                    display(stack, &top);
                    break;
            }
        }while(ch <= 4);
    }
```


## **Problem statement-3:**
Write a C program to implement stack using dynamic memory allocation(Linked List) with call by value concept(By Returninig).

## **Objective:**
To understand the concept of Stack using Linked List.

## Assumptions:
Let we have a complex data type structure and a local pointer top initialize with NULL.

## **Algorithm for push operation:**
// Note: Insertion and Deletion operation at the start of the Linked List.


## **Code:**
```c
  // Implement Stack using Linked List with the concept of call by value.
  
  #include<stdio.h>
  
  typedef struct Stack{
      int data;
      struct Stack *next;
  }Stack;
  
  Stack* push(Stack *top){
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
          newNode->next = top;
          top = newNode;
      }
      return top;
  }
  
  Stack* pop(Stack *top){
      if(top == NULL){
          printf("\nStack is Empty!");
      }
      else{
          Stack *p = top;
          printf("Poped element is: %d", p->data);
          top = top->next;
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
              top = push(top);
              break;
          case 2:
              top = pop(top);
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
```

## **Problem statement-4:**
Write a C program to implement stack using dynamic memory allocation(Linked List) with call by reference concept(Without Returninig).

## **Objective:**
To understand the concept of Stack using Linked List.

## Assumptions:
Let we have a complex data type structure and a local pointer top initialize with NULL.

## **Algorithm for push operation:**
// Note: Insertion and Deletion operation at the start of the Linked List.




## **Code:**

```c
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
```






