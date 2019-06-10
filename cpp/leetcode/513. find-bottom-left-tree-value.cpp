#include "BinaryTree.h"

//16ms, 97.78%

//DFS, Levelorder
//problem say that root will not be NULL

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
	int res = 0;
	void recu_findnextlevel(queue<TreeNode*>& preroot)
	{
		queue<TreeNode*> nextlevel;
		int preleftestval = preroot.front()->val;

		while (!preroot.empty())
		{
			TreeNode* r = preroot.front();
			preroot.pop();
			if (r->left) nextlevel.push(r->left);
			if (r->right) nextlevel.push(r->right);
		}
		if (nextlevel.empty()) res = preleftestval;
		else recu_findnextlevel(nextlevel);
	}

public:
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> r;
		r.push(root);
		recu_findnextlevel(r);
		return res;
	}
};
