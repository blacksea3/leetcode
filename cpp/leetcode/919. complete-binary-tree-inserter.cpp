#include "BinaryTree.h"

//32ms, 80.00%
//������Բ�������?
//ʹ�ü򵥱����ķ���: ֱ��������vector��¼�����ǺͶ�����, �����ǰ���밴λ�ò���, �����������*2==��������, ��ô����һ��

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
	vector<TreeNode*> fathers;
	vector<TreeNode*> sons;
	TreeNode* mroot;
public:
	CBTInserter(TreeNode* root) {
		mroot = root;
		//init fathers and sons
		fathers.push_back(root);
		while (true)
		{
			for (auto& f : fathers)
			{
				if (f->left)
				{
					sons.push_back(f->left);
					if (f->right)
					{
						sons.push_back(f->right);
					}
					else break;
				}
				else break;
			}
			if (fathers.size() * 2 == sons.size())
			{
				fathers = sons;
				sons.clear();
				continue;
			}
			else
				break;
		}


	}

	int insert(int v) {
		//�鿴���׺Ͷ�������
		int lf = fathers.size();
		int ls = sons.size();
		TreeNode* pre = new TreeNode(v);
		TreeNode* f = fathers[ls / 2];
		if (ls % 2) f->right = pre;
		else f->left = pre;
		sons.push_back(pre);
		if (lf * 2 == (ls + 1))
		{
			fathers = sons;
			sons.clear();
		}
		return f->val;
	}

	TreeNode* get_root() {
		return mroot;
	}
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

/*
int main()
{
	CBTInserter* obj = new CBTInserter(stringToTreeNode("[1,2,3,4,5,6]"));
	int param_1 = obj->insert(7);
	int param_2 = obj->insert(8);
	return 0;
}
*/
