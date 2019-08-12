#include "BinaryTree.h"

//52ms, 36.82%
//基础结构
//先(二分)查到节点Pre, 此时应当记录下父节点Par(用迭代查节点)
//然后: Par某个方向=Pre->right
//如果Pre->left是空, 则结束了
//否则:从Pre->left开始一直找右儿子, 直到终点:Ma: 则Ma->right = Pre->right->left
//   然后Pre->right->left = Pre->left

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
	TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode* dump = new TreeNode(0);
		dump->left = root;
		TreeNode* parent = dump;
		TreeNode* son = root;
		bool isleft = true;
		bool isdeleted = false;
		TreeNode* rootson = son;

		while (son)
		{
			if (son->val == key)
			{		
				if (!son->right)
				{
					rootson = son->left;
				}
				else
				{
					rootson = son->right;
					if (!son->left) ;
					else
					{
						TreeNode* pre = son->left;
						while (pre->right) pre = pre->right;
						pre->right = rootson->left;
						rootson->left = son->left;
					}
				}
				isdeleted = true;
				break;
			}
			else if (son->val > key)
			{
				parent = son;
				son = son->left;
				isleft = true;
			}
			else
			{
				parent = son;
				son = son->right;
				isleft = false;
			}
		}

		if (!isdeleted)
			return dump->left;
		else
		{
			if (isleft) parent->left = rootson;
			else parent->right = rootson;
			return dump->left;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->deleteNode(stringToTreeNode("[0]"), 0);
	//auto res = s->deleteNode(stringToTreeNode("[5,3,6,2,4,null,7]"), 3);
	return 0;
}
*/
