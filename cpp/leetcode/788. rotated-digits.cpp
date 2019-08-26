#include "public.h"

//280ms, 5.41%
//不能全是0/8/1, 可取总数: 0 1 2 5 6 8 9
//个位数: 2 5 6 9 : 4
//十位数: 6*7 - 2*3
//百位数: 6*7*7 - 2*3*3
//千位数: 6*7*7*7 - 2*3*3*3

//考虑到N<=10000, 可以暴力

class Solution {
private:
	bool canrotated(int r)
	{
		set<int> s;
		while (r > 0)
		{
			s.insert(r % 10);
			r /= 10;
		}

		//判断s的数字们
		if (s.find(3) != s.end() || s.find(4) != s.end() || s.find(7) != s.end()) return false;
		if (s.find(2) == s.end() && s.find(5) == s.end() && s.find(6) == s.end() && s.find(9) == s.end()) return false;
		return true;
	}


public:
	int rotatedDigits(int N) {
		int res = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (canrotated(i)) res++;
		}
		return res;
	}
};
