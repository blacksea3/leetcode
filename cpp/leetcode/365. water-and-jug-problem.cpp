#include "public.h"

//4ms, 86.55%
//z=ax+by && z <= (x+y)
//a和b可能有负的, 负表示倒掉那个桶, 正表示放满某个桶
//除1 1外不可能都是正整数

class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (z == 0) {
			return true;
		}
		if (x + y < z) {
			return false;
		}
		if (x < y) {  //使得初始条件: x大于y, 以进行接下来的辗转相除法
			swap(x, y);
		}
		if (y > 0) {
			int r = x % y;
			while (r > 0) {
				x = y;
				y = r;
				r = x % y;
			}
			return z % y == 0;
		}
		return z % x == 0;
	}
};
