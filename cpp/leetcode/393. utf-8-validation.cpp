#include "public.h"

//16ms, 90.11%
//模拟/验证

class Solution {
public:
	bool validUtf8(vector<int>& data) {
		if (data.size() == 0) return true;

		int loc = 0;
		while (loc < data.size())
		{
			//判断第一个数字
			int first = data[loc] % 256;
			int maysize = 0;
			if (first >= 248) return false;
			else if (first >= 240) maysize = 4;
			else if (first >= 224) maysize = 3;
			else if (first >= 192) maysize = 2;
			else if (first <= 127) maysize = 1;
			else return false;

			//判断长度
			if (loc + maysize > data.size()) return false;

			//判断其他数字
			for (int i = loc + 1; i < (loc + maysize); ++i)
			{
				if ((data[i] <= 127) || (data[i] >= 192)) return false;
			}

			//移动至下一个unicode字符
			loc += maysize;
		}

		return true;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> data = { 197,130,1 };
	auto res = s->validUtf8(data);
	return 0;
}*/
