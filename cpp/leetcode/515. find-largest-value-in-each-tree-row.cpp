#include "BinaryTree.h"

//24ms, 94.86%

//DFS, Levelorder

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
	vector<int> res = {};
	void recu_findnextlevel(queue<TreeNode*>& preroot)
	{
		queue<TreeNode*> nextlevel;
		int prebiggestval = INT_MIN;

		while (!preroot.empty())
		{
			TreeNode* r = preroot.front();
			prebiggestval = max(prebiggestval, r->val);
			preroot.pop();
			if (r->left) nextlevel.push(r->left);
			if (r->right) nextlevel.push(r->right);
		}
		res.push_back(prebiggestval);
		if (nextlevel.empty()) return;
		else recu_findnextlevel(nextlevel);
	}

public:
	vector<int> largestValues(TreeNode* root) {
		if (root == nullptr) return res;
		queue<TreeNode*> r;
		r.push(root);
		recu_findnextlevel(r);
		return res;
	}
};
