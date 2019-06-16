#include "BinaryTree.h"

//36ms, 80.16%

//DFS problem
// double recursively solve it

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	int recu_path(TreeNode* root, int target)
	{
		if (!root) return 0;
		int res;
		if (root->val == target) res = 1;
		else res = 0;
		res += recu_path(root->left, target - root->val);
		res += recu_path(root->right, target - root->val);
		return res;
	}

public:
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		return recu_path(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
};

int main()
{
	Solution* s = new Solution();
	TreeNode* root = stringToTreeNode("[1,null,2,null,3]");
	prettyPrintTree(root);
	cout << s->pathSum(root, 3);
	return 0;
}