#include "BinaryTree.h"

//Traverse together is ok, 87.70%

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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		vector<TreeNode*> stackp = {};
		vector<TreeNode*> stackq = {};
		TreeNode *prep = p;
		TreeNode *preq = q;

		while (true)
		{
			//border input
			if ((prep == nullptr) && (stackp.empty()))
				if ((preq == nullptr) && (stackq.empty())) break;
				else return false;
			else if ((preq == nullptr) && (stackq.empty())) return false;
			else
			{
				if ((preq != nullptr) && (prep != nullptr))
				{
					stackp.push_back(prep);
					stackq.push_back(preq);
					prep = prep->left;
					preq = preq->left;
				}
				else if ((preq == nullptr) && (prep == nullptr))
				{
					//backtracking
					prep = stackp[stackp.size() - 1];
					preq = stackq[stackq.size() - 1];
					if ((prep->val) != (preq->val)) return false;

					stackp.pop_back();
					stackq.pop_back();

					prep = prep->right;
					preq = preq->right;
				}
				else return false;
			}
		}
		return true;
	}
};