#include "public.h"

//36ms, 27.43%
//̰��:
//����ȫ�����: ż��ȫ���ұ�,
//����˳��:�ݹ鱾����, ���շ���ֵÿ��*2-1��, ż��˳��:�ݹ鱾����, ���շ���ֵÿ��*2��

class Solution {
public:
	vector<int> beautifulArray(int N) {
		if (N == 1) return { 1 };
		else
		{
			vector<int> res;
			vector<int> odds = beautifulArray((N + 1) / 2);
			for (int i = 0; i < odds.size(); ++i)
			{
				res.push_back(2 * odds[i] - 1);
			}

			vector<int> evens = beautifulArray(N / 2);
			for (int i = 0; i < evens.size(); ++i)
			{
				res.push_back(2 * evens[i]);
			}
			return res;
		}
	}
};
