# Linked List

## Write a C program to implement process management using circular linked list.

```C
  #include <stdio.h>
  #include<stdlib.h>
  
  typedef struct Node{
      char processId[10];
      int priority;
      struct Node *next;
  }Node;
  
  void executeProcess(Node **head){
      if(*head == NULL){
          printf("\nProcess List is Empty!");
      }
      else{
         // Delete High Priority Process
         Node *highPriorityProcess = *head;
         Node *temp = (*head)->next;
  
         while(temp != (*head)){
           if(highPriorityProcess->priority < temp->priority){
              highPriorityProcess = temp;
           }
         }
  
         while(temp->next != *head){
           if(temp->next == highPriorityProcess){
              temp = temp->next;
              printf("\nProcess %s Executed Successfully!", highPriorityProcess->processId);
              free(highPriorityProcess);
              break;
           }
         }
      }
  }
  
  void insertAtStart(Node **head){
      int p;
      char id[10];
      printf("\nEnter process id: ");
      scanf("%s", id);
      printf("\nEnter priority of process: ");
      scanf("%d", &p);
  
      Node *newNode = (Node *) malloc(sizeof(Node));
      newNode->priority = p;
      newNode->processId = id;
      if(*head == NULL){
          *head = newNode;
          newNode->next = *head;
      }else{
          Node *lastNode =(*head);
          while(lastNode->next != (*head)){
              lastNode = lastNode->next;
          }
          newNode->next = *head;
          lastNode->next = newNode;
      }
  }
  
  void display(Node *head){
      if(head != NULL){
          Node *temp = head;
          printf("\nprocessId\t\tPriority");
          do{
              printf("%d\t\t%s", temp->processId, temp->priority);
              temp = temp->next;
          }while(temp != head);
      }
  }
  
  int main() {
      Node *priorityQueue = NULL;
      printf("\n1. Add Process");
      printf("\n2. Execute High Priority Process");
      printf("\n3. Display");
      printf("\n4. Exit");
      int ch;
  
      do{
          printf("\n\nEnter your choice: ");
          scanf("%d",&ch);
          switch(ch){
              case 1:
                  insertAtStart(&priorityQueue);
                  break;
              case 2:
                  executeProcess(&priorityQueue);
                  break;
              case 3:
                  display(priorityQueue);
                  break;
          }
      }while(ch < 4);
      return 0;
  }
```
