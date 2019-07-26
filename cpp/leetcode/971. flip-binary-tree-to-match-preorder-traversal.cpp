#include "BinaryTree.h"

//12ms, 52.78%
//混合DFS
//考虑以下的操作:同时推进voyage和root,
//如果voyage的下一个值不等于root->left->val或root->right->val则完蛋了
//若等于root->left->val, 则ok
//等于root->right则相反, res++

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
	vector<int> res;
	bool fail = false;

	void DFS(TreeNode* root, const vector<int>& voyage, int& loc)
	{
		if (fail) return;
		if (!root || root->val != voyage[loc]) //长度不符合, 但算法逻辑上不会到这里
		{
			res.clear();
			res.push_back(-1);
			fail = true;
		}
		else
		{
			loc++;
			if (loc == voyage.size() && (root->left || root->right))
			{
				res.clear();
				res.push_back(-1);
				fail = true;
			}
			else if (root->left && root->right)
			{
				if (root->left->val == voyage[loc])
				{
					DFS(root->left, voyage, loc);
					DFS(root->right, voyage, loc);
				}
				else if (root->right->val == voyage[loc])
				{
					res.push_back(root->val);
					DFS(root->right, voyage, loc);
					DFS(root->left, voyage, loc);
				}
				else
				{
					res.clear();
					res.push_back(-1);
					fail = true;
				}
			}
			else if (root->left)
			{
				if (root->left->val == voyage[loc])
				{
					DFS(root->left, voyage, loc);
				}
				else
				{
					res.clear();
					res.push_back(-1);
					fail = true;
				}
			}
			else if (root->right)
			{
				if (root->right->val == voyage[loc])
				{
					DFS(root->right, voyage, loc);
				}
				else
				{
					res.clear();
					res.push_back(-1);
					fail = true;
				}
			}
		}
	}

public:
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		if (root->val != voyage[0]) return { -1 };
		else
		{
			int loc = 0;
			DFS(root, voyage, loc);
			if (loc == voyage.size()) return res;
			else return { -1 };
		}
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<int> voyage = { 1,3,2 };
	//auto res = s->flipMatchVoyage(stringToTreeNode("[1,2,3]"), voyage);
	//vector<int> voyage = { 5,2,3,4,1 };
	//auto res = s->flipMatchVoyage(stringToTreeNode("[5, 1, 2, null, null, 4, 3]"), voyage);
	
	vector<int> voyage = { 8,9,12,29,42,50,41,34,48,26,25,49,31,11,13,38,43,24,28,46,6,45,1,37,40,22,27,33,44,47,30,2,32,35,19,23,16,5,3,39,20,36,21,17,4,14,15,18,7,10 };
	TreeNode* root = stringToTreeNode("[8, 9, 4, 12, 46, 7, 14, 48, 29, 6, 37, 10, null, null, 15, 26, 3, 50, 42, 45, null, 17, 40, null, null, 18, null, null, 25, 11, 31, 41, null, null, null, 1, null, null, null, 22, 19, null, null, null, null, 13, null, null, null, null, 34, null, null, 27, null, 23, null, 28, 38, null, null, 33, null, 16, 20, null, null, 43, null, 44, 35, 5, 49, 21, 36, 24, null, 2, 47, null, null, null, null, null, 39, null, null, null, null, null, null, null, 32, null, 30]");
	prettyPrintTree(root);
	auto res = s->flipMatchVoyage(root, voyage);

	return 0;
}
