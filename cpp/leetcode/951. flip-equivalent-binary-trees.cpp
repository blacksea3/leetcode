#include "BinaryTree.h"

//8ms, 66.67%
//同时DFS
//如果俩root的左右反的, 那么反过来DFS, 否则正着DFS

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
	bool res = true;
	void DFS(TreeNode* root1, TreeNode* root2)
	{
		if (!res) return;
		if (root1->left && root2->left && root1->left->val == root2->left->val)
		{
			if (root1->right && root2->right && root1->right->val == root2->right->val)
			{
				DFS(root1->left, root2->left);
				DFS(root1->right, root2->right);
			}
			else if (!root1->right && !root2->right)
			{
				DFS(root1->left, root2->left);
			}
			else res = false;
		}
		else if (root1->right && root2->right && root1->right->val == root2->right->val)
		{
			if (!root1->left && !root2->left)
			{
				DFS(root1->right, root2->right);
			}
			else res = false;
		}
		else if (root1->left && root2->right && root1->left->val == root2->right->val)
		{
			if (root1->right && root2->left && root1->right->val == root2->left->val)
			{
				DFS(root1->left, root2->right);
				DFS(root1->right, root2->left);
			}
			else if (!root1->right && !root2->left)
			{
				DFS(root1->left, root2->right);
			}
			else res = false;
		}
		else if (root1->right && root2->left && root1->right->val == root2->left->val)
		{
			if (!root1->left && !root2->right)
			{
				DFS(root1->right, root2->left);
			}
			else res = false;
		}
		else if (!root1->left && !root2 ->left && !root1->right && !root2->right)
		{
			;
		}
		else res = false;
	}


public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if (!root1 && !root2) return true;
		else if (root1 && root2 && root1->val == root2->val)
		{
			DFS(root1, root2);
			return res;
		}
		else return false;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->flipEquiv(stringToTreeNode("[1,2,3,4,5,6,null,null,null,7,8]"), stringToTreeNode("[1,3,2,null,6,4,5,null,null,null,null,8,7]"));
	return 0;
}
*/
