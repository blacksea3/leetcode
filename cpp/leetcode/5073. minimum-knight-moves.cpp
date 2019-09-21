#include "public.h"

//
//超级找规律
//参考: https://www.cnblogs.com/zhengguiping--9876/p/4947957.html

class Solution {
public:
	int minKnightMoves(int x, int y) {
		x = abs(x);
		y = abs(y);
		if (x > y)swap(x, y);

		if (y == x * 2)
		{
			return (y + x) / 3;
		}
		if (y <= 2 * x)
		{
			if (x == 1 && y == 1)
				return 2;
			else if (x == 2 && y == 2)
				return 4;
			else
				return (x + y) / 3 + (x + y) % 3;
		}
		else
		{
			int ans = x;
			int c = (y - 2 * x) % 4;
			ans += c;
			ans += (y - 2 * x - c) / 2;
			if (y == 1 && x == 0)
			{
				ans = 3;
			}
			return ans;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->minKnightMoves(2, 1);
	return 0;
}
*/
