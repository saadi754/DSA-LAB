#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

/* Returns 0 for NULL, otherwise the stored height */
int getHeight(struct Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

int maxOf(int a, int b) {
    return (a > b) ? a : b;
}

struct Node *newNode(int key) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->key    = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;   /* every new node starts as a leaf */
    return node;
}

/* Balance factor > 0 means left-heavy, < 0 means right-heavy */
int getBalance(struct Node *node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

/* -------------------------------------------------------
   TASK 01 — rightRotate
   Fixes the Left-Left (LL) imbalance case.

   Before:          After:
        root           leftChild
        /               /      \
   leftChild         (left)    root
      /    \                   /
   (left)  orphan           orphan
------------------------------------------------------- */
struct Node *rightRotate(struct Node *root) {

    struct Node *leftChild = root->left;        /* steps up as new root  */
    struct Node *orphan    = leftChild->right;  /* save before overwrite */

    leftChild->right = root;    /* leftChild adopts root as right child */
    root->left       = orphan;  /* root adopts the orphaned subtree     */

    /* update heights bottom-up: root is now lower, so update it first */
    root->height      = maxOf(getHeight(root->left),
                              getHeight(root->right)) + 1;
    leftChild->height = maxOf(getHeight(leftChild->left),
                              getHeight(leftChild->right)) + 1;

    return leftChild;   /* leftChild is the new root of this subtree */
}

/* -------------------------------------------------------
   TASK 02a — leftRotate
   Fixes the Right-Right (RR) imbalance case.
   Mirror image of rightRotate.

   Before:        After:
     root           rightChild
        \            /       \
    rightChild     root     (right)
      /    \          \
   orphan  (right)   orphan
------------------------------------------------------- */
struct Node *leftRotate(struct Node *root) {

    struct Node *rightChild = root->right;       /* steps up as new root  */
    struct Node *orphan     = rightChild->left;  /* save before overwrite */

    rightChild->left = root;    /* rightChild adopts root as left child */
    root->right      = orphan;  /* root adopts the orphaned subtree     */

    /* update heights bottom-up: root is now lower, so update it first */
    root->height       = maxOf(getHeight(root->left),
                               getHeight(root->right)) + 1;
    rightChild->height = maxOf(getHeight(rightChild->left),
                               getHeight(rightChild->right)) + 1;

    return rightChild;  /* rightChild is the new root of this subtree */
}

/* -------------------------------------------------------
   TASK 02b — insert
   Standard BST insert + AVL rebalancing on the way back up.

   Each call returns the (possibly new) root of its subtree,
   so the parent updates its own pointer automatically:
       node->left = insert(node->left, key)
------------------------------------------------------- */
struct Node *insert(struct Node *node, int key) {

    /* 1. standard BST insert */
    if (node == NULL)
        return newNode(key);        /* empty slot found — place it here */

    if (key < node->key)
        node->left  = insert(node->left,  key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;                /* duplicate — ignore */

    /* 2. update this ancestor's height on the way back up */
    node->height = maxOf(getHeight(node->left),
                         getHeight(node->right)) + 1;

    /* 3. check balance factor at this node */
    int balance = getBalance(node);

    /* 4. four rotation cases */

    /* LL case: left-heavy AND new key went into left child's LEFT side */
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    /* RR case: right-heavy AND new key went into right child's RIGHT side */
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    /* LR case: left-heavy AND new key went into left child's RIGHT side
       Fix: left-rotate the left child first, then right-rotate this node */
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    /* RL case: right-heavy AND new key went into right child's LEFT side
       Fix: right-rotate the right child first, then left-rotate this node */
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;    /* no imbalance at this node */
}

/* Pre-order: root -> left -> right */
void preOrder(struct Node *node) {
    if (node == NULL) return;
    printf("%d ", node->key);
    preOrder(node->left);
    preOrder(node->right);
}

/* Same traversal but with height and BF for debugging */
void preOrderDetailed(struct Node *node) {
    if (node == NULL) return;
    printf("  key=%-4d  height=%d  BF=%+d\n",
           node->key, node->height, getBalance(node));
    preOrderDetailed(node->left);
    preOrderDetailed(node->right);
}

/* -------------------------------------------------------
   main
   Inserts 10, 20, 30, 40, 50, 25 as required by the lab.
   Correct pre-order output: 30 20 10 25 40 50
------------------------------------------------------- */
int main() {

    struct Node *root = NULL;

    int keys[] = {10, 20, 30, 40, 50, 25};
    int n      = sizeof(keys) / sizeof(keys[0]);

    printf("Inserting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", keys[i]);
        root = insert(root, keys[i]);
    }
    printf("\n\n");

    printf("Pre-order (keys only): ");
    preOrder(root);
    printf("\n");
    printf("Expected:              30 20 10 25 40 50\n\n");

    printf("Pre-order (detailed):\n");
    preOrderDetailed(root);

    return 0;
}