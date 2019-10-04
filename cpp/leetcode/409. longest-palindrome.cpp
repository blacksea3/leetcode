#include "public.h"

//4ms, 90.69%
//暴力
//统计所有的出现次数的一半之和(包括偶数和奇数), 以及是否有奇数出现次数

class Solution {
public:
	int longestPalindrome(string s) {
		vector<int> v(256, 0);
		for (auto& is : s) v[is]++;

		bool needodd = false;
		int halfres = 0;
		for (char c = 'a'; c <= 'z'; ++c)
		{
			if ((v[c] % 2) == 1) needodd = true;
			halfres += v[c] / 2;
		}
		for (char c = 'A'; c <= 'Z'; ++c)
		{
			if ((v[c] % 2) == 1) needodd = true;
			halfres += v[c] / 2;
		}

		return (needodd) ? halfres*2 + 1 : halfres*2;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->longestPalindrome("abccccdd");
	return 0;
}
*/