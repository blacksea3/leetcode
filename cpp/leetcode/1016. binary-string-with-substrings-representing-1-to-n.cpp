#include "public.h"

//4ms, 93.39%
//这里的子串是连续的...

class Solution {
private:
	//默认正整数
	string dec2bin(int decVal)
	{
		string value = "";
		while (decVal > 0)
		{
			if (decVal % 2)
				value = '1' + value;
			else
				value = '0' + value;
			decVal = decVal / 2;
		}
		return value;
	}

public:
	bool queryString(string S, int N) {
		if (N >= 2048) return false; //这样将必须有至少1024个同样的长度, 不同内容的二进制字符串, 这不可能在S中出现
		else
		{
			//直接暴力
			for (int i = 1; i <= N; ++i)
				if (S.find(dec2bin(i)) == S.npos) return false;
			return true;
		}
	}
};