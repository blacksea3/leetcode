#include "BinaryTree.h"

/*
//4ms, 83.50%
//栈, 左中右, 迭代法

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res = {};
		stack<TreeNode*> ts;
		TreeNode* pre = root;
		while ((pre != nullptr) || !ts.empty())
		{
			if (pre != nullptr)
			{
				ts.push(pre);
				pre = pre->left;
			}
			else
			{
				pre = ts.top();
				ts.pop();
				res.push_back(pre->val);
				pre = pre->right;
			}
		}
		return res;
	}
};
*/

//0ms, 100%
//左中右, 递归写法
//层数不能超过最大递归深度

class Solution {
private:
	void Inorder(TreeNode* root, vector<int>& res)
	{
		if (!root) return;
		Inorder(root->left, res);
		res.emplace_back(root->val);
		Inorder(root->right, res);
	}

public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		Inorder(root, res);
		return res;
	}
};
