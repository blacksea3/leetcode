#include "BinaryTree.h"

class Solution {
private:
	static bool sort_end(const vector<int>& v1, const vector<int>& v2)
	{
		return v1[1] < v2[1];
	}


public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		//双排序, 模拟

		vector<vector<int>> start = bookings;
		vector<vector<int>> end = bookings;
		vector<int> res(n + 1, 0);
		sort(start.begin(), start.end());
		sort(end.begin(), end.end(), sort_end);

		int startloc = 0;
		int endloc = 0;
		int preair = 1;

		int prenum = 0;

		while (preair <= n)
		{
			while ((startloc < bookings.size()) && (start[startloc][0] == preair))
			{
				prenum += start[startloc][2];
				startloc++;
			}
			while ((endloc < bookings.size()) && (end[endloc][1] < preair))
			{
				prenum -= end[endloc][2];
				endloc++;
			}
			res[preair] = prenum;
			preair++;
		}
		res.erase(res.begin());
		return res;
	}

private:
	vector<TreeNode*> res;
	unordered_set<int> us_delete;
	TreeNode* recursive(TreeNode* root)
	{
		if (!root) return root;

		TreeNode* left = recursive(root->left);
		TreeNode* right = recursive(root->right);

		root->left = left;
		root->right = right;

		if (us_delete.find(root->val) != us_delete.end())
		{
			us_delete.erase(root->val);
			if (left) res.push_back(left);
			if (right) res.push_back(right);
			return nullptr;
		}
		else
		{
			return root;
		}
	}

public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int> temp(to_delete.begin(), to_delete.end());
		us_delete = temp;
		TreeNode* rootres = recursive(root);
		if (rootres) res.push_back(rootres);
		return res;
	}


	//注意到seq是有效括号
	//那么只需要把嵌套情况'平均'分配
	//因此记录当前的左括号数量, 
	//如果目前是左括号则数量加1, 之后若现在有奇数个左括号则给0, 偶数个左括号给1
	//如果目前是右括号, 则抵消掉一个左括号, 若剩余奇数个左括号则给1, 偶数个则给0  (和上一行描述相反)


public:
	vector<int> maxDepthAfterSplit(string seq) {
		vector<int> res(seq.size());
		int left = 0;
		for (int loc = 0; loc < seq.size(); ++loc)
		{
			if (seq[loc] == '(')
			{
				left++;
				if (left % 2) res[loc] = 0;
				else res[loc] = 1;
			}
			else
			{
				left--;
				if (left % 2) res[loc] = 1;
				else res[loc] = 0;
			}
		}
		return res;
	}




};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> bookings = { {1, 2, 10},{2, 3, 20},{2, 5, 25} };
	vector<int> res = s->corpFlightBookings(bookings, 5);
	return 0;
}

