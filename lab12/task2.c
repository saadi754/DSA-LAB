#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void) {
    struct TrieNode *newNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    newNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        newNode->children[i] = NULL;
    return newNode;
}

void insert(struct TrieNode *root, const char *word) {
    struct TrieNode *currentNode = root;
    for (int charIndex = 0; charIndex < strlen(word); charIndex++) {
        int alphabetIndex = word[charIndex] - 'a';
        if (!currentNode->children[alphabetIndex])
            currentNode->children[alphabetIndex] = getNode();
        currentNode = currentNode->children[alphabetIndex];
    }
    currentNode->isEndOfWord = true;
}

// Task 1: Exact Search Function
bool search(struct TrieNode *root, const char *word) {
    struct TrieNode *currentNode = root;
    for (int charIndex = 0; charIndex < strlen(word); charIndex++) {
        int alphabetIndex = word[charIndex] - 'a';
        if (!currentNode->children[alphabetIndex])
            return false;
        currentNode = currentNode->children[alphabetIndex];
    }
    return currentNode->isEndOfWord;
}

// Task 2: Prefix Validation
bool startsWith(struct TrieNode *root, const char *prefix) {
    struct TrieNode *currentNode = root;
    for (int charIndex = 0; charIndex < strlen(prefix); charIndex++) {
        int alphabetIndex = prefix[charIndex] - 'a';
        if (!currentNode->children[alphabetIndex])
            return false;
        currentNode = currentNode->children[alphabetIndex];
    }
    return true;
}

// Task 3: DFS Autocomplete Engine
void autocompleteDFS(struct TrieNode *node, char *buffer, int bufferLength) {
    if (node->isEndOfWord) {
        printf("  %s\n", buffer);
    }
    
    for (int alphabetIndex = 0; alphabetIndex < ALPHABET_SIZE; alphabetIndex++) {
        if (node->children[alphabetIndex] != NULL) {
            buffer[bufferLength] = 'a' + alphabetIndex;
            buffer[bufferLength + 1] = '\0';
            autocompleteDFS(node->children[alphabetIndex], buffer, bufferLength + 1);
        }
    }
}

// Autocomplete wrapper function
void autocomplete(struct TrieNode *root, const char *prefix) {
    struct TrieNode *currentNode = root;
    
    // Traverse to the end of the prefix
    for (int charIndex = 0; charIndex < strlen(prefix); charIndex++) {
        int alphabetIndex = prefix[charIndex] - 'a';
        if (!currentNode->children[alphabetIndex]) {
            printf("No words found with prefix '%s'\n", prefix);
            return;
        }
        currentNode = currentNode->children[alphabetIndex];
    }
    
    // Start DFS from this node
    char buffer[100];
    strcpy(buffer, prefix);
    printf("Autocomplete suggestions for '%s':\n", prefix);
    autocompleteDFS(currentNode, buffer, strlen(prefix));
}

int main(void) {
    struct TrieNode *root = getNode();
    
    // Build dictionary
    const char *dictionary[] = {"algorithm", "algo", "alien", "all", "apple", "app", "application"};
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);
    
    printf("=== Building Dictionary ===\n");
    for (int i = 0; i < dictSize; i++) {
        insert(root, dictionary[i]);
        printf("Inserted: %s\n", dictionary[i]);
    }
    
    printf("\n=== Testing Search Function ===\n");
    
    // Test 1: Search for "algo" (should return True)
    const char *searchKey1 = "algo";
    if (search(root, searchKey1))
        printf("search('%s'): TRUE - Word found\n", searchKey1);
    else
        printf("search('%s'): FALSE - Word not found\n", searchKey1);
    
    // Test 2: Search for "al" (should return False - it's just a prefix)
    const char *searchKey2 = "al";
    if (search(root, searchKey2))
        printf("search('%s'): TRUE - Word found\n", searchKey2);
    else
        printf("search('%s'): FALSE - It's just a prefix, not a complete word\n", searchKey2);
    
    printf("\n=== Testing Prefix Validation ===\n");
    
    // Bonus: Test startsWith
    const char *prefix1 = "ap";
    if (startsWith(root, prefix1))
        printf("startsWith('%s'): TRUE\n", prefix1);
    else
        printf("startsWith('%s'): FALSE\n", prefix1);
    
    printf("\n=== Testing Autocomplete Engine ===\n");
    printf("\n");
    // Test 3: Autocomplete for "app"
    autocomplete(root, "app");
    
    printf("\n");
    // Bonus: Autocomplete for "al"
    autocomplete(root, "al");
    
    printf("\n");
    // Bonus: Autocomplete for "algo"
    autocomplete(root, "algo");
    
    return 0;
}
