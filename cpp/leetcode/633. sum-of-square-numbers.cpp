#include "public.h"

//300ms, 5.06%
//����1��(int)sqrt(c), ��¼���ֵ�ƽ�����ҷ���set, ���set���Ѿ�����,��OK
//�������: c/2������ȫƽ����

class Solution {
public:
	bool judgeSquareSum(int c) {
		if (c % 2 == 0 && ((int)(sqrt(c / 2))*(int)(sqrt(c / 2)) == c/2)) return true;

		unordered_set<int> memory;

		for (int i = 0; i <= (int)sqrt(c); ++i)
		{
			if (memory.find(c - i * i) == memory.end()) memory.insert(i*i);
			else return true;
		}
		return false;
	}
};
