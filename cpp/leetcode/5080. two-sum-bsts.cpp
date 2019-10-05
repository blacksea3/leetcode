#include "BinaryTree.h"

//
//分治
//如果当前两个root非空, 且值和=target 返回true
// 如果小了, 返回1的右边和2; 2的右边和1
// 如果大了, 返回1的左边和2; 2的左边和1

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
	vector<int> inorderTraversal(TreeNode* pRootOfTree)
	{
		stack<TreeNode*> st;
		TreeNode* pre = pRootOfTree;
		vector<int> res;

		while (!st.empty() || pre)
		{
			while (pre)
			{
				st.push(pre);
				pre = pre->left;
			}
			pre = st.top();
			st.pop();
			res.emplace_back(pre->val);
			pre = pre->right;
		}
		return res;
	}

public:
	bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
		vector<int> v1;
		vector<int> v2;

		v1 = inorderTraversal(root1);
		v2 = inorderTraversal(root2);

		for (auto& iterv1 : v1)
		{
			if (binary_search(v2.begin(), v2.end(), target - iterv1)) return true;
		}
		return false;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->twoSumBSTs(stringToTreeNode("[0,-10,10]"), stringToTreeNode("[5,1,7,0,2]"), 18);
	return 0;
}
*/
