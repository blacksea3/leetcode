#include "public.h"

//56ms, 94.65%
//�����ɷ���: �ȷŴ��: ��������ұ���: ����һ��D��һ������, ������һ��D��һ���δ��..
//Ȼ����ұ��������:����һ��I�ŵ�ǰ����...ֱ������

class Solution {
public:
	vector<int> diStringMatch(string S) {
		vector<int> res(S.size() + 1);
		int pre = S.size();

		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == 'D') res[i] = pre--;
		}
		res[S.size()] = pre--;
		for (int i = S.size() - 1; i >= 0; --i)
		{
			if (S[i] == 'I') res[i] = pre--;
		}
		return res;
	}
};
