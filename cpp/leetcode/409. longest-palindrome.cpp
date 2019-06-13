#include "public.h"

//8ms, 89.94%

//Brute force, this is just an easy problem
// only need count in um, then find if there occur odd value!

class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> um;
		for (auto is : s) um[is]++;

		bool needodd = false;
		int halfres = 0;
		for (unordered_map<char, int>::iterator iter = um.begin(); iter != um.end(); ++iter)
		{
			if ((iter->second % 2) == 1) needodd = true;
			halfres += iter->second / 2;
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