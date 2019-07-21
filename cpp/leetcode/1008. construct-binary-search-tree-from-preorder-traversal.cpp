#include "BinaryTree.h"

//
//ջ

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
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		TreeNode* root = new TreeNode(preorder[0]);
		TreeNode* pre = root;

		int loc = 1;
		stack<TreeNode*> st;
		st.push(pre);
		while (loc < preorder.size())
		{
			if (preorder[loc] < st.top()->val)
			{
				st.top()->left = new TreeNode(preorder[loc]);
				st.push(st.top()->left);
			}
			else
			{
				TreeNode* temp = st.top();
				while (!st.empty() && st.top()->val < preorder[loc])
				{
					temp = st.top();
					st.pop();
				}
				temp->right = new TreeNode(preorder[loc]);
				st.push(temp->right);
			}
			loc++;
		}
		return root;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> p = { 8, 5, 1, 7, 10, 12 };
	auto res = s->bstFromPreorder(p);
	return 0;
}*/
