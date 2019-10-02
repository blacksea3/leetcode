#include "public.h"

//0ms, 100%
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
				res.push_back('Z');
				n /= 26;
				n--;
			}
			else
			{
				res.push_back(n % 26 + 'A' - 1);
				n /= 26;
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
