#include "public.h"

//
//»¬¶¯´°¿Ú


class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int sSize = s.size();
		vector<int> de(sSize, 0);

		for (int i = 0; i < sSize; ++i)
		{
			de[i] = abs(s[i] - t[i]);
		}

		int lastR = -1;
		int preI = 0;
		int preS = 0;
		int res = 0;

		while (preI < sSize)
		{
			preS += de[preI];
			if (preS <= maxCost)
			{
				res = max(res, (preI - lastR));
			}
			else
			{
				while (preS > maxCost && lastR < preI)
				{
					preS -= de[lastR + 1];
					lastR++;
				}
				res = max(res, (preI - lastR));
			}
			preI++;
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->equalSubstring("abcd", "bcdf", 3) << endl;
	cout << s->equalSubstring("abcd", "cdef", 3) << endl;
	cout << s->equalSubstring("abcd", "acde", 0) << endl;
	return 0;
}
*/
