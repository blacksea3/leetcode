#include "public.h"

//4ms, 86.49%
//simple solution

class Solution {
public:
	string toHex(int num) {
		unsigned int ui = num;
		if (ui == 0) return "0";
		string res = "";
		while (ui > 0)
		{
			char temp = (ui % 16 < 10) ? ui % 16 + '0' : ui % 16 - 10 + 'a';
			res.insert(res.begin(), temp);
			ui /= 16;
		}
		return res;
	}
};
