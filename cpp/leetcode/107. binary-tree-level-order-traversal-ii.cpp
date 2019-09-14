#include "BinaryTree.h"

//4ms, 97.92%
//²ãÐò±éÀú, Ë«¶ÓÁÐ
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (root == nullptr) return vector<vector<int>> {};

		queue<TreeNode*> pre;
		queue<TreeNode*> next;

		vector<vector<int>> total_res;
		vector<int> pre_res;

		bool ist1valid = true;

		pre.push(root);

		while (!pre.empty())
		{
			pre_res.clear();
			while (!pre.empty())
			{
				TreeNode* temp = pre.front();
				pre.pop();
				pre_res.push_back(temp->val);
				if (temp->left) next.push(temp->left);
				if (temp->right) next.push(temp->right);
			}
			total_res.emplace_back(pre_res);
			swap(pre, next);
		}
		reverse(total_res.begin(), total_res.end());
		return total_res;
	}
};
