#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <string>
using namespace std;

struct BTNode {
	//Data
	string data;
	BTNode *left;
	BTNode *right;
	BTNode *morse_root;
	


	//Construct
	BTNode(string dataValue = "", BTNode *leftValue = NULL, BTNode *rightValue = NULL) {
		data = dataValue;
		left = leftValue;
		right = rightValue;
	}

	//Destruct
	~BTNode() {}
};

class BinaryTree  {
public:
	BTNode * root;

	//DEF constructor
	BinaryTree() { root = new BTNode();}

	//Non-DEF constructors
	BinaryTree(BTNode *newroot) { root = newroot;}

	BinaryTree(const string & data, const BinaryTree & left = BinaryTree(), const BinaryTree & right = BinaryTree()) {
		root = new BTNode(data, left.root, right.root);
	}

	//Member_Functi0ns
	BTNode* get_root() { return root;}
	void set_root(BTNode *data) { root = data;}
	BinaryTree get_left_subtree() { return BinaryTree(root->left);}
	BinaryTree get_right_subtree() { return BinaryTree(root->right);}
};

#endif