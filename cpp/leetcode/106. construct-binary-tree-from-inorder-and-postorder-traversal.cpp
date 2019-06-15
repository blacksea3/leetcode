#include "BinaryTree.h"

//24ms, 96.72%

//similar to problem 105
//上一题是这样
//先preorder往后面扫,如果当前节点!=inorder未操作节点,则记录至左儿子
//然后存至栈,注意这里扫的时候,被扫的节点在当前节点后一格
//否则,栈退出,当前节点上溯
//inorder节点连续被操作,操作停止时当前节点的右节点恰好等于preorder
//的被扫描的节点

//这一题是这样
//把后序遍历"倒"过来就是根->右->左
//把中序遍历"倒"过来就是右->根->左
//这样和上一题不是差不多吗!

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0) return nullptr;

		stack<TreeNode*> st;
		TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
		st.push(root);
		int index = inorder.size() - 1;

		for (int i = postorder.size() - 2; i >= 0; --i)
		{
			TreeNode *cur = st.top();
			if (cur->val != inorder[index])
			{
				cur->right = new TreeNode(postorder[i]);
				st.push(cur->right);
			}
			else
			{
				while (!st.empty() && st.top()->val == inorder[index])
				{
					cur = st.top();
					st.pop();
					--index;
				}
				if (index >= 0)  //这相当于退出循环标志
				{
					cur->left = new TreeNode(postorder[i]);
					st.push(cur->left);
				}
			}
		}
		return root;
	}
};