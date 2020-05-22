/*
  Rogers Xiang
  May 8, 2018

  A trie is a multiway branching structure (tree) that stores the prefixes of sequences.
  As we travel down a path in the trie, we reach word sequences spelled out by the numbers
  along that path. This application uses a compressed trie: the digits 2-9 represent the 26 letters.

  index: returns T9 branch index corresponding to input letter
  newNode: creates new trie node
  insert: inserts given word into trie 
  search: searches trie for word corresponding to given sequence
  freeTrie: frees allocated memory for the trie
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

/* Internal function declarations */
int index(char letter);

/*Returns the T9 branch index for the given character.
  letter: must be lowercase letter
*/ 
int index(char letter) {
  switch (letter) {
    case 'a': case 'b': case 'c': return 0;  // case fall-through
    case 'd': case 'e': case 'f': return 1;
    case 'g': case 'h': case 'i': return 2;
    case 'j': case 'k': case 'l': return 3;
    case 'm': case 'n': case 'o': return 4;
    case 'p': case 'q': case 'r': case 's': return 5;
    case 't': case 'u': case 'v': return 6;
    case 'w': case 'x': case 'y': case 'z': return 7;
    case '#': return 8;
    default: return -1;  // shouldn't happen
  }
}

/*Creates a new TrieNode.
  The children and word fields are initialized to NULL.
*/
TrieNode *newNode() {
  TrieNode *node = (TrieNode*) malloc(sizeof(TrieNode));  // allocate memory
  if (node) {  // malloc might return null
    int i;
    for (i = 0; i < NUM_CHILDREN; ++i) {
      node->children[i] = NULL;
    }
    node->word = NULL;
  } else {
    fprintf(stderr, "t9: malloc failed\n");
  }
  return node;
}

/*Inserts a word into the trie.
  root: root node of the trie
  str: word to be inserted
*/
void insert(TrieNode *root, char *str) {
  char *copy;  // stores copy of str
  int length = strlen(str);  // str length
  int key;  // branch index
  int i;
  for (i = 0; i < length; ++i) {
    key = index(str[i]);
    if (root->children[key] == NULL) {
      root->children[key] = newNode();
    }
    root = root->children[key];
  }
  length += 1;  // for null-terminating character
  copy = (char*) malloc(length);
  if (copy) {  // malloc might return null
    strncpy(copy, str, length);
    if (root->word != NULL) {
      while (root->children[8] != NULL) {
        root = root->children[8];
      }
      root->children[8] = newNode();
      root = root->children[8];
    }
    root->word = copy;
  } else {
    fprintf(stderr, "t9: malloc failed\n");
  }
}

/*Returns the word associated with the given sequence.
  sequence: T9 key sequence to be searched
  root: root node of trie
*/
char *search(char *sequence, TrieNode *root) {
  static TrieNode *current = NULL;  // tracks current node
  int length = strlen(sequence);  // sequence length
  int key;  // branch index
  int i;
  if (current == NULL || sequence[0] != '#') {
    current = root;  // reset current
  }
  for (i = 0; i < length; ++i) {
    if (sequence[i] == '#') {
      key = 8;
      if (current->children[key] == NULL) {
        current = root;
        return "There are no more T9onyms.";
      }
      current = current->children[key];
    } else {
      key = sequence[i] - 2 - '0';  // ascii to int
      if (key < 0 || key > 7) {
        current = root;
        return "Not a valid input.";
      } else {
        if (current->children[key] == NULL) {
          current = root;
          return "Not found in current dictionary.";
        }
        current = current->children[key];
      }
    }
  }
  if (current->word == NULL) {
    return "Not found in current dictionary.";
  }
  return current->word;
}

/*Recursively frees all allocated memory for the trie. 
  root: root node of trie
*/
void freeTrie(TrieNode *root) {
  int i;
  for (i = 0; i < NUM_CHILDREN; ++i) {
    if (root->children[i] != NULL) {
      freeTrie(root->children[i]);
    }
  }
  if (root->word != NULL) {
    free(root->word);
  }
  free(root);
}
