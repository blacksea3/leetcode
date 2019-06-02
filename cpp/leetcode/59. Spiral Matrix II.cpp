#include "public.h"

//12ms, 83.31%

//one traverse, from outside to inside

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int up_border = 0;
		int down_border = n - 1;
		int left_border = 0;
		int right_border = n - 1;
		int dir = 0;

		vector<vector<int>> res(n, vector<int>(n, 0));
		int count = 1;
		int prex = 0;
		int prey = 0;

		while ((right_border >= left_border) && (down_border >= up_border))
		{
			switch (dir)
			{
			case 0:
			{
				res[prex][prey] = count++;
				if (prey == right_border)
				{
					dir = 1;
					prex++;
					up_border++;
				}
				else prey++;
				break;
			}
			case 1:
			{
				res[prex][prey] = count++;
				if (prex == down_border)
				{
					dir = 2;
					prey--;
					right_border--;
				}
				else prex++;
				break;
			}
			case 2:
			{
				res[prex][prey] = count++;
				if (prey == left_border)
				{
					dir = 3;
					prex--;
					down_border--;
				}
				else prey--;
				break;
			}
			case 3:
			{
				res[prex][prey] = count++;
				if (prex == up_border)
				{
					dir = 0;
					prey++;
					left_border++;
				}
				else prex--;
				break;
			}
			default: break;
			}
		}
		return res;

	}
};