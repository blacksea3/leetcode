#include "BinaryTree.h"

//note: recursively will overflow, FUCK
//iterative: 20ms, 99.33%

//the first item in preorder is root, then divide inorder by root into left and right trees

//in the iteratively solution: 
//先preorder往后面扫,如果当前节点!=inorder未操作节点,则生成单独左儿子节点,连接到root上
//然后存至栈,注意这里扫的时候,被扫的节点在当前节点后一格
//否则,栈退出,当前节点上溯
//inorder节点连续被操作,操作停止时当前节点的右节点恰好等于preorder的被扫描的节点

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return nullptr;

		stack<TreeNode*> st;
		TreeNode* root = new TreeNode(preorder[0]);
		st.push(root);
		int index = 0;

		for (int i = 1; i <= preorder.size(); ++i)
		{
			TreeNode *cur = st.top();
			if (cur->val != inorder[index])
			{
				cur->left = new TreeNode(preorder[i]);
				st.push(cur->left);
			}
			else
			{
				while (!st.empty() && st.top()->val == inorder[index])
				{
					cur = st.top();
					st.pop();
					++index;
				}
				if (index < inorder.size())  //border check
				{
					cur->right = new TreeNode(preorder[i]);
					st.push(cur->right);
				}
			}
		}
		return root;
	}
};
