#include "BinaryTree.h"


class Solution {
public:
	int numberOfDays(int Y, int M) {

		switch (M)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			return 31;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			return 30;
			break;
		}
		case 2:
		{
			if (Y % 400 == 0) return 29;
			else if (Y % 100 == 0) return 28;
			else if (Y % 4 == 0) return 29;
			else return 28;
			break;
		}
		default:
			return -999;
			break;
		}
	}

private:
	double res = INT_MIN;
	//返回: 此子树的sum, 以及个数
	pair<int, int> DFS(TreeNode* root)
	{
		if (!root) return pair<int, int>{0, 0};
		pair<int, int> left = DFS(root->left);
		pair<int, int> right = DFS(root->right);
		double sum = left.first + right.first;
	    double num = left.second + right.second;
		res = max(res, (sum + root->val) / (num + 1));
		return pair<int, int>{sum + root->val, num + 1};
	}

public:
	double maximumAverageSubtree(TreeNode* root) {
		pair<int, int> total = DFS(root);
		//res = max(res, (total.first) / (total.second);
		return res;
	}

public:
	bool canDivideIntoSubsequences(vector<int>& nums, int K) {
		int maxdup = 1;

		int predup = 1;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i] == nums[i + 1])
			{
				predup++;
			}
			else
			{
				maxdup = max(maxdup, predup);
				predup = 1;
			}
		}
		maxdup = max(maxdup, predup);
		if (maxdup * K > nums.size()) return false;
		else return true;
	}

};


int main()
{
	Solution* s = new Solution();
	//auto res = s->maximumAverageSubtree(stringToTreeNode("[2,null,1]"));
	vector<int> nums = { 5,5,5,5,5,5 };
	auto res = s->canDivideIntoSubsequences(nums, 6);
	return 0;
}
