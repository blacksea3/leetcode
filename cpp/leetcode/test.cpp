#include "public.h"

//暴力
//还能重复的?

class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		//统计
		vector<vector<int>> v(10, vector<int>(10, 0));

		for (auto& d : dominoes)
		{
			v[d[0]][d[1]]++;
		}

		int res = 0;

		for (int i = 2; i <= 9; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				res += v[j][i] * v[i][j];
			}
		}

		for (int i = 1; i <= 9; ++i)
		{
			for (int j = 1; j <= 9; ++j)
			{
				res += v[i][j] * (v[i][j] - 1) / 2;
			}
		}

		return res;
	}

private:
	vector<int> res;
	void BFS(bool isred, vector<int> pre_edgeid, vector<vector<bool>>& redlines, vector<vector<bool>>& bluelines, int length)
	{
		if (isred)
		{
			vector<int> next = {};
			for (auto& p : pre_edgeid)
			{
				if (res[p] == -1) res[p] = length;
				for (int i = 0; i < redlines.size(); ++i)
				{
					if (redlines[p][i])
					{
						if (find(next.begin(), next.end(), i) == next.end()) next.push_back(i);
						redlines[p][i] = false;
					}
				}
			}
			if (next.empty()) return;
			BFS(false, next, redlines, bluelines, length + 1);
		}
		else
		{
			vector<int> next = {};
			for (auto& p : pre_edgeid)
			{
				if (res[p] == -1) res[p] = length;
				for (int i = 0; i < bluelines.size(); ++i)
				{
					if (bluelines[p][i])
					{
						if (find(next.begin(), next.end(), i) == next.end()) next.push_back(i);
						bluelines[p][i] = false;
					}
				}
			}
			if (next.empty()) return;
			BFS(true, next, redlines, bluelines, length + 1);
		}
	}

public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		vector<vector<bool>> redlines(n, vector<bool>(n, false));
		vector<vector<bool>> bluelines(n, vector<bool>(n, false));

		vector<int> temp(n, -1);
		res = temp;
		for (auto& r : red_edges)
		{
			redlines[r[0]][r[1]] = true;
		}
		for (auto& b : blue_edges)
		{
			bluelines[b[0]][b[1]] = true;
		}

		vector<vector<bool>> copyredlines = redlines;
		vector<vector<bool>> copybluelines = bluelines;

		vector<int> pre_edgeid = { 0 };
		BFS(true, pre_edgeid, copyredlines, copybluelines, 0);

		vector<int> red = res;
		res = temp;
		
		BFS(false, pre_edgeid, redlines, bluelines, 0);

		vector<int> trueres(n, -1);
		for (int i = 0; i < n; ++i)
		{
			if (res[i] == -1 && red[i] == -1) trueres[i] = -1;
			else if (res[i] == -1) trueres[i] = red[i];
			else if (red[i] == -1) trueres[i] = res[i];
			else trueres[i] = min(res[i], red[i]);
		}

		return trueres;
	}

public:
	int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
		vector<int> sum_p(arr1.size(), 0);
		vector<int> sum_n(arr1.size(), 0);
		vector<int> del_p(arr1.size(), 0);
		vector<int> del_n(arr1.size(), 0);
		
		for (int i = 0; i < arr1.size(); ++i)
		{
			sum_p[i] = arr1[i] + arr2[i] + i;
			sum_n[i] = arr1[i] + arr2[i] - i;
			del_p[i] = arr1[i] - arr2[i] + i;
			del_n[i] = arr1[i] - arr2[i] - i;
		}

		vector<vector<int>> dp(arr1.size(), vector<int>(4, 0));
		vector<int> prem(4);
		prem[0] = INT_MIN;  //分别存从右边数的sum_p最大,sum_n最小,del_p最大,del_n最小
		prem[1] = INT_MAX;
		prem[2] = INT_MIN;
		prem[3] = INT_MAX;
		for (int i = arr2.size() - 1; i >= 0; --i)
		{
			prem[0] = max(prem[0], sum_p[i]);
			dp[i][0] = prem[0];
			prem[1] = min(prem[1], sum_n[i]);
			dp[i][1] = prem[1];
			prem[2] = max(prem[2], del_p[i]);
			dp[i][2] = prem[2];
			prem[3] = min(prem[3], del_n[i]);
			dp[i][3] = prem[3];
		}

		int resmax = 0;

		for (int i = 0; i < arr1.size() - 1; ++i)
		{
			resmax = max(resmax, max(
				max(dp[i + 1][0] - sum_p[i], sum_n[i] - dp[i + 1][1]),
				max(dp[i + 1][2] - del_p[i], del_n[i] - dp[i + 1][3])
				));
		}
		return resmax;
	}

private:
	int get_range_max(const vector<int>& arr, int s, int e)
	{
		int res = arr[s];
		for (int i = s + 1; i <= e; ++i)
			res = max(res, arr[i]);
		return res;
	}

public:
	int mctFromLeafValues(vector<int>& arr) {
		vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

		for (int len = 2; len <= arr.size(); ++len)
		{
			for (int start = 0; start <= arr.size() - len; ++start)
			{
				int tempmax = INT_MAX;
				int tempend = start + len - 1;
				for (int k = start; k < tempend; ++k)
				{
					tempmax = min(tempmax, dp[start][k] + dp[k + 1][tempend] +
						get_range_max(arr, start, k)*get_range_max(arr, k + 1, tempend));
				}
				dp[start][tempend] = tempmax;
			}
		}
		return dp[0][arr.size() - 1];
	}


};

/*
int main() {
	Solution* s = new Solution();
	//vector<vector<int>> d = { {1,2}, {2,1},{2,1},{2,1} };
	//cout << s->numEquivDominoPairs(d) << endl;
	//d = { {1,2}, {1,2},{1,1},{1,2}, {2,2} };
	//cout << s->numEquivDominoPairs(d) << endl;

	//vector<vector<int>> red_edges = { {0,1},{1,2} };
	//vector<vector<int>> blue_edges = {};
	//auto res = s->shortestAlternatingPaths(3, red_edges, blue_edges);
	//vector<vector<int>> red_edges = { {0,1},{0,2} };
	//vector<vector<int>> blue_edges = { {1,0} };
	//auto res = s->shortestAlternatingPaths(3, red_edges, blue_edges);

	//vector<vector<int>> red_edges = { {2,2},{0,4},{4,2},{4,3},{2,4},{0,0},{0,1},{2,3},{1,3} };
	//vector<vector<int>> blue_edges = { {0,4},{1,0},{1,4},{0,0},{4,0} };
	//auto res = s->shortestAlternatingPaths(5, red_edges, blue_edges);
	*/
	/*

	vector<int> arr1 = {1,2,3,4};
	vector<int> arr2 = { -1,4,5,6 };
	cout << s->maxAbsValExpr(arr1, arr2) << endl;

	vector<int> arr3 = { 1,-2,-5,0,10 };
	vector<int> arr4 = { 0,-2,-1,-7,-4 };
	cout << s->maxAbsValExpr(arr3, arr4) << endl;


	vector<int> arr5 = {10, 5, 2, -1, 5, 1};
	vector<int> arr6 = {-5, -4, 2, 9, -8, -5};
	cout << s->maxAbsValExpr(arr5, arr6) << endl;
	*/
	/*
	vector<int> arr = { 6,2,4 };
	cout << s->mctFromLeafValues(arr);
	return 0;
}
*/
