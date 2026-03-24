### Tree Notes

## Binary Search Tree (BST)

```C
    #include<stdio.h>
    #include<stdlib.h>
    
    typedef struct Node{
        struct Node *left;
        int data;
        struct Node *right;
    }Node;
    
    void insert(Node **st, int n){
        Node *p = NULL;
        if(*st == NULL){
            p = (Node *) malloc(sizeof(Node));
            p->data = n;
            p->left = NULL;
            p->right= NULL;
            (*st) = p;
        }
        else if((*st)->data > n){
            insert(&((*st)->left), n);
        }
        else if((*st)->data < n){
            insert(&((*st)->right), n);
        }
        else{
            printf("Duplicate Entry is not allowed!");
        }
    }
    
    void inorder(Node *root){
        if(root != NULL){
            inorder(root->left);
            printf("%d ", root->data);
            inorder(root->right);
        }
    }
    
    void preorder(Node *root){
        if(root != NULL){
            printf("%d ", root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }
    
    void postorder(Node *root){
        if(root != NULL){
            postorder(root->left);
            postorder(root->right);
            printf("%d ", root->data);
        }
    }
    
    void countNodes(Node *ptr, int *c){
        if(ptr != NULL){
            (*c)++;
            countNodes(ptr->left, c);
            countNodes(ptr->right, c);
        }
    }
    
    void countLeafNodes(Node *ptr, int *c){
        if(ptr != NULL){
            if(ptr->left == NULL && ptr->right == NULL){
                (*c)++;
            }
            countLeafNodes(ptr->left, c);
            countLeafNodes(ptr->right, c);
        }
    }
    
    void main(){
        Node *BST = NULL;
        int count = 0, leaf = 0;
        insert(&BST, 50);
        insert(&BST, 70);
        insert(&BST, 40);
        insert(&BST, 20);
        insert(&BST, 10);
        insert(&BST, 30);
        insert(&BST, 80);
        printf("\nInorder Traversal: \n");
        inorder(BST);
        printf("\nPreorder Traversal: \n");
        preorder(BST);
        printf("\nPostorder Traversal: \n");
        postorder(BST);
    
        countNodes(BST, &count);
        printf("\nTotal no. of nodes are: %d", count);
    
        countLeafNodes(BST, &leaf);
        printf("\nTotal no. of leaf nodes are: %d", leaf);
    }
```
