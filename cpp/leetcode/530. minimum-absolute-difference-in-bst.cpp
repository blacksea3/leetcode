#include "BinaryTree.h"

//32ms, 54.56%
//遍历: 左中右

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
	int getMinimumDifference(TreeNode* root) {
		int res = INT_MAX;
		stack<TreeNode*> st;
		st.push(root);
		TreeNode* pre = root;
		int old = 100000000;  //取个很大的数字, 避免干扰第一个值运算

		while (!st.empty())
		{
			if (pre->left)
			{
				st.push(pre->left);
				pre = pre->left;
			}
			else
			{
				while (!st.empty())
				{
					TreeNode* temp = st.top();
					res = min(res, abs(temp->val - old));
					old = temp->val;
					st.pop();
					if (temp->right)
					{
						st.push(temp->right);
						pre = temp->right;
						break;
					}
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->getMinimumDifference(stringToTreeNode("[236,104,701,null,227,null,911]"));
	return 0;
}
*/
