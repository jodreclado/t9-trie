/*
  Rogers Xiang
  May 8, 2018

  The command
     $ ./t9 FILE
  should read in a dictionary file (FILE) that contains a list of words. Each word
  in the dictionary is translated into its numeric T9 key sequence, and then added
  to a trie, with the word at the end of the path corresponding to the digits.
  If a word with the same numeric sequence already exists in the trie, the new word
  is added as a link to the new node with an edge labeled '#' instead of one of the
  digits 2-9.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "parse.h"

int main(int argc, char *argv[]) {
  FILE *fp;  // pointer to dictionary file
  TrieNode *root;  // root node of trie
  if (argc != 2) {
    fprintf(stderr, "t9: takes one and only one argument\n");
    return EXIT_FAILURE;
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "t9: unable to open %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  root = trieFromDict(fp);
  parseInput(root);
  freeTrie(root);
  fclose(fp);
  return EXIT_SUCCESS;
}
