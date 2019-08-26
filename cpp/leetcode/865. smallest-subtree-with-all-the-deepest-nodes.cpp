#include "BinaryTree.h"

//8ms, 78.13%
//DFS先查出深度
//然后寻找这样的节点: 他的左右子树深度加上自己深度都等于实际最深深度, 找出最浅的这个节点
//左右子树深度等于两者更深的那个, 通过后序遍历查询, 第一个一个满足深度条件的节点必然是最深的节点(祖先)

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
	int maxdepth = 0;
	int numleafs = 0;
	TreeNode* res;
	bool isok = false;
	void DFS_depth(TreeNode* root, int predepth)
	{
		if (!root) return;
		else
		{
			maxdepth = max(maxdepth, predepth);
			DFS_depth(root->left, predepth + 1);
			DFS_depth(root->right, predepth + 1);
		}
	}

	void find_leafs(TreeNode* root, int predepth)
	{
		if (!root) return;
		else
		{
			if (predepth == maxdepth) 
				numleafs++;
			find_leafs(root->left, predepth + 1);
			find_leafs(root->right, predepth + 1);
		}
	}

	//返回当前树包含的最大深度节点个数
	int DFS_find_pre(TreeNode* root, int predepth)
	{
		if (isok) return -999;
		if (!root->left && !root->right)
		{
			if (predepth == maxdepth)
			{
				if (numleafs == 1)
				{
					res = root;
					isok = true;
					return -999;
				}
				else return 1;
			}
			else return 0;
		}
		else if (!root->left)
		{
			return DFS_find_pre(root->right, predepth + 1);
		}
		else if (!root->right)
		{
			return DFS_find_pre(root->left, predepth + 1);
		}
		else
		{
			int left = DFS_find_pre(root->left, predepth + 1);
			int right = DFS_find_pre(root->right, predepth + 1);
			if ((left + right) == numleafs)
			{
				res = root;
				isok = true;
				return -999;
			}
			else
			{
				return (left + right);
			}
		}
	}


public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		DFS_depth(root, 1);
		find_leafs(root, 1);
		DFS_find_pre(root, 1);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->subtreeWithAllDeepest(stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]"));
	return 0;
}
*/
