/*
  May 8, 2018

  Header file for trie.c
*/

#ifndef TRIE_H
#define TRIE_H

#define NUM_CHILDREN 9  // number of branches for trie node

typedef struct TrieNode {
  struct TrieNode* children[NUM_CHILDREN];
  char *word;
} TrieNode;

TrieNode *newNode();
void insert(TrieNode *root, char *str);
char *search(char *sequence, TrieNode *root);
void freeTrie(TrieNode *root);

#endif
