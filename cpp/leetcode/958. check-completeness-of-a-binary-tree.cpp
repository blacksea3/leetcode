#include "BinaryTree.h"

//20ms, 10.53%
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
	bool isCompleteTree(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		bool isfull = true;

		while (!q.empty())
		{
			queue<TreeNode*> next;

			while (!q.empty())
			{
				if (isfull)
				{
					if (q.front()->left)
					{
						next.push(q.front()->left);
						if (q.front()->right)
						{
							next.push(q.front()->right);
						}
						else isfull = false;
					}
					else
					{
						if (q.front()->right) return false;
						else isfull = false;
					}
				}
				else
				{
					if (q.front()->left) return false;
					if (q.front()->right) return false;
				}
				q.pop();
			}
			q = next;
		}
		return true;
	}
};
