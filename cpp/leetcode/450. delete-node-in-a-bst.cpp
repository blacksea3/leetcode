#include "BinaryTree.h"

//52ms, 36.82%
//�����ṹ
//��(����)�鵽�ڵ�Pre, ��ʱӦ����¼�¸��ڵ�Par(�õ�����ڵ�)
//Ȼ��: Parĳ������=Pre->right
//���Pre->left�ǿ�, �������
//����:��Pre->left��ʼһֱ���Ҷ���, ֱ���յ�:Ma: ��Ma->right = Pre->right->left
//   Ȼ��Pre->right->left = Pre->left

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
