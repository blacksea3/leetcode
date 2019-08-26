#include "public.h"

//4ms, 88.89%
//���������Ҫ���: ���������û�˻�������������һ�����һ��������, �������������ж��, ��ô��������������

class Solution {
public:
	int minAddToMakeValid(string S) {
		int leftcount = 0;
		int res = 0;

		for (auto& iis : S)
		{
			if (iis == ')')
			{
				if (leftcount == 0) res++;
				else leftcount--;
			}
			else leftcount++;
		}
		res += leftcount;
		return res;
	}
};
