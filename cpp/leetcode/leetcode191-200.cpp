#include "include.h"

#ifdef LEETCODE_191_200
#include "public.h"
#include "leetcode.h"

int Solution::hammingWeight(uint32_t n)
{
	int res = 0;
	//位运算
	for (int i = 0; i < 32; i++)
	{
		if (n & 0x00000001) res++;
		n >>= 1;
	}
	return res;
}

int Solution::rob(vector<int>& nums)
{
	//dpi:偷窃开头直到包含i下标的最大金额
	//只保存最后三个dp
	//init
	if (nums.size() == 0)
		return 0;
	else if (nums.size() == 1)
		return nums[0];
	else if (nums.size() == 2)
		return max(nums[0], nums[1]);
	else
	{
		int dp0 = nums[0];
		int dp1 = nums[1];
		int dp2 = nums[0] + nums[2];
		for (int i = 3; i < nums.size(); i++)
		{
			dp0 = max(dp0, dp1) + nums[i];
			int temp = dp0;
			dp0 = dp1;
			dp1 = dp2;
			dp2 = temp;
		}
		return max(dp1, dp2);
	}
}

vector<int> Solution::rightSideView(TreeNode * root)
{
	//层序遍历
	vector<int> res;

	if (root == nullptr) return res;
	vector<TreeNode*> q;
	vector<TreeNode*> temp;
	q.push_back(root);
	while (!q.empty())
	{
		res.push_back(q[q.size() - 1]->val);
		temp.clear();
		for (auto iq : q)
		{
			if (iq->left) temp.push_back(iq->left);
			if (iq->right) temp.push_back(iq->right);
		}
		q.clear();
		q.assign(temp.begin(), temp.end());
	}
	return res;
}

pair<int, int> Solution::getstartloc(vector<vector<char>>& grid, pair<int, int> lastloc)
{
	int m = grid.size();
	int n = grid[0].size();
	int row = lastloc.first;
	int column = lastloc.second;

	while (true)
	{
		if (grid[row][column] == '1') return pair<int, int> {row, column};
		if (column == n - 1)
		{
			if (row == m - 1) break;
			else
			{
				row++;
				column = 0;
			}
		}
		else
			column++;
	}
	return pair<int, int> {-1, -1};
}

void Solution::BFS_Islands_200(vector<vector<char>>& grid, pair<int, int> preloc)
{
	int m = grid.size();
	int n = grid[0].size();

	vector<pair<int, int>> bfs1;
	vector<pair<int, int>> bfs2;
	bool isbfs1_valid = true;   //bfs1与bfs2来回横跳
	bfs1.push_back(preloc);
	grid[preloc.first][preloc.second] = '2';

	while (true)
	{
		if (isbfs1_valid)
		{
			if (bfs1.empty()) break;
			else
			{
				bfs2.clear();
				for (auto temp : bfs1)
				{
					int prerow = temp.first;
					int precolumn = temp.second;

					if ((prerow != 0) && (grid[prerow - 1][precolumn] == '1'))
					{
						grid[prerow - 1][precolumn] = '2';
						bfs2.push_back(pair<int, int> {prerow - 1, precolumn});
					}
					if ((prerow != m - 1) && (grid[prerow + 1][precolumn] == '1'))
					{
						grid[prerow + 1][precolumn] = '2';
						bfs2.push_back(pair<int, int> {prerow + 1, precolumn});
					}
					if ((precolumn != 0) && (grid[prerow][precolumn - 1] == '1'))
					{
						grid[prerow][precolumn - 1] = '2';
						bfs2.push_back(pair<int, int> {prerow, precolumn - 1});
					}
					if ((precolumn != n - 1) && (grid[prerow][precolumn + 1] == '1'))
					{
						grid[prerow][precolumn + 1] = '2';
						bfs2.push_back(pair<int, int> {prerow, precolumn + 1});
					}
				}
			}
			isbfs1_valid = false;
		}
		else
		{
			if (bfs2.empty()) break;
			else
			{
				bfs1.clear();
				for (auto temp : bfs2)
				{
					int prerow = temp.first;
					int precolumn = temp.second;

					if ((prerow != 0) && (grid[prerow - 1][precolumn] == '1'))
					{
						grid[prerow - 1][precolumn] = '2';
						bfs1.push_back(pair<int, int> {prerow - 1, precolumn});
					}
					if ((prerow != m - 1) && (grid[prerow + 1][precolumn] == '1'))
					{
						grid[prerow + 1][precolumn] = '2';
						bfs1.push_back(pair<int, int> {prerow + 1, precolumn});
					}
					if ((precolumn != 0) && (grid[prerow][precolumn - 1] == '1'))
					{
						grid[prerow][precolumn - 1] = '2';
						bfs1.push_back(pair<int, int> {prerow, precolumn - 1});
					}
					if ((precolumn != n - 1) && (grid[prerow][precolumn + 1] == '1'))
					{
						grid[prerow][precolumn + 1] = '2';
						bfs1.push_back(pair<int, int> {prerow, precolumn + 1});
					}
				}
			}
			isbfs1_valid = true;
		}
	}
	return;
}

int Solution::numIslands(vector<vector<char>>& grid)
{
	//BFS
	//朴素的判断是否搜索过的方法
	//对搜索过的陆地赋值2

	//目标:循环地对所有位置进行搜索,若找到某个陆地,那么BFS搜索临近陆地,直至这一块岛屿搜索结束
	//然后重置起始搜索位置,继续进行

	//特殊情况
	if (grid.size() == 0) return 0;
	if (grid[0].size() == 0) return 0;

	pair<int, int> oldstartloc = { 0,0 };
	int res = 0;

	while (true)
	{
		pair<int, int> pres = getstartloc(grid, oldstartloc);
		if ((pres.first == -1) && (pres.second == -1)) break;
		BFS_Islands_200(grid, pres);
		res++;
	}
	return res;
}





#else
#endif
