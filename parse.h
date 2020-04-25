/*
  May 8, 2018

  Header file for parse.c
*/

#include "trie.h"

#ifndef PARSE_H
#define PARSE_H

TrieNode *trieFromDict(FILE *file);
void parseInput(TrieNode *root);

#endif
