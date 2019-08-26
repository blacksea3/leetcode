#include "public.h"

//
//暴力
//寻找连续abc的位置, 然后去掉它们

class Solution {
public:
	bool isValid(string S) {
		if (S.size() % 3) return false;

		int loc = 0;
		bool isloopflag = true;
		while (!S.empty())
		{
			if (loc >= S.size() - 2)
			{
				if (isloopflag) break;
				else
				{
					loc = 0;
					isloopflag = true;
				}
			}
			if (S[loc] == 'a' && S[loc + 1] == 'b' && S[loc + 2] == 'c')
			{
				S.erase(S.begin() + loc);
				S.erase(S.begin() + loc);
				S.erase(S.begin() + loc);
				isloopflag = false;
			}
			else loc++;
		}
		return (S.empty()) ? true : false;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//auto res = s->isValid("aabbcc");
	auto res = s->isValid("abc");
	return 0;
}
*/
