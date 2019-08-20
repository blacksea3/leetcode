#include "BinaryTree.h"

//188ms, 66.52%
//DFS
//�ݹ麯�����ذ�����ǰroot�ڵ���"����"ֵͬ·��, ����ָ��ǰroot�ڵ������·����һ��

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
	int res = 1;

	int DFS(TreeNode* root)
	{
		if (!root) return 0;
		else
		{
			int preVal = root->val;
			TreeNode* leftNode = root->left;
			TreeNode* rightNode = root->right;
			int leftRoute = DFS(leftNode);
			int rightRoute = DFS(rightNode);
			if (!(leftNode && (preVal == leftNode->val)))
				leftRoute = 0;
			if (!(rightNode && (preVal == rightNode->val)))
				rightRoute = 0;
			res = max(res, 1 + leftRoute + rightRoute);
			return 1 + max(leftRoute, rightRoute);
		}
	}


public:
	int longestUnivaluePath(TreeNode* root) {
		DFS(root);
		return res - 1;
	}
};

int main()
{
	Solution* s = new Solution();
	auto res = s->longestUnivaluePath(stringToTreeNode("[5,4,5,1,1,5]"));
	return 0;
}
