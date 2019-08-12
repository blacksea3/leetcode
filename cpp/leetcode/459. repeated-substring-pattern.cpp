#include "public.h"

//36ms, 84.52%
//找到s长度的所有因数, 然后乘过去

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int ssize = s.size();
		for (int length = 1; length <= ssize/2; ++length)
		{
			if (ssize%length) continue;
			//判断
			bool isgood = true;
			string first = s.substr(0, length);
			for (int i = length; i < s.size(); i += length)
			{
				if (first != s.substr(i, length))
				{
					isgood = false;
					break;
				}
			}
			if (isgood) return true;
		}
		return false;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->repeatedSubstringPattern("abacababacab") << endl;
	cout << s->repeatedSubstringPattern("aabaaba") << endl;
	cout << s->repeatedSubstringPattern("bb") << endl;
	cout << s->repeatedSubstringPattern("b") << endl;
	return 0;
}
*/
