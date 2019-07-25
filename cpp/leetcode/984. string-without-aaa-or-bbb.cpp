#include "public.h"

//4ms, 86.92%
//��1:1����, Ȼ���������ٵ��ַ��嵽����ַ���

class Solution {
public:
	string strWithout3a3b(int A, int B) {
		string res = "";

		if (A > B)
		{
			while (A < 2 * B)
			{
				res += "a";
				res += "b";
				A--;
				B--;
			}
			while (A > 1 && B > 0)
			{
				res += "aa";
				res += "b";
				A -= 2;
				B--;
			}
			if (A > 0)
			{
				while (A > 0)
				{
					res += "a";
					A--;
				}
			}
			else
			{
				while (B > 0)
				{
					res += "b";
					B--;
				}
			}
		}
		else
		{
			while (B < 2 * A)
			{
				res += "b";
				res += "a";
				B--;
				A--;
			}
			while (B > 1 && A > 0)
			{
				res += "bb";
				res += "a";
				B -= 2;
				A--;
			}
			if (A > 0)
			{
				while (A > 0)
				{
					res += "a";
					A--;
				}
			}
			else
			{
				while (B > 0)
				{
					res += "b";
					B--;
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res1 = s->strWithout3a3b(1, 2);
	auto res2 = s->strWithout3a3b(4, 1);
	return 0;
}
*/
