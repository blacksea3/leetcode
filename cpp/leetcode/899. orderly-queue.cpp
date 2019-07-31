#include "public.h"

//8ms, 69.23%
//K==1, 环序列, 查找字典序最小的那个
//K>=2, 因为如果前K个字符无序, 则总可以把不满足的扔到后面去, 都有序则全部按顺序扔, 这样无限制次数总是能够整体完全有序的

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