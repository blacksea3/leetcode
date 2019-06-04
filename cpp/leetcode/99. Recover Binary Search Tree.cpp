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
		//�򵥵ķ������������������ڵ㣬Ȼ�������������˳���������ȥ���ռ临�Ӷ�O(n)

		//Morris����
		//̫��̬��https://blog.csdn.net/u013575812/article/details/50069991
		//����:���ȷ���������,ÿ�������������ʱ,�Ե�ǰ�������������ҽڵ���ҽڵ����ϵ�ǰ�ڵ�ĸ��ڵ�
		//Ȼ�����������,����������������,�ܹ�ֱ���ߵ����ڵ�ȥ!,Ȼ����������

		//ʲôʱ��������:��ǰ�������������ҽڵ��ǿյģ������ǵ�ǰ�������������ҽڵ��������˵�ǰ�ڵ�ĸ��ڵ�
		//����������

		//�����Ҫ֮���ٴ�����

		//�ռ临�Ӷ�Ϊ����


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