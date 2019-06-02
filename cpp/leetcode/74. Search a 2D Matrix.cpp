#include "public.h"

//12ms, 95.45%

//use double binary search

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;

		//search line
		int up = 0;
		int down = matrix.size() - 1;
		int mid;
		while (up <= down)
		{
			mid = (up + down) / 2;
			if (matrix[mid][0] < target) up = mid + 1;
			else if (matrix[mid][0] > target) down = mid - 1;
			else return true;
		}

		if (down == -1) return false;

		int fixrow = down;

		//search column, reuse up and down
		up = 0;
		down = matrix[0].size() - 1;
		while (up <= down)
		{
			mid = (up + down) / 2;
			if (matrix[fixrow][mid] < target) up = mid + 1;
			else if (matrix[fixrow][mid] > target) down = mid - 1;
			else return true;
		}
		return false;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> m = { {},{}, {} };
	cout << s->searchMatrix(m,3);
	return 0;
}
