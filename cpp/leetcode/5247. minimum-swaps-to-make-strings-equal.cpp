#include "public.h"

//
//统计xy和yx对

class Solution {
public:
	int minimumSwap(string s1, string s2) {
		int xy = 0;
		int yx = 0;

		for (int i = 0; i < s1.size(); ++i)
		{
			if (s1[i] != s2[i])
			{
				if (s1[i] == 'x') xy++;
				else yx++;
			}
		}
		int res = 0;
		res += xy / 2;
		xy %= 2;
		res += yx / 2;
		yx %= 2;

		if (xy == yx) return res + xy * 2;
		else return -1;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->minimumSwap("xx", "yy") << endl;
	cout << s->minimumSwap("xy", "yx") << endl;
	cout << s->minimumSwap("xx", "xy") << endl;
	cout << s->minimumSwap("xxyyxyxyxx", "xyyxyxxxyx") << endl;
	return 0;
}
*/
