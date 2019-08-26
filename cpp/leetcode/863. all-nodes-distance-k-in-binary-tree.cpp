#include "BinaryTree.h"

//12ms, 78.31%
//将二叉树转成图, 然后BFS

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
	vector<vector<int>> nexts;
	void DFS(TreeNode* root, int parent)
	{
		if (parent == -1)
		{
			if (!root->left && !root->right)
			{
				return;
			}
			else if (!root->left)
			{
				nexts[root->val].push_back(root->right->val);
				DFS(root->right, root->val);
			}
			else if (!root->right)
			{
				nexts[root->val].push_back(root->left->val);
				DFS(root->left, root->val);
			}
			else
			{
				nexts[root->val].push_back(root->right->val);
				DFS(root->right, root->val);
				nexts[root->val].push_back(root->left->val);
				DFS(root->left, root->val);
			}
		}
		else
		{
			nexts[root->val].push_back(parent);
			if (!root->left && !root->right)
			{
				return;
			}
			else if (!root->left)
			{
				nexts[root->val].push_back(root->right->val);
				DFS(root->right, root->val);
			}
			else if (!root->right)
			{
				nexts[root->val].push_back(root->left->val);
				DFS(root->left, root->val);
			}
			else
			{
				nexts[root->val].push_back(root->right->val);
				DFS(root->right, root->val);
				nexts[root->val].push_back(root->left->val);
				DFS(root->left, root->val);
			}
		}
	}

public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		nexts.resize(501);
		DFS(root, -1);
		vector<int> res;
		if (K == 0) return { target->val };
		else
		{
			//BFS
			vector<int> pre;
			vector<int> searched;
			pre.push_back(target->val);
			while (K-- > 0)
			{
				vector<int> next;
				for (auto& a : pre)
				{
					searched.push_back(a);
					for (auto& n : nexts[a])
					{
						if (find(searched.begin(), searched.end(), n) == searched.end())
						{
							next.push_back(n);
						}
					}
				}
				pre = next;
			}
			return pre;
		}
	}
};

