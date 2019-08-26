#include "public.h"

//8ms, 37.81%
//正常操作, 模拟

class Solution {
private:
	vector<vector<int>> v = { {0,0},{0,1},{0,2},{0,3},{0,4},
 {1,0},{1,1},{1,2},{1,3},{1,4},
 {2,0},{2,1},{2,2},{2,3},{2,4},
 {3,0},{3,1},{3,2},{3,3},{3,4},
 {4,0},{4,1},{4,2},{4,3},{4,4},
 {5,0},{5,1},{5,2},{5,3},{5,4}
	};
	string getroute(int old, int pre)
	{
		int x1 = v[old][0];
		int y1 = v[old][1];
		int x2 = v[pre][0];
		int y2 = v[pre][1];

		string res = "";

		//先上下
		if (x2 != 5)
		{
			if (x2 > x1)
			{
				for (int i = 0; i < (x2 - x1); ++i)
				{
					res += 'D';
				}
			}
			else if (x2 < x1)
			{
				for (int i = 0; i < -1 * (x2 - x1); ++i)
				{
					res += 'U';
				}
			}
			//
			if (y2 > y1)
			{
				for (int i = 0; i < (y2 - y1); ++i)
				{
					res += 'R';
				}
			}
			else
			{
				for (int i = 0; i < -1 * (y2 - y1); ++i)
				{
					res += 'L';
				}
			}
		}
		else if (x1 != 5)
		{
			for (int i = 0; i < (4 - x1); ++i)
			{
				res += 'D';
			}
			for (int i = 0; i < -1 * (y2 - y1); ++i)
			{
				res += 'L';
			}
			res += 'D';
		}
		res += '!';
		return res;
	}

public:
	string alphabetBoardPath(string target) {
		string returns = "";

		target = "a" + target;

		for (int i = 0; i < target.size() - 1; ++i)
		{
			string temp = getroute(target[i] - 'a', target[i + 1] - 'a');
			returns += temp;
		}
		return returns;
	}
};
