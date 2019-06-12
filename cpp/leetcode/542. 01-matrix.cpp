#include "public.h"

//BFS problem, 468ms, 39.86%

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		queue <pair<int, int>> q;    //pre level points
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> res(m, vector<int>(n, INT_MAX));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					res[i][j] = 0;
					q.push({ i,j });    //init q
				}
				else matrix[i][j] = INT_MAX;
			}
		}
		while (!q.empty())
		{
			pair <int, int> temp = q.front();
			int prerow = temp.first;
			int precolumn = temp.second;
			int preval_p1 = matrix[prerow][precolumn] + 1;
			q.pop();
			//search neighbour points
			if (prerow > 0)
				if (preval_p1 < matrix[prerow - 1][precolumn])
				{
					matrix[prerow - 1][precolumn] = preval_p1;
					q.push({ prerow - 1, precolumn });
				}
			if (prerow < m - 1)
				if (preval_p1 < matrix[prerow + 1][precolumn])
				{
					matrix[prerow + 1][precolumn] = preval_p1;
					q.push({ prerow + 1, precolumn });
				}
			if (precolumn > 0)
				if (preval_p1 < matrix[prerow][precolumn - 1])
				{
					matrix[prerow][precolumn - 1] = preval_p1;
					q.push({ prerow, precolumn - 1 });
				}
			if (precolumn < n - 1)
				if (preval_p1 < matrix[prerow][precolumn + 1])
				{
					matrix[prerow][precolumn + 1] = preval_p1;
					q.push({ prerow, precolumn + 1 });
				}
		}
		return matrix;
	}
};
