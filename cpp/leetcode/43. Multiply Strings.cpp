#include "public.h"

//12ms, 95.49%

//brute force

class Solution {
public:
	string multiply(string num1, string num2) {
		//special input
		//assume that both num1 and num2 are not empty
		if ((num1 == "0") || (num2 == "0")) return "0";
		
		int num2size = num2.size();
		int num1size = num1.size();

		string res(num1size + num2size, '0');

		for (int i = num1size - 1; i >= 0; --i)
		{
			int carry = 0;
			for (int j = num2size - 1; j >= 0; j--) {
				int temp = (res[j + i + 1] - '0') +
					(num1[i] - '0') * (num2[j] - '0') + carry;
				res[j + i + 1] = temp % 10 + '0';
				carry = temp / 10;
			}
			res[i] += carry;
		}

		//remove the begin '0'
		int loc = 0;
		while (res[loc] == '0')   //don't worry index overflow error, all '0' condition only means '0'
			                      //this is judged at the beginning
			++loc;
		res = res.substr(loc);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	string res = s->multiply("123", "456");
	return 0;
}
