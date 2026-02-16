# Stack Notes

## **Problem statement-1:**
Write a C program to implement stack using static memory allocation(Array) with call by value concept(By Returninig).

## **Objective:**
To understand the concept of Stack.

## Assumptions:
Let we have an Array named as stack and a local variable top.

## **Algorithm for push operation:**

<pre>
  Step-1: START
  Step-2: Recieved Parameters Stack[], top, MAX
          Declare variable X
  Step-3: check if(top == MAX-1)
          then, print "Stack is Full"
                go to step-7
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
                go to step-6
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
                go to step-5
  Step-4: print Stack[top]
  step-5: STOP
</pre>

## **Algorithm for display operation:**

<pre>
  Step-1: START
  Step-2: Recieved Parameters Stack[], top
  Step-3: check if(top == -1)
          then, print "Stack is Empty"
                go to step-7
  Step-4: Repeat step-5 and step-6 while(top != -1)
  Step-5: print Stack[top]
  Step-6: top = top-1
  step-7: STOP
</pre>

## **Code:**

```c
//Stack Implementation using stack (call by value)

  #define max 10
  #include<stdio.h>
  #include<conio.h>
  
  int push(int stack[], int top){
      if(top == max){
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
      int stack[max], top = -1;
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
To understand the concept of Stack.

## Assumptions:
Let we have an Array named as stack and a local variable top.

## **Code:**

```c


```



