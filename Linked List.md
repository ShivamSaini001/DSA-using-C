# Linked List

## Write a C program to implement process management using circular linked list.

```C
  #include <stdio.h>
  #include<stdlib.h>
  #include<string.h>

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
         Node *temp = *head;

         while(temp->next != (*head)){
           if(highPriorityProcess->priority > temp->priority){
              highPriorityProcess = temp;
           }
           temp = temp->next;
         }
         if(highPriorityProcess->priority > temp->priority){
              highPriorityProcess = temp;
         }

         printf("High priority process: ");
         printf("\n%s\t\t%d", highPriorityProcess->processId, highPriorityProcess->priority);

         if((*head)->next == *head){
            *head = NULL;
            free(highPriorityProcess);
         }
         // Delete first node
         else if(highPriorityProcess == *head){
            *head = (*head)->next;
            temp->next = *head;
            free(highPriorityProcess);
         }
         // Delete last node
         // Delete from position
         else{
            temp = *head;
            while(temp->next->next != *head){
               if(temp->next == highPriorityProcess){
                  temp->next = temp->next->next;
                  printf("\nProcess %s Executed Successfully!", highPriorityProcess->processId);
                  free(highPriorityProcess);
                  break;
               }
             }
            // Pending code
            if(highPriorityProcess->next == *head){
                
            }
         }
      }
  }

  void insertAtEnd(Node **head){
      int p;
      char id[10];
      printf("\nEnter process id: ");
      scanf("%s", id);
      printf("\nEnter priority of process: ");
      scanf("%d", &p);

      Node *newNode = (Node *) malloc(sizeof(Node));
      newNode->priority = p;
      strcpy(newNode->processId, id);
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
      if(head == NULL){
        printf("Queue is Empty!");
      }
      else {
          Node *temp = head;
          printf("\nprocessId\tPriority");

          do{
              printf("\n%s\t\t%d", temp->processId, temp->priority);
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
                  insertAtEnd(&priorityQueue);
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

## Doubly Linked List

```C
  #include<stdio.h>
  #include<stdlib.h>
  
  typedef struct Node{
      int info;
      struct Node *prev, *next;
  }Node;
  
  Node* insertNodeAtFirst(Node *head){
      Node *newNode = (Node*) malloc(sizeof(Node));
      printf("\nEnter data: ");
      scanf("%d", &(newNode->info));
      if(head == NULL){
          head = newNode;
          head->next = NULL;
          head->prev = NULL;
      }
      else{
          newNode->prev = NULL;
          newNode->next = head;
          head->prev = newNode;
          head = newNode;
      }
      return head;
  }
  
  void displayList(Node *head){
      if(head != NULL){
          do{
              printf("%d ", head->info);
              head = head->next;
          }while(head != NULL);
      }
  }
  
  Node* swapFirstWithLast(Node *head){
      if(head != NULL){
          int data;
          Node *lastNode = head;
          while(lastNode->next != NULL){
              lastNode = lastNode->next;
          }
          data = lastNode->info;
          lastNode->info = head->info;
          head->info = data;
      }
      return head;
  }
  
  void main(){
      Node *head=NULL;
      int choice;
      printf("\n1. Insert new node");
      printf("\n2. Display");
      printf("\n3. Swap first and last node");
      do{
          printf("\nEnter your choice: ");
          scanf("%d", &choice);
  
          switch(choice){
          case 1:
              head = insertNodeAtFirst(head);
              break;
          case 2:
              displayList(head);
              break;
          case 3:
              head = swapFirstWithLast(head);
          }
      }while(choice <= 3 && choice > 0);
  
  
  }
```
