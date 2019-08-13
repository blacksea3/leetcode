#include "BinaryTree.h"

//60ms, 11.42%
//不受进阶限制, 直接暴力DFS

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
	unordered_map<int, int> count;
	void DFS(TreeNode* root)
	{
		if (!root) return;
		else
		{
			count[root->val]++;
			DFS(root->left);
			DFS(root->right);
		}
	}

public:
	vector<int> findMode(TreeNode* root) {
		DFS(root);

		vector<int> res;
		int resmaxfre = 0;

		for (auto& iter_count : count)
		{
			if (iter_count.second > resmaxfre)
			{
				res.clear();
				res.push_back(iter_count.first);
				resmaxfre = iter_count.second;
			}
			else if (iter_count.second == resmaxfre)
				res.push_back(iter_count.first);
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->findMode(stringToTreeNode("[1,null,2,2]"));
	return 0;
}
*/
