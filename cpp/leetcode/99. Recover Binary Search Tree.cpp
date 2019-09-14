#include "BinaryTree.h"

//36ms, 74.91%
//�򵥵ķ������������������ڵ㣬Ȼ�������������˳���������ȥ���ռ临�Ӷ�O(n)
//������
//���ֱ���

class Solution {
private:
	vector<int> nodes;
	int index = 0;
	void Inorder_Gen(TreeNode* root)
	{
		if (!root) return;
		Inorder_Gen(root->left);
		nodes.emplace_back(root->val);
		Inorder_Gen(root->right);
	}
	void Inorder_Set(TreeNode* root)
	{
		if (!root) return;
		Inorder_Set(root->left);
		root->val = nodes[index++];
		Inorder_Set(root->right);
	}

public:
	void recoverTree(TreeNode* root) {
		Inorder_Gen(root);
		sort(nodes.begin(), nodes.end());
		Inorder_Set(root);
	}
};

/*
//52ms, 32.63%
//Morris traverse, see https://blog.csdn.net/u013575812/article/details/50069991
class Solution {
public:
	void recoverTree(TreeNode* root) {
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
			}
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
			}
		}

		if (first != NULL && second != NULL) {
			int temp = first->val;
			first->val = second->val;
			second->val = temp;
		}
	}
};
*/
