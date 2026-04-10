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
