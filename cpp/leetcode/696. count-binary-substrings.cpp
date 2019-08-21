#include "public.h"

//40ms, 72.39%
//数连续的0/1的数量
//如果前一个连续数量是x, 后一个是y, 那么结果增加min(x, y)

class Solution {
public:
	int countBinarySubstrings(string s) {
		int countzero = 0;
		int countone = 0;
		bool isOldZero = true;
		int res = 0;

		for (auto& iter_s : s)
		{
			if (isOldZero)
			{
				if (iter_s == '0')
					countzero++;
				else
				{
					res += min(countzero, countone);
					countone = 1;
					isOldZero = false;
				}
			}
			else
			{
				if (iter_s == '1')
					countone++;
				else
				{
					res += min(countzero, countone);
					countzero = 1;
					isOldZero = true;
				}
			}
		}
		res += min(countzero, countone);
		return res;
	}
};
