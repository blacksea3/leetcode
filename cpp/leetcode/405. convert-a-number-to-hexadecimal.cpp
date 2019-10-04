#include "public.h"

//4ms, 75.06%
//Ä£Äâ

class Solution {
private:
	const char table[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
public:
	string toHex(int num) {
		unsigned int ui = num;
		if (ui == 0) return "0";
		string res = "";
		while (ui > 0)
		{
			res.push_back(table[ui % 16]);
			ui /= 16;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
