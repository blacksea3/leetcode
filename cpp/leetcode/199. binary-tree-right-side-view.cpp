#include "BinaryTree.h"

//4ms, 92.11%
//层序遍历, 层间反向

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			queue<TreeNode*> ne;
			res.push_back(q.front()->val);
			while (!q.empty())
			{
				TreeNode* temp = q.front();
				q.pop();
				if (temp->right) ne.push(temp->right);
				if (temp->left) ne.push(temp->left);
			}
			q = ne;
		}
		return res;
	}
};
