#include "BinaryTree.h"

//16ms, 30.00%
//先还原出A, 再添加B

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
	vector<int> reconstructA(TreeNode* root)
	{
		if (!root) return vector<int>{};

		vector<int> left = reconstructA(root->left);
		vector<int> right = reconstructA(root->right);
		vector<int> res = left;
		res.push_back(root->val);
		for (int i = 0; i < right.size(); ++i)
		{
			res.push_back(right[i]);
		}
		return res;
	}

	//[start, end]应当是合法的闭区间
	TreeNode* constructB(const vector<int>& B, int start, int end)
	{
		if (start > end) return nullptr;
		int resloc;
		int rmax = INT_MIN;
		for (int i = start; i <= end; ++i)
		{
			if (rmax < B[i])
			{
				rmax = B[i];
				resloc = i;
			}
		}
		//拆分
		TreeNode* res = new TreeNode(rmax);
		res->left = constructB(B, start, resloc - 1);
		res->right = constructB(B, resloc + 1, end);
		return res;
	}

public:
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		vector<int> A = reconstructA(root);
		A.push_back(val);

		TreeNode* tB = constructB(A, 0, A.size() - 1);
		return tB;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->insertIntoMaxTree(stringToTreeNode("[4,1,3,null,null,2]"), 5);
	return 0;
}
*/
