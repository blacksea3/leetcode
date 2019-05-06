#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_WC

vector<vector<int>> Solution::colorBorder(vector<vector<int>>& grid, int r0, int c0, int color)
{
	//只要搞清楚边界就可以咯
	//从中心点试图向外扩散,如果四个方向都是和中心点相同值,则保存此四个点接着扩散,删除中心点
	//否则:保存相同值的点然后扩散
	//对于边界点,保存相同值的点然后扩散

	//对于已经保存/删除的点,扩散时无视它,认为是相同值

	//m行n列
	int m = grid.size();
	int n = grid[0].size();

	//维护一个stack保存待扩散的点
	//维护一个res保存确认是边界的点
	//维护一个full保存内部点
	int findcolor = grid[r0][c0];
	vector<pair<int, int>> stack = { pair<int,int>(r0,c0) };
	vector<pair<int, int>> res = {};
	vector<pair<int, int>> full = {};

	while (stack.size() > 0)
	{
		int same_time = 0;
		pair<int, int> pre_loc = stack[stack.size()-1];
		stack.pop_back();

		if ((pre_loc.first != 0) && (grid[pre_loc.first - 1][pre_loc.second] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first - 1, pre_loc.second)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first - 1, pre_loc.second)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first - 1, pre_loc.second));
			}
			same_time++;
		}
		if ((pre_loc.first != (m - 1)) && (grid[pre_loc.first + 1][pre_loc.second] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first + 1, pre_loc.second)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first + 1, pre_loc.second)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first + 1, pre_loc.second));
			}
			same_time++;
		}
		if ((pre_loc.second != 0) && (grid[pre_loc.first][pre_loc.second - 1] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first, pre_loc.second - 1)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first, pre_loc.second - 1)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first, pre_loc.second - 1));
			}
			same_time++;
		}
		if ((pre_loc.second != (n - 1)) && (grid[pre_loc.first][pre_loc.second + 1] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first, pre_loc.second + 1)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first, pre_loc.second + 1)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first, pre_loc.second + 1));
			}
			same_time++;
		}

		if (same_time == 4) full.push_back(pre_loc);
		else res.push_back(pre_loc);
	}

	for (int i = 0; i < res.size(); i++)
	{
		grid[res[i].first][res[i].second] = color;
	}
	return grid;
}

TreeNode* Solution::bstToGst(TreeNode* root)
{
	//看示例,似乎是先遍历右子树,然后遍历根,然后遍历左子树咯
	//每遍历一次,替换那个节点的值,用当前已经替换的节点值之和+那个节点的值替换;然后更新已经替换的节点值之和

	int pre_sum = 0;
	vector<TreeNode*> stack = {};
	TreeNode *rootbak = root;
	TreeNode *pre = root;
	while ((pre != nullptr) || !stack.empty())
	{
		if (pre != nullptr)
		{
			stack.push_back(pre);
			pre = pre->right;
		}
		else
		{
			//撤回一步
			pre = stack[stack.size() - 1];
			stack.pop_back();
			pre->val += pre_sum;
			pre_sum = pre->val;
			pre = pre->left;
		}
	}
	return rootbak;
}


int Solution::iter_minScoreTriangulation(vector<int>& A)
{
	//如果长度是三,直接乘起来
	//否则递归去吧
	//对于以下点:    A0, A1, A2...  AN-1
	//连线A0-A2, 左半A0A1A2与右半A2,A3...AN-1,A0
	//左半A0-A3, 右半A3,A3...AN-1,A0
	//左半直到A0-A(N-2),  对应右半直到A0,AN-1,AN

	//划分起始点然后从A1开始,第二点从A3开始,终点最多到AN-1
	//搞个大递归

	if (A.size() == 3) return A[0] * A[1] * A[2];

	int minres = INT_MAX;

	int res1 = 0;
	int res2 = 0;

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = i + 2; j < A.size(); j++)
		{
			if ((i == 0) && (j == A.size() - 1)) continue;
			vector<int> left = {};
			for (int k = i; k <= j; k++)
				left.push_back(A[k]);
			res1 = iter_minScoreTriangulation(left);
			

			vector<int> right = {};
			for (int k = j; k < A.size(); k++)
				right.push_back(A[k]);
			for (int k = 0; k <= i; k++)
				right.push_back(A[k]);
			res2 = iter_minScoreTriangulation(right);
			minres = min(minres, (res1 + res2));
		}
	}
	return minres;
}

int Solution::minScoreTriangulation(vector<int>& A)
{
	return iter_minScoreTriangulation(A);
}

/*
	//包括0,有效值[0,max]
	int Solution::noborder_add(int add1, int add2, int max)
	{
		return ((add1 + add2) <= max) ? (add1 + add2) : (add1 + add2 - max - 1);
	}

	int Solution::minScoreTriangulation(vector<int>& A)
	{
		//动态规划
		//维护dp[start][end]:表示 start,start+1,end三角形的乘积,这里的end实际上是下标end+2
		//维护dp2[start][length]:表示从start顺时针加一段长度,length:0表示长度是4,0最大为A.size()-4

		int maxloc = A.size() - 1;
		int size = A.size();

		//计算dp
		vector<vector<int>> dp(A.size(), vector<int>(A.size() - 3));

		for (int i = 0; i <= maxloc; i++)
			for (int j = 0; j <= (maxloc - 3); j++)
				dp[i][j] = A[i] * A[noborder_add(i, 1, maxloc)] * A[j];

		//计算dp2
		vector<vector<int>> dp2(A.size(), vector<int>(A.size() - 3));

		int length = -1;
		for (int i = 0; i <= maxloc; i++)
			dp2[i][0] = min((dp[i][0] + dp[noborder_add(i, (length + 2), maxloc)][size - (length + 2) - 1]), (dp[noborder_add(i, 1, maxloc)][0] + dp[i][length + 1]));

		for (int i = 1; i <= maxloc; i++)
		{
			for (int j = 0; j <= (maxloc - 3); j++)
			{
				int length = j - 1;
				dp2[i][j] = min((dp[i][length] + dp[noborder_add(i, (length + 2), maxloc)][size - (length + 2) - 1]), (dp[noborder_add(i, 1, maxloc)][j] + dp[i][length + 1]));
			}
			
		}

		return 0;
	}

*/

#else
#endif
