#include "BinaryTree.h"

//40ms, 72.93%

//DC problem
//traverse the may occur n, then the n->left must include these numbers less than n;
// the n->right must include these numbers bigger than n

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
	//ensure that m>= n
	vector<TreeNode*> iter_gen_trees(int n, int m)
	{
		if (n == m)
		{
			TreeNode *tn = new TreeNode(n);
			return vector<TreeNode*> {tn};
		}
		else
		{
			//root: from n to m, left from None,n,n+1..n to m-1
			//right from n+1....m to None
			vector<TreeNode*> res;
			//left None
			vector<TreeNode*> leftnull_sons = iter_gen_trees(n + 1, m);
			for (auto ln : leftnull_sons)
			{
				TreeNode* leftnull = new TreeNode(n);
				leftnull->right = ln;
				res.push_back(leftnull);
			}
			//right None
			vector<TreeNode*> rightnull_sons = iter_gen_trees(n, m - 1);
			for (auto rn : rightnull_sons)
			{
				TreeNode* rightnull = new TreeNode(m);
				rightnull->left = rn;
				res.push_back(rightnull);
			}
			//others
			for (int i = n + 1; i <= m - 1; i++)
			{
				vector<TreeNode*> leftsons = iter_gen_trees(n, i - 1);
				vector<TreeNode*> rightsons = iter_gen_trees(i + 1, m);
				for (auto left : leftsons)
					for (auto right : rightsons)
					{
						TreeNode* bothside = new TreeNode(i);
						bothside->left = left;
						bothside->right = right;
						res.push_back(bothside);
					}
			}
			return res;
		}
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		if (n <= 0) return vector<TreeNode*> {};

		return iter_gen_trees(1, n);
	}
};


