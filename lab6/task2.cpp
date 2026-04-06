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

struct Node *search(struct Node *root, int key) {
    if (root == NULL)
        return NULL;
    
    if (key == root->data)
        return root;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct Node *findMin(struct Node *root) {
    if (root == NULL)
        return NULL;
    
    while (root->left != NULL)
        root = root->left;
    
    return root;
}

struct Node *findMax(struct Node *root) {
    if (root == NULL)
        return NULL;
    
    while (root->right != NULL)
        root = root->right;
    
    return root;
}

struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return NULL;
    
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        
        if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node *successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    
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

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, val, key;
    struct Node *result;
    
    while (1) {
        printf("\n=== BST Menu ===\n");
        printf("1. Insert a value\n");
        printf("2. Search for a value\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Delete a value\n");
        printf("6. In-Order Traversal\n");
        printf("7. Pre-Order Traversal\n");
        printf("8. Post-Order Traversal\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Value inserted successfully!\n");
                break;
            
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                result = search(root, key);
                if (result != NULL)
                    printf("Value %d found in the tree!\n", key);
                else
                    printf("Value %d not found in the tree.\n", key);
                break;
            
            case 3:
                result = findMin(root);
                if (result != NULL)
                    printf("Minimum value: %d\n", result->data);
                else
                    printf("Tree is empty!\n");
                break;
            
            case 4:
                result = findMax(root);
                if (result != NULL)
                    printf("Maximum value: %d\n", result->data);
                else
                    printf("Tree is empty!\n");
                break;
            
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("Value deleted successfully!\n");
                break;
            
            case 6:
                printf("In-Order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            
            case 7:
                printf("Pre-Order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            
            case 8:
                printf("Post-Order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            
            case 9:
                printf("Exiting...\n");
                return 0;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
