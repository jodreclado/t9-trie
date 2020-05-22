# T9 trie

T9 predictive text is a text input mode used by numeric keypads. Each number from 2-9 represents three or four letters, the number 0 represents a space, and 1 represents a set of symbols such as { , . ! ? }.

A data structure known as a trie is used to translate number sequences to words. A trie is a multiway branching structure (tree) that stores the prefixes of sequences. As we travel down a path in the trie, we reach word sequences spelled out by the numbers along that path. 

The command

     $ ./t9 FILE

should read in a dictionary file (FILE) that contains a list of words. Each word in the dictionary is translated into its numeric key sequence and added to the trie, with the word stored at the end of the path. 

This program uses a compressed trie that has only 9 possible branches at each node instead of 26, since the digits 2-9 represent the 26 letters. If a word with the same numeric sequence already exists in the trie, the new word is added to the trie as a link to a new node with an edge labeled '#'. 

* 2 => ABC
* 3 => DEF
* 4 => GHI
* 5 => JKL
* 6 => MNO
* 7 => PQRS
* 8 => TUV
* 9 => WXYZ

![Example Trie](./exampleTrie.jpg?raw=true)




