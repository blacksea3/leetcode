#include "BinaryTree.h"

//Firstly: inorder traversal, find the first item, then traverse it, 36ms, 42.11%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*class Solution {
public:
	bool isValidBST(TreeNode* root) {
		//中序遍历,只保存最后遍历的节点,并与下一个节点比较

		int last_num;

		vector<TreeNode> stack = {};
		TreeNode *pre = root;
		//先找到第一个
		while ((pre != nullptr) || !stack.empty())
		{
			if (pre != nullptr)
			{
				stack.push_back(*pre);
				pre = pre->left;
			}
			else
			{
				//撤回一步
				pre = &stack[stack.size() - 1];
				stack.pop_back();
				last_num = pre->val;
				pre = pre->right;
				break;
			}
		}

		while ((pre != nullptr) || !stack.empty())
		{
			if (pre != nullptr)
			{
				stack.push_back(*pre);
				pre = pre->left;
			}
			else
			{
				//撤回一步
				pre = &stack[stack.size() - 1];
				stack.pop_back();
				if (last_num >= pre->val) return false;
				else last_num = pre->val;
				pre = pre->right;
			}
		}

		return true;
	}
};*/

//Second: DC problem: recursively solve it, 12ms, 99.52%
class Solution {
public:
	int* last = NULL;
	bool isValidBST(TreeNode* root) {
		if (root) {
			if (!isValidBST(root->left)) return false;
			if (last && *last >= root->val) return false;
			last = &root->val;
			if (!isValidBST(root->right)) return false;
			return true;
		}
		else return true;
	}
};

int main()
{
	TreeNode* root = stringToTreeNode("[10,5,15,null,null,6,20]");
	prettyPrintTree(root);
	Solution* s = new Solution();
	cout << s->isValidBST(root);
	return 0;
}
