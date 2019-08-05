#include "public.h"

//92ms, 13.77%
//BFS

class Solution {
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
};
