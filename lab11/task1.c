#include <stdio.h>
#include <stdlib.h>

/* -------------------------------------------------------
   AVL Tree — Task 01 (Right Rotation)
   Variable naming:
     root        : the node passed in (was 'y')
     leftChild   : root's left child (was 'x')
     orphan      : the subtree temporarily lost during
                   rotation — must be saved first (was 'T2')
     node        : generic node pointer in helpers
------------------------------------------------------- */

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
    struct Node *node  = (struct Node *) malloc(sizeof(struct Node));
    node->key    = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;    /* every new node starts as a leaf, height = 1 */
    return node;
}

/*
 * rightRotate — fixes the Left-Left imbalance case.
 *
 * Before:          After:
 *      root            leftChild
 *      /                /      \
 * leftChild          (left)    root
 *    /    \                    /
 * (left)  orphan           orphan
 *
 * 'orphan' is leftChild's right subtree. It becomes
 * root's new left child so no data is lost.
 */
struct Node *rightRotate(struct Node *root) {

    struct Node *leftChild = root->left;        /* step in as new root  */
    struct Node *orphan    = leftChild->right;  /* save before overwrite */

    /* --- perform the two pointer rewrites --- */
    leftChild->right = root;    /* leftChild adopts root as its right child */
    root->left       = orphan;  /* root adopts the orphaned subtree         */

    /* --- update heights bottom-up (root is now lower, so first) --- */
    root->height      = maxOf(getHeight(root->left),
                              getHeight(root->right)) + 1;

    leftChild->height = maxOf(getHeight(leftChild->left),
                              getHeight(leftChild->right)) + 1;

    return leftChild;   /* leftChild is the new root of this subtree */
}

/* Balance factor > 0 means left-heavy, < 0 means right-heavy */
int getBalance(struct Node *node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

/* Pre-order: root → left → right (useful for verifying structure) */
void preOrder(struct Node *node) {
    if (node == NULL) return;
    printf("%d (h=%d, BF=%d)  ", node->key, node->height, getBalance(node));
    preOrder(node->left);
    preOrder(node->right);
}

/* -------------------------------------------------------
   main — manually builds the LL-imbalanced tree:

         30          <-- imbalanced root (BF = +2)
        /
       20
      /
     10

   then calls rightRotate(30) and prints the result:

       20
      /  \
    10    30

   Expected pre-order: 20  10  30
------------------------------------------------------- */
int main() {

    /* Build the skewed tree by hand (no insert yet, that's Task 02) */
    struct Node *root      = newNode(30);
    root->left             = newNode(20);
    root->left->left       = newNode(10);

    /* Fix heights manually to match what insert would have set */
    root->left->left->height = 1;   /* 10 is a leaf               */
    root->left->height       = 2;   /* 20 has one child            */
    root->height             = 3;   /* 30 has a chain of two       */

    printf("=== Before rotation ===\n");
    printf("Pre-order: ");
    preOrder(root);
    printf("\n");
    printf("Root: %d  |  Balance factor: %d\n\n", root->key, getBalance(root));

    /* BF of root is +2 → LL case → right rotation */
    root = rightRotate(root);

    printf("=== After right rotation ===\n");
    printf("Pre-order: ");
    preOrder(root);
    printf("\n");
    printf("Root: %d  |  Balance factor: %d\n", root->key, getBalance(root));

    return 0;
}