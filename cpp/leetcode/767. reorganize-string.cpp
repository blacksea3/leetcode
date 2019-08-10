#include "public.h"

//0ms, 100%
//ͳ�ƴ�Ƶ�ҳ�����, ��������ֻҪ<= ������������+1�Ϳ���

class Solution {
public:
	string reorganizeString(string S) {
		vector<int> v(26, 0);
		for (auto& iis : S)
		{
			v[iis - 'a']++;
		}

		vector<int>::iterator maxiter = max_element(v.begin(), v.end());

		if (*maxiter <= (S.size() - (*maxiter) + 1))
		{
			int absloc = maxiter - v.begin();
			//�ȷ�����, Ȼ���������
			int preloc = 0;
			string res = S;
			for (; preloc < S.size();)
			{
				if (v[absloc] > 0)
				{
					res[preloc] = absloc + 'a';
					v[absloc]--;
					preloc += 2;
				}
				else break;
			}
			//�����0��ʼ��, ÿ�θ�һ��
			//�������ٴ�1��ʼ��
			int otherchar = 0;
			for (; preloc < S.size();)
			{
				if (otherchar == absloc) otherchar++;
				if (v[otherchar] > 0)
				{
					res[preloc] = otherchar + 'a';
					v[otherchar]--;
					preloc += 2;
				}
				else
				{
					otherchar++;
				}
			}
			preloc = 1;
			for (; preloc < S.size(); )
			{
				if (otherchar == absloc) otherchar++;
				if (v[otherchar] > 0)
				{
					res[preloc] = otherchar + 'a';
					v[otherchar]--;
					preloc += 2;
				}
				else
				{
					otherchar++;
				}
			}
			return res;
		}
		else return "";
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->reorganizeString("zhmyo");
	//auto res = s->reorganizeString("aaaaaaabcdees");
	return 0;
}
*/
