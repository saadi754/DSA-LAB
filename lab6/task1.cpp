#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int val) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *root, int val) {
    if (root == NULL)
        return createNode(val);
    
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    
    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


int main() {
    struct Node *root = NULL;
    
    root = insert(root, 50);
    insert(root, 300);
    insert(root, 20);
    insert(root, 40);
    insert(root, 700);
    insert(root, 60);
    insert(root, 80);
    
    printf("In-Order Traversal yields:\n");
    inorder(root);
    printf("\n");
    printf("pre-order traversal \n");
    preorder(root);
    printf("\n");
    
    
    return 0;
}
