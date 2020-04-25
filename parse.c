/*
  Rogers Xiang
  May 8, 2018

  The following functions parse file and user input for the t9 program.
  trieFromDict: creates a trie from the input dictionary file
  parseInput: runs an interactive session for user input
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"
#include "trie.h"

#define MAXLINE 20  // maximum line size

/*Builds the trie and returns the root node.
  file: dictionary containing words to be inserted.
*/ 
TrieNode* trieFromDict(FILE* file) {
  char line[MAXLINE + 1];  // stores line
  TrieNode *root = newNode();
  while (fgets(line, MAXLINE, file) != NULL) {
    line[strcspn(line, "\n")] = 0;  // remove newline character
    insert(root, line);
  }
  return root;
}

/*Parses user input sequence and searches the trie for the
  corresponding word. If the user then enters '#', the next
  word in the tree with the same numeric value is printed.
  The user can also enter a number followed by one or more
  '#' characters to achieve the same result.
  root: root node of the trie
*/
void parseInput(TrieNode *root) {
  char input[MAXLINE + 1];  // plus one for null terminating character
  printf("Enter \"exit\" to quit.\n");
  while (1) {
    printf("Enter Key Sequence (or \"#\" for next word)\n");
    scanf("%s", input);
    if (strncmp(input, "exit", 4) == 0) {
      break;
    } else {
      printf("%s\n", search(input, root));
    }
  }
}
