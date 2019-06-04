#include "BinaryTree.h"

//Morris traverse, see https://blog.csdn.net/u013575812/article/details/50069991 86.75%

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
	void recoverTree(TreeNode* root) {
		//简单的方法是中序遍历后排序节点，然后按照中序遍历的顺序依次填回去，空间复杂度O(n)

		//Morris遍历
		//太变态了https://blog.csdn.net/u013575812/article/details/50069991
		//核心:首先疯狂往左遍历,每次往下增加深度时,对当前的右子树的最右节点的右节点连上当前节点的父节点
		//然后按照中序遍历,往左遍历完就往右走,能够直接走到父节点去!,然后再往右走

		//什么时候往左走:当前的右子树的最右节点是空的，而不是当前的右子树的最右节点连接上了当前节点的父节点
		//否则往右走

		//这个需要之后再次消化

		//空间复杂度为常数


		TreeNode *first = NULL;
		TreeNode *second = NULL;
		TreeNode *parent = NULL;
		TreeNode *pre = NULL;
		TreeNode *cur = root;

		while (cur != NULL) {
			if (cur->left == NULL) {
				if (parent != NULL && parent->val >= cur->val) {
					if (first == NULL) first = parent;
					second = cur;
				}
				parent = cur;
				cur = cur->right;
			}//end if
			else {
				pre = cur->left;
				while (pre->right != NULL && pre->right != cur) pre = pre->right;

				if (pre->right == NULL) {
					pre->right = cur;
					cur = cur->left;
				}
				else {
					pre->right = NULL;
					if (parent != NULL && parent->val >= cur->val) {
						if (first == NULL) first = parent;
						second = cur;
					}
					parent = cur;
					cur = cur->right;
				}
			}//end else
		}//end while

		if (first != NULL && second != NULL) {
			int temp = first->val;
			first->val = second->val;
			second->val = temp;
		}
	}
};