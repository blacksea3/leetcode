#include "BinaryTree.h"

//12ms, 97.57%
//ÏÈÐò±éÀú, µÝ¹é
class Solution {
public:
	int* last = NULL;
	bool isValidBST(TreeNode* root) {
		if (root) {
			if (!isValidBST(root->left)) return false;
			if (last && *last >= root->val) return false;
			last = &root->val;
			if (!isValidBST(root->right)) return false;
			return true;
		}
		else return true;
	}
};

/*
int main()
{
	TreeNode* root = stringToTreeNode("[10,5,15,null,null,6,20]");
	prettyPrintTree(root);
	Solution* s = new Solution();
	cout << s->isValidBST(root);
	return 0;
}
*/
