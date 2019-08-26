#include "public.h"

//8ms, 63.24%
//递归+备忘录
//注意精度要求1e-6, N非常大时结果将趋近于1, 通过计算可以知道N>4800时答案是1

class Solution {
private:
	unordered_map<int, double> um;
	double recu(int a, int b)
	{
		if (um.find(10000 * a + b) != um.end()) return um[10000 * a + b];
		else
		{
			double res;
			if (a <= 0 && b > 0) res = 1.0;
			else if (a <= 0 && b <= 0) res = 0.5;
			else if (a > 0 && b <= 0) res = 0;
			else
			{
				res = 0.25*(recu(a - 100, b) + recu(a - 75, b - 25) + recu(a - 50, b - 50) + recu(a - 25, b - 75));
				um[10000 * a + b] = res;
			}
			return res;
		}
	}

public:
	double soupServings(int N) {
		return recu(N, N);
	}
};
