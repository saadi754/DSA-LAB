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
    struct TrieNode *currentNode = root;  // Pointer that crawls/traverses through the tree
    for (int charIndex = 0; charIndex < strlen(word); charIndex++) {
        int alphabetIndex = word[charIndex] - 'a';  // 'a'->0, 'b'->1, ..., 'z'->25
        if (!currentNode->children[alphabetIndex])
            currentNode->children[alphabetIndex] = getNode();
        currentNode = currentNode->children[alphabetIndex];  // Move to next node
    }
    currentNode->isEndOfWord = true;  // Mark the final node as end of a complete word
}

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

int main(void) {
    struct TrieNode *root = getNode();
    
    // Test words
    const char *words[] = {"hello", "world", "hi", "have", "head", "hear"};
    int numWords = sizeof(words) / sizeof(words[0]);
    
    // Insert words
    printf("Inserting words into Trie...\n");
    for (int i = 0; i < numWords; i++) {
        insert(root, words[i]);
        printf("Inserted: %s\n", words[i]);
    }
    
    printf("\n--- Testing Search ---\n");
    
    // Test search
    const char *searchWords[] = {"hello", "world", "hi", "hey", "hear", "hel", "app"};
    int numSearches = sizeof(searchWords) / sizeof(searchWords[0]);
    
    for (int i = 0; i < numSearches; i++) {
        if (search(root, searchWords[i]))
            printf("'%s' - FOUND\n", searchWords[i]);
        else
            printf("'%s' - NOT FOUND\n", searchWords[i]);
    }
    
    return 0;
}
