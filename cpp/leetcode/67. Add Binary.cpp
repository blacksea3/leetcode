#include "public.h"

//12ms, 65.75%

//simple algorithm, traverse a and b,
//just pay attention that carry and a.size()!=b.size()

class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		int carry = 0;
		for (int al = a.size() - 1, bl = b.size() - 1; al >= 0 || bl >= 0; --al, --bl)
		{
			int av = (al >= 0) ? a[al] - '0' : 0;
			int bv = (bl >= 0) ? b[bl] - '0' : 0;
			int sum = (av + bv + carry) % 2;
			carry = (av + bv + carry) / 2;
			res.insert(res.begin(), sum + '0');
		}
		if (carry) res.insert(res.begin(), '1');
		return res;
	}
};
