#include "BinaryTree.h"

//traverse by level order, 8ms, 87.31%

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
public:
	vector<int> rightSideView(TreeNode* root) {
		//≤„–Ú±È¿˙
		vector<int> res;

		if (root == nullptr) return res;
		vector<TreeNode*> q;
		vector<TreeNode*> temp;
		q.push_back(root);
		while (!q.empty())
		{
			res.push_back(q[q.size() - 1]->val);
			temp.clear();
			for (auto iq : q)
			{
				if (iq->left) temp.push_back(iq->left);
				if (iq->right) temp.push_back(iq->right);
			}
			q.clear();
			q.assign(temp.begin(), temp.end());
		}
		return res;
	}
};
