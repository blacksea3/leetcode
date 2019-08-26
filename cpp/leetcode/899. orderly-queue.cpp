#include "public.h"

//8ms, 69.23%
//K==1, ������, �����ֵ�����С���Ǹ�
//K>=2, ��Ϊ���ǰK���ַ�����, ���ܿ��԰Ѳ�������ӵ�����ȥ, ��������ȫ����˳����, ���������ƴ��������ܹ�������ȫ�����

class Solution {
public:
	string orderlyQueue(string S, int K) {
		if (K >= 2)
		{
			sort(S.begin(), S.end());
			return S;
		}
		else
		{
			string mins = S;
			int times = 1;
			while (times < S.size())
			{
				char c = S[0];
				S.erase(S.begin());
				S.push_back(c);
				mins = min(mins, S);
				times++;
			}
			return mins;
		}
	}
};