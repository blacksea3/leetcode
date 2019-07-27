#include "public.h"

//164ms, 61.70%
//统计, 然后注意判断顺序, 挨个判断
//统计结果直接放入vector<int> v(200001, 0)中, 其中下标等于实际值+100000

class Solution {
public:
	bool canReorderDoubled(vector<int>& A) {
		vector<int> v(200001, 0);

		for (auto& a : A)
			v[a + 100000]++;

		//负数
		for (int i = 0; i < 100000; ++i)
		{
			if (v[i] > 0)
			{
				if (i % 2) return false;
				else
				{
					int temp = i / 2 + 50000;
					if (v[temp] < v[i]) return false;
					else v[temp] -= v[i];
				}
			}
		}

		//正数
		for (int i = 200000; i >= 100001; --i)
		{
			if (v[i] > 0)
			{
				if (i % 2) return false;
				else
				{
					int temp = i / 2 + 50000;
					if (v[temp] < v[i]) return false;
					else v[temp] -= v[i];
				}
			}
		}
		return true;
	}
};
