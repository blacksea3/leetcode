#pragma once
#include "public.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* stringToTreeNode(string input);
void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true);

