#ifndef MORSETREE_H_
#define MORSETREE_H_
#include "BinaryTree.h"
#include <string>
#include <fstream>


class MorseTree {
private:
public:
	//Default constructor 
	MorseTree() { 

		BinaryTree();
	}

	//Member funtions
	BTNode* rtrnRoot(BTNode* get_root()) { return 0;}

	void add_letter(BTNode * node,  std::string code, std::string letter) {
		//Add the letter to tree from morse.txt 
		if (node == NULL) {
			node = new BTNode();
		}
		if (code.size() == 0) {
			node->data = letter;
		}
		else if (code[0] == '.') {
			add_letter(node->left, code.substr(1), letter);
		}
		else if (code[0] == '_') {
			add_letter(node->right, code.substr(1), letter);
		}
	}
	
};
#endif
