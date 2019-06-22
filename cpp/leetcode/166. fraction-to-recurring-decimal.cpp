#include "public.h"

//纯数学题,极其绕人 8ms, 75.94%

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		//除下去
		//出现0就强制退出
		//否则等待出现重复的循环小数

		long long fnumerator = numerator;
		long long fdenominator = denominator;
		//傻逼大数字
		if ((fnumerator == INT_MIN) && (fdenominator == -1))
			return "2147483648";
		else if (fnumerator%fdenominator == 0)
			return to_string(fnumerator / fdenominator);
		else
		{
			string res1 = "";
			if (double(numerator) / double(denominator) < 0)
			{
				if (numerator / denominator == 0)
					res1 += "-";
			}
			res1 += to_string(fnumerator / fdenominator);
			string res2 = "";
			fnumerator %= fdenominator;
			unordered_map<long long, int> his = {};
			his[fnumerator] = -1;
			int loc = 0;
			while (true)
			{
				fnumerator *= 10;
				long long yushu = fnumerator % fdenominator;
				if (yushu == 0)
				{
					res2 += to_string(abs(fnumerator / fdenominator));
					return res1 + "." + res2;
				}
				else
				{
					if (his.find(yushu) != his.end())
					{
						//结束了
						res2 += to_string(abs(fnumerator / fdenominator));
						return res1 + "." + res2.substr(0, his[yushu] + 1) + "(" + res2.substr(his[yushu] + 1) + ")";
					}
					else
					{
						res2 += to_string(abs(fnumerator / fdenominator));
						his[yushu] = loc++;
						fnumerator = yushu;
					}
				}
			}
			return "";  //dump
		}
	}
};
