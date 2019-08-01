#include "BinaryTree.h"

//296ms, 17.31%
//DFS

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
	vector<vector<int>> allpossibles;
	void DFS(vector<int> prev, int zeronum, int twonum, int target)
	{
		if (target == 0 && zeronum == twonum)
		{
			prev.push_back(0);
			allpossibles.push_back(prev);
		}
		else
		{
			if (target == 0)
			{
				prev.push_back(0);
				DFS(prev, zeronum + 1, twonum, target);
			}
			else if (zeronum < twonum)
			{
				prev.push_back(2);
				DFS(prev, zeronum, twonum + 1, target - 2);
				prev.pop_back();
				prev.push_back(0);
				DFS(prev, zeronum + 1, twonum, target);
			}
			else
			{
				prev.push_back(2);
				DFS(prev, zeronum, twonum + 1, target - 2);
			}
		}
	}

	void clearq(queue<TreeNode*>& q) {
		queue<TreeNode*> empty;
		swap(empty, q);
	}

public:
	vector<TreeNode*> allPossibleFBT(int N) {
		if (N == 1)
		{
			TreeNode* root = new TreeNode(0);
			return { root };
		}
		else if (N % 2 == 0) return {};
		else
		{
			//首先生成一个列表, 里面为数字2或0, 满足: 数字的和是N-1, 除最后一位以外, 0等于2的数量, 在生成的过程中0的数量一直<=2的数量
			DFS({}, 0, 0, N - 1);
			//然后按照列表层序生成二叉树
			vector<TreeNode*> res;

			for (int i = 0; i < allpossibles.size(); ++i)
			{
				TreeNode* root = new TreeNode(0);
				res.push_back(root);
				queue<TreeNode*> q;
				q.push(root);
				queue<TreeNode*> next;
				for (int j = 0; j < allpossibles[i].size(); ++j)
				{
					if (q.empty())
					{
						q = next;
						clearq(next);
					}
					TreeNode* pre = q.front();
					if (allpossibles[i][j] == 2)
					{
						TreeNode* left = new TreeNode(0);
						TreeNode* right = new TreeNode(0);
						next.push(left);
						next.push(right);
						pre->left = left;
						pre->right = right;
						q.pop();
					}
					else q.pop();
				}
			}
			return res;
		}
	}
};

int main()
{
	Solution* s = new Solution();
	auto res = s->allPossibleFBT(7);
	return 0;
}