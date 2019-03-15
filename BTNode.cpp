#include "stdafx.h"
#include "BTNode.h"

BTNode:: BTNode() {

}

BTNode::BTNode(const string& theData, BTNode* leftVal, BTNode* rightVal) {
	leftVal = NULL;
	rightVal = NULL;
}