#include "BinaryTree.h"

//
//如果1号玩家选择的节点所在子树不包含根的节点总数量正好等于一半的(总节点量-1), 那么false 否则true

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
	int totalnum = 0;
	int leftnum = 0;
	int rightnum = 0;
	int gblx;
	void DFS(TreeNode* root, bool isneedcal, bool callleft, bool callright)
	{
		if (!root) return;
		else
		{
			if (isneedcal)
			{
				totalnum++;
				if (callleft) leftnum++;
				else if (callright) rightnum++;
				DFS(root->left, isneedcal, callleft, callright);
				DFS(root->right, isneedcal, callleft, callright);
			}
			else
			{
				if (root->val == gblx)
				{
					isneedcal = true;
					DFS(root->left, isneedcal, true, callright);
					DFS(root->right, isneedcal, callleft, true);
				}
				else
				{
					DFS(root->left, isneedcal, callleft, callright);
					DFS(root->right, isneedcal, callleft, callright);
				}
			}
		}
	}

public:
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		gblx = x;
		DFS(root, false, false, false);

		if (totalnum < (n - 1) / 2) return true;
		else
		{
			if (max(leftnum, rightnum) >= ((n - 1) / 2 + 1)) return true;
			else return false;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//cout << s->btreeGameWinningMove(stringToTreeNode("[1,2,3]"), 3, 1);
	cout << s->btreeGameWinningMove(stringToTreeNode("[1,2,3,4,5]"), 5, 1);
	return 0;
}
*/
