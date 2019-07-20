#include "BinaryTree.h"

//8ms, 96.98%
//DFS, ºóÐò±éÀú, ×óÖÐÓÒ

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
	int res = -1;
	void DFS(TreeNode* root, int pmax, int pmin)
	{
		if (!root) return;
		else
		{
			res = max(res, abs(root->val - pmax));
			res = max(res, abs(root->val - pmin));
			pmax = max(pmax, root->val);
			pmin = min(pmin, root->val);
			DFS(root->left, pmax, pmin);
			DFS(root->right, pmax, pmin);
		}
	}

public:
	int maxAncestorDiff(TreeNode* root) {
		if (!root) return 0;
		else
		{
			DFS(root->left, root->val, root->val);
			DFS(root->right, root->val, root->val);
			return res;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->maxAncestorDiff(stringToTreeNode("[1,null,2,null,0,3]"));
	return 0;
}
*/
