# Stack Notes

## **Problem statement:**
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

## **Code:  **

```c


```

