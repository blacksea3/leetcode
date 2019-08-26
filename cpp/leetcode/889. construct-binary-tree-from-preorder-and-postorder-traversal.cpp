#include "BinaryTree.h"

//12ms, 88.24%
//前序: 根左右
//后序: 左右根

//考虑以下的算法: 把后序倒过来: 那么假如当前根的左右儿子均存在则其之后的元素不同, 分别赋值
//否则之后的元素相同, 则直接给左儿子, 右儿子是空就行

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
	void DFS(TreeNode* root, const vector<int>& pre, int ps, int pe, const vector<int>& rpost, int rs, int re)
	{
		if (ps >= pe || rs >= re) return;

		if (pre[ps] == rpost[rs])
		{
			TreeNode* r = new TreeNode(pre[ps]);
			root->left = r;
			DFS(root->left, pre, ps + 1, pe, rpost, rs + 1, re);
		}
		else //拆分
		{
			TreeNode* left = new TreeNode(pre[ps]);
			TreeNode* right = new TreeNode(rpost[rs]);
			auto preiter = find(pre.begin() + ps, pre.begin() + pe, rpost[rs]);
			auto rpostiter = find(rpost.begin() + rs, rpost.begin() + re, pre[ps]);
			//vector<int>::iterator preiter = find(pre.begin() + ps, pre.begin() + pe, rpost[rs]);
			//vector<int>::iterator rpostiter = find(rpost.begin() + rs, rpost.begin() + re, pre[ps]);
			root->left = left;
			root->right = right;
			DFS(root->left, pre, ps + 1, preiter - pre.begin(), rpost, rpostiter - rpost.begin() + 1, re);
			DFS(root->right, pre, preiter - pre.begin() + 1, pe, rpost, rs + 1, rpostiter - rpost.begin());
		}
	}

public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		reverse(post.begin(), post.end());

		TreeNode* root = new TreeNode(pre[0]);
		DFS(root, pre, 1, pre.size(), post, 1, post.size());
		return root;

	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> pre = { 1,2,4,5,3,6,7 };
	vector<int> post = { 4,5,2,6,7,3,1 };
	auto res = s->constructFromPrePost(pre, post);
	return 0;
}
*/
