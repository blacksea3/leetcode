#include "BinaryTree.h"

//36ms, 26.56%
//±©Á¦DFS

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
	vector<int> vres = { 27 };
	void update_vres(const vector<int>& nv)
	{
		int loc1 = vres.size() - 1;
		int loc2 = nv.size() - 1;
		while (loc1 >= 0 && loc2 >= 0)
		{
			if (vres[loc1] > nv[loc2])
			{
				vres = nv;
				break;
			}
			else if (vres[loc1] < nv[loc2])
			{
				break;
			}
			else
			{
				loc1--;
				loc2--;
			}
		}
		if (loc2 == -1) vres = nv;
	}

	void DFS(TreeNode* root, vector<int> prev)
	{
		if (!root) return;
		prev.push_back(root->val);
		if (!root->left && !root->right)
			update_vres(prev);
		else
		{
			DFS(root->left, prev);
			DFS(root->right, prev);
		}
	}

public:
	string smallestFromLeaf(TreeNode* root) {
		DFS(root, {});
		string r;
		for (int i = vres.size() - 1; i >= 0; --i)
			r += vres[i] - 0 + 'a';
		return r;
	}
};
