#include "public.h"

//4ms, 96.88%
//Ä£Äâ

class Solution {
public:
	string addStrings(string num1, string num2) {
		string res = "";
		bool c = false;

		int l1 = num1.size() - 1;
		int l2 = num2.size() - 1;

		while (l1 >= 0 && l2 >= 0)
		{
			int s = num1[l1--] + num2[l2--] - '0';
			if (c) s++;
			if (s > '9')
			{
				c = true;
				s -= 10;
			}
			else
			{
				c = false;
			}
			res.push_back(s);
		}
		while ((c) || (l1 >= 0) || (l2 >= 0))
		{
			int s;
			if (l1 >= 0) s = num1[l1--];
			else if (l2 >= 0) s = num2[l2--];
			else s = '0';
			if (c) s++;
			if (s > '9')
			{
				c = true;
				s -= 10;
			}
			else
			{
				c = false;
			}
			res.push_back(s);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
