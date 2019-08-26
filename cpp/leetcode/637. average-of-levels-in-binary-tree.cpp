#include "BinaryTree.h"

//16ms, 99.82%
//≤„–Ú±È¿˙

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
	vector<double> averageOfLevels(TreeNode* root) {
		if (!root) return {};
		else
		{
			queue<TreeNode*> treeQueue;
			treeQueue.push(root);

			vector<double> res;
			while (!treeQueue.empty())
			{
				double sum = 0.0;
				double count = 0.0;
				queue<TreeNode*> next;
				while (!treeQueue.empty())
				{
					TreeNode* treePre = treeQueue.front();
					treeQueue.pop();
					sum += treePre->val;
					count += 1.0;
					if (treePre->left) next.push(treePre->left);
					if (treePre->right) next.push(treePre->right);
				}
				res.push_back(sum / count);
				treeQueue = next;
			}
			return res;
		}
	}
};
