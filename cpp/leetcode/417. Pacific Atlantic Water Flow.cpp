#include "public.h"

//DFS problem, TOTAL BRUTE force DFS, TLE

/*
class Solution {
private:
	//target: true: Parcific(left, top), false: Atlantic(right, down)
	bool DFS(const vector<vector<int>>& matrix, vector<vector<bool>> issearched, int y, int x, bool target)
	{
		if (target)
		{
			if ((y == 0) || (x == 0)) return true;
			else
			{
				issearched[y][x] = true;
				if ((!issearched[y - 1][x]) && (matrix[y][x] >= matrix[y - 1][x]))
					if (DFS(matrix, issearched, y - 1, x, target)) return true;
				if ((!issearched[y][x - 1]) && (matrix[y][x] >= matrix[y][x - 1]))
					if (DFS(matrix, issearched, y, x - 1, target)) return true;
				if ((y < matrix.size() - 1) && (!issearched[y + 1][x]) && (matrix[y][x] >= matrix[y + 1][x]))
					if (DFS(matrix, issearched, y + 1, x, target)) return true;
				if ((x < matrix[0].size() - 1) && (!issearched[y][x + 1]) && (matrix[y][x] >= matrix[y][x + 1]))
					if (DFS(matrix, issearched, y, x + 1, target)) return true;
			}
			return false;
		}
		else
		{
			if ((y == matrix.size() - 1) || (x == matrix[0].size() - 1)) return true;
			else
			{
				issearched[y][x] = true;
				if ((y > 0) && (!issearched[y - 1][x]) && (matrix[y][x] >= matrix[y - 1][x]))
					if (DFS(matrix, issearched, y - 1, x, target)) return true;
				if ((x > 0) && (!issearched[y][x - 1]) && (matrix[y][x] >= matrix[y][x - 1]))
					if (DFS(matrix, issearched, y, x - 1, target)) return true;
				if ((!issearched[y + 1][x]) && (matrix[y][x] >= matrix[y + 1][x]))
					if (DFS(matrix, issearched, y + 1, x, target)) return true;
				if ((!issearched[y][x + 1]) && (matrix[y][x] >= matrix[y][x + 1]))
					if (DFS(matrix, issearched, y, x + 1, target)) return true;
			}
			return false;
		}
	}

public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> res = {};
		for (int y = 0; y < matrix.size(); ++y)
			for (int x = 0; x < matrix[0].size(); ++x)
			{
				vector<vector<bool>> issearched(matrix.size(), vector<bool>(matrix[0].size(), false));
				if ((DFS(matrix, issearched, y, x, true)) && (DFS(matrix, issearched, y, x, false)))
					res.push_back({x, y});
			}
		return res;
	}
};
*/

//68ms, 87.73%
//modified DFS, from left/top and right/down, reverse move the water!
//  store all the loc that can move to Parcific(left, top) and Atlantic(right, down)
//  then use traverse to get the loc that can move both to Parcific and Atlantic

class Solution {
private:
	vector<vector<bool>> is_parcific;
	vector<vector<bool>> is_atlantic;
	vector<vector<bool>> issearched;

	//origin true: Parcific(left, top), false: Atlantic(right, down)
	void DFS(const vector<vector<int>>& matrix, int y, int x, bool origin)
	{
		if (issearched[y][x]) return;
		issearched[y][x] = true;
		if (origin) is_parcific[y][x] = true;
		else is_atlantic[y][x] = true;

		if ((y > 0) && (!issearched[y - 1][x]) && (matrix[y][x] <= matrix[y - 1][x]))
			DFS(matrix, y - 1, x, origin);
		if ((x > 0) && (!issearched[y][x - 1]) && (matrix[y][x] <= matrix[y][x - 1]))
			DFS(matrix, y, x - 1, origin);
		if ((y < matrix.size() - 1) && (!issearched[y + 1][x]) && (matrix[y][x] <= matrix[y + 1][x]))
			DFS(matrix, y + 1, x, origin);
		if ((x < matrix[0].size() - 1) && (!issearched[y][x + 1]) && (matrix[y][x] <= matrix[y][x + 1]))
			DFS(matrix, y, x + 1, origin);
	}

public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if ((matrix.size() == 0) || (matrix[0].size() == 0)) return vector<vector<int>> {};

		int m = matrix.size();     //lines
		int n = matrix[0].size();  //columns
		vector<vector<bool>> zero(m, vector<bool>(n, false));
		
		//search Racific
		is_parcific.assign(zero.begin(), zero.end());
		issearched.assign(zero.begin(), zero.end());
		for (int x = 0; x < n; ++x)
			DFS(matrix, 0, x, true);
		for (int y = 1; y < m; ++y)
			DFS(matrix, y, 0, true);

		//search Atlantic
		is_atlantic.assign(zero.begin(), zero.end());
		issearched.assign(zero.begin(), zero.end());
		for (int x = 0; x < n; ++x)
			DFS(matrix, m - 1, x, false);
		for (int y = 0; y < m - 1; ++y)
			DFS(matrix, y, n - 1, false);

		//generate res
		vector<vector<int>> res = {};
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y)
				if (is_parcific[y][x] && is_atlantic[y][x]) res.push_back({ y,x });

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> matrix = { {1,2}, {4,3} };
	vector<vector<int>> res = s->pacificAtlantic(matrix);
	return 0;
}
*/