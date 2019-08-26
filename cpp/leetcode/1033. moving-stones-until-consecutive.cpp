#include "public.h"

//8ms, 76.57%
//Ä£ÄâÅĞ¶Ï

class Solution {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		//¸øabcÅÅĞò

		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		if (b > c)
		{
			int temp = b;
			b = c;
			c = temp;
		}
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		//OKÁËÅÅĞòÍê±Ï

		int mintimes = 0;

		if (((a + 1) == b) && ((b + 1) == c)) return vector<int>{0, 0};

		if ((a + 2) == b) mintimes = 1;
		else if ((b + 2) == c) mintimes = 1;
		else
		{
			if ((a + 1) != b) mintimes++;
			if ((b + 1) != c) mintimes++;
		}

		int maxtimes;
		maxtimes = (b - a - 1) + (c - b - 1);
		return vector<int>{mintimes, maxtimes};
	}
};
