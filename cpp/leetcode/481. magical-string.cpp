#include "public.h"

//24ms, 54.35%
//模拟

class Solution {
public:
	int magicalString(int n) {
		string bigstr = "122";
		int res = 1;
		int realIndex = 3;
		int countIndex = 2;
		bool isCurrentOne = true;

		while (realIndex < n)
		{
			if (isCurrentOne)
			{
				if (bigstr[countIndex++] == '1')
				{
					bigstr += "1";
					realIndex += 1;
					res += 1;
				}
				else
				{
					bigstr += "11";
					realIndex += 2;
					res += 2;
				}
				isCurrentOne = false;
			}
			else
			{
				if (bigstr[countIndex++] == '1')
				{
					bigstr += "2";
					realIndex += 1;
				}
				else
				{
					bigstr += "22";
					realIndex += 2;
				}
				isCurrentOne = true;
			}
		}
		//去掉可能多加的一个末尾的1
		if (realIndex > n && bigstr[bigstr.size() - 1] == '1') res--;
		return res;
	}
};
