### Tree Notes

## Binary Search Tree (BST)

```C
    #include<stdio.h>
    #include<stdlib.h>
    #include<conio.h>


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
            printf("\nKey Inserted Successfully...");
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

/*
    void countNodes(Node *ptr, int *c){
        if(ptr != NULL){
            (*c)++;
            countNodes(ptr->left, c);
            countNodes(ptr->right, c);
        }
    }
    */

    int countNodes(Node *ptr){
        if(ptr == NULL){
            return 0;
        }
        else{
            return countNodes(ptr->left) + countNodes(ptr->right) + 1;
        }
    }

    /*
    void countLeafNodes(Node *ptr, int *c){
        if(ptr != NULL){
            if(ptr->left == NULL && ptr->right == NULL){
                (*c)++;
            }
            countLeafNodes(ptr->left, c);
            countLeafNodes(ptr->right, c);
        }
    }
    */

    int countLeafNodes(Node *ptr){
        if(ptr == NULL){
            return 0;
        }
        else if(ptr->left == NULL && ptr->right == NULL){
            return 1;
        }
        else{
            return countLeafNodes(ptr->left) + countLeafNodes(ptr->right);
        }
    }

    int height(Node *root){
        if(root == NULL){
            return -1;
        }
        int l = height(root->left);
        int r = height(root->right);
        return (l>=r ? l : r) + 1;
    }

    int havingBothChildren(Node *root){
        int count = 0;
        if(root == NULL){
            return 0;
        }
        if(root->left != NULL && root->right != NULL){
            count++;
        }
        return count + havingBothChildren(root->left) + havingBothChildren(root->right);
    }

    int countSiblingNodes(Node *root){
        // Count no. of nodes which are sharing common parents.
        int count = 0;
        if(root == NULL){
            return 0;
        }
        if(root->left != NULL && root->right != NULL){
            count = 2;
        }
        return count + countSiblingNodes(root->left) + countSiblingNodes(root->right);
    }

    int havingLeftChildOnly(Node *root){
        int count = 0;
        if(root == NULL){
            return 0;
        }
        if(root->left != NULL && root->right == NULL){
            count++;
        }
        return count + havingLeftChildOnly(root->left) + havingLeftChildOnly(root->right);
    }

    int havingRightChildOnly(Node *root){
        int count = 0;
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right != NULL){
            count++;
        }
        return count + havingRightChildOnly(root->left) + havingRightChildOnly(root->right);
    }

    int maxElement(Node *root){
        if (root == NULL) {
            printf("Tree is empty");
            return -1;
        }
        if(root->right == NULL){
            return root->data;
        }
        return maxElement(root->right);
    }

    int minElement(Node *root){
        if (root == NULL) {
            printf("Tree is empty");
            return -1;
        }
        if(root->left == NULL){
            return root->data;
        }
        return minElement(root->left);
    }

    int inorderSuccessorOfKey(Node *root, int key){
        // Inorder Successor: The smallest element in the right subtree of the key.
        while(root != NULL){
            if(key < (root->data)){
                root = root->left;
            }
            else if(key > (root->data)){
                root = root->right;
            }
            else{
                break;
            }
        }
        if(root == NULL){
            printf("\nKey does not exists!");
            return -1;
        }

        return minElement(root->right);
    }

    int inorderPredessorOfKey(Node *root, int key){
        // Inorder Predessor: The largest element in the left subtree of the key.
        // Searching the key
        while(root != NULL){
            if(key < root->data){
                root = root->left;
            }
            else if(key > root->data){
                root = root->right;
            }
            else{
                break;
            }
        }
        // If key not found
        if(root == NULL){
            printf("\nKey does not exists!");
            return -1;
        }
        return maxElement(root->left);
    }

    void deleteLeafNode(Node **root, Node *current, Node *parent){
        if(parent == NULL){
            // If leaf node does not have any parent it means it is root node and tree contains only one element.
            (*root) = NULL;
        }
        else if(current == parent->left){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
        free(current);
    }

    void deleteNodeHavingOneChild(Node **root, Node *current, Node *parent){
            Node *child;
            if(current->left != NULL){
                child = current->left;
            }
            else{
                child = current->right;
            }
            if(parent == NULL){
                (*root) = child;
            }
            else if(parent->left == current){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
            free(current);
    }

    void deleteNodeHavingTwoChilds(Node **root, Node *current, Node *parent){
        // Finding inorder successor and it's parent.
        Node *successor = current->right;
        Node *successorParent = current;
        while(successor->left != NULL){
            successorParent = successor;
            successor = successor->left;
        }

        // copy successor data into node to be deleted.
        current->data = successor->data;

        if(successor->left == NULL && successor->right == NULL){
            deleteLeafNode(root, successor, successorParent);
        }
        else{
            deleteNodeHavingOneChild(root, successor, successorParent);
        }
    }

    void deleteKey(Node **root){
        if(*root == NULL){
            printf("\nTree is empty!");
            return;
        }
        // Input key from the user.
        int key;
        printf("Enter key which you want to delete: ");
        scanf("%d", &key);

        // Searching the key
        Node *current = (*root);
        Node *parent = NULL;
        while(current != NULL){
            if(key == current->data){
                break;
            }
            parent = current;
            if(key < current->data){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }

        if(current == NULL){
            printf("\nKey does not exists!");
            return;
        }
        else if(current->left != NULL && current->right != NULL){
            // If node having both child.
            deleteNodeHavingTwoChilds(root, current, parent);
        }
        else if(current->left != NULL){
            // If node have only left child.
            deleteNodeHavingOneChild(root, current, parent);
        }
        else if(current->right != NULL){
            // If node have only right child.
            deleteNodeHavingOneChild(root, current, parent);
        }
        else{
            // If node does not have any child (Leaf Node).
            deleteLeafNode(root, current, parent);
        }
        printf("\nElement deleted successfully where key = %d", key);
    }

    void main(){
        system("color 1f");
        Node *BST = NULL;
       /* insert(&BST, 50);
        insert(&BST, 70);
        insert(&BST, 40);
        insert(&BST, 20);
        insert(&BST, 10);
        insert(&BST, 30);
        insert(&BST, 80);
*/
        int choice, key;
        do{
            printf("***********Operations on BST ***********\n");
            printf("\n1. Insert new node ");
            printf("\n2. Delete node");
            printf("\n3. Preorder Traversal");
            printf("\n4. Inorder Traversal");
            printf("\n5. Postorder Traversal");
            printf("\n6. Count total nodes");
            printf("\n7. Count leaf nodes");
            printf("\n8. Count total number of nodes which are left of the root");
            printf("\n9. Count total number of nodes which are right of the root");
            printf("\n10. Count total number of nodes having both child");
            printf("\n11. Count total number of nodes having only left child");
            printf("\n12. Count total number of nodes having only right child");
            printf("\n13. Count total number of sibling nodes");
            printf("\n14. Get max element");
            printf("\n15. Get min element");
            printf("\n16. Height of tree");
            printf("\n17. Inorder successor of key");
            printf("\n18. Inorder predessor of key");
            printf("\n19. Exit");

            printf("\n\nEnter your choice: ");
            scanf("%d", &choice);

            switch(choice){
            case 1:
                printf("Enter the key: ");
                scanf("%d", &key);
                insert(&BST, key);
                break;
            case 2:
                deleteKey(&BST);
                break;
            case 3:
                printf("\nPreorder Traversal: \n");
                preorder(BST);
                break;
            case 4:
                printf("\nInorder Traversal: \n");
                inorder(BST);
                break;
            case 5:
                printf("\nPostorder Traversal: \n");
                postorder(BST);
                break;
            case 6:
                printf("\nTotal no. of nodes are: %d", countNodes(BST));
                break;
            case 7:
                printf("\nTotal no. of leaf nodes are: %d", countLeafNodes(BST));
                break;
            case 8:
                (BST == NULL) ? printf("\nTree is empty!") :
                printf("\nTotal no. of nodes which are the left side of root node: %d", countNodes(BST->left));
                break;
            case 9:
                (BST == NULL) ? printf("\nTree is empty!") :
                printf("\nTotal no. of nodes which are the right side of root node: %d", countNodes(BST->right));
                break;
            case 10:
                printf("\nNo. of nodes having both child: %d", havingBothChildren(BST));
                break;
            case 11:
                printf("\nNo. of nodes having Left child only: %d", havingLeftChildOnly(BST));
                break;
            case 12:
                printf("\nNo. of nodes having Right child only: %d", havingRightChildOnly(BST));
                break;
            case 13:
                printf("\nNo. of nodes sharing common parent: %d", countSiblingNodes(BST));
                break;
            case 14:
                printf("\nMax Element: %d", maxElement(BST));
                break;
            case 15:
                printf("\nMin Element: %d", minElement(BST));
                break;
            case 16:
                printf("\nHeight of the tree are: %d", height(BST));
                break;
            case 17:
                printf("\nEnter the key: ");
                scanf("%d", &key);
                printf("\nInorder Successor : %d", inorderSuccessorOfKey(BST, key));
                break;
            case 18:
                printf("\nEnter the key: ");
                scanf("%d", &key);
                printf("\nInorder Predessor : %d", inorderPredessorOfKey(BST, key));
                break;
            }
            getch();
            system("cls");
        }while(choice <= 18 && choice > 0);
    }
```
