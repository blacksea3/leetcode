#include "public.h"

/*
���� n �����ԡ� ��ÿһ�������У���һ���������Ǳȵڶ�������С��

���ڣ����Ƕ���һ�ָ����ϵ�����ҽ��� b < c ʱ������(c, d) �ſ��Ը��� (a, b) ���档������������ʽ������һ����������

����һ���������ϣ��ҳ��ܹ��γɵ���������ĳ��ȡ��㲻��Ҫ�õ����е����ԣ���������κ�˳��ѡ�����е�һЩ���������졣

*/

class Solution {
private:
	static bool m_cmp_lessthan(const vector<int>& p1, const vector<int> p2)
	{
		if (p1[0] < p2[0]) return true;
		else if (p1[0] > p2[0]) return false;
		else
		{
			if (p1[1] <= p2[1]) return true;
			else return false;
		}
	}


public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), m_cmp_lessthan);

		map<int, int> mm;

		//�������µĲ��������Ǽ�¼pairs�ĵڶ�����Ϊkey����ǰ����������ĳ���Ϊvalue

		for (auto pre : pairs)
		{
			int hismaxlen = 0;
			for (map<int, int>::iterator iter = mm.begin(); iter != mm.end(); ++iter)
			{
				if (iter->first < pre[0])
					hismaxlen = max(hismaxlen, iter->second);
				else break;
			}
			mm[pre[1]] = max(mm[pre[1]], hismaxlen + 1);
		}

		int resmax = 0;
		for (auto iter = mm.begin(); iter != mm.end(); ++iter)
			resmax = max(resmax, iter->second);

		return resmax;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> pairs = { {1,2},{2,3},{3,4} };
	cout << s->findLongestChain(pairs);
	return 0;
}


