#include "public.h"

//simple solution 4ms, 87.86%
//数学问题

class Solution {
public:
	string convertToTitle(int n) {
		//不停地除以26
		//这是正整数!
		string res = "";
		while (n > 0)
		{
			if (n % 26 == 0)
			{
				res.insert(res.begin(), 'Z');
				n /= 26;
				n--;
			}
			else
			{
				res.insert(res.begin(), n % 26 + 'A' - 1);
				n /= 26;
			}
		}
		return res;
	}
};

