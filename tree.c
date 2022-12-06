#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
    int data;
    struct tree * left, * right;
} t;

t * root = NULL;


void preOrder(t * root) {
    if(root != NULL) {
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(t * root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}

void postOrder(t * root) {
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}


void insert(t ** root, t ** newNode) {
    if(*root == NULL) {
        *root = *newNode;
    }
    else if((*root)->data > (*newNode)->data) {
        insert(&(*root)->left, &(*newNode));
    }
    else {
        insert(&(*root)->right, &(*newNode));
    }
}


t * find_min(t * root) {
    if(root == NULL) {
        return NULL;
    }
    else if(root->left != NULL) {
        return find_min(root->left);
    }
    return root;
}

t * delete(t * root, int data) {
    if(root == NULL) {
        return NULL;
    }
    else if(data > root->data) {
        root->right = delete(root->right, data);
    }
    else if(data < root->data) {
        root->left = delete(root->left, data);
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL) {
            t * temp;
            if(temp->left == NULL) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
            free(root);
            return temp;
        }
        else {
            t * temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {

    int choice;
    while(1) {
        printf("1. Insert\n2. InOrder\n3. PreOrder\n4. PostOrder\n5. Delete\n6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int data;
        switch(choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                t * newNode;
                newNode = (t*)malloc(sizeof(t));
                newNode->data = data;
                newNode->left = NULL;
                newNode->right = NULL;
                insert(&root, &newNode);
                break;
            case 2:
                inOrder(root);
                printf("\n");
                break;
            case 3:
                preOrder(root);
                printf("\n");
                break;
            case 4:
                postOrder(root);
                printf("\n");   
                break;
            case 5:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                delete(root, data);
                printf("\n%d is deleted", data);
                break;
            case 6: 
                exit(1);
        }
    }
    
    return 0;
}



