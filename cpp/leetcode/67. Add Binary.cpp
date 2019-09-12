#include "public.h"

//0ms, 100%
//ģ��, �������a��b����, ����ȵ�������res, Ȼ�󵹹���

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
			res.push_back(sum + '0');
		}
		if (carry) res.push_back('1');
		reverse(res.begin(), res.end());
		return res;
	}
};
