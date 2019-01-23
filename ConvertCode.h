#ifndef CONVERTCODE_H_
#define CONVERTCODE_H_
#include "MorseTree.h"
//#include "BinaryTree.h"
#include "HashTable.h"

class Convert_Code {
private:
	BTNode getRoot;
	MorseTree morse_tree;	//MorseTree for decoding
	HashTable morse_hash;//encoding
public:
	//Default constructor

	Convert_Code() { morse_tree = MorseTree(); getRoot = BTNode(); }

	//Member Functions
	void parse();
	string search(BTNode *node, string in);
	string decode(string in);
	string encode(string in);

};

#endif

