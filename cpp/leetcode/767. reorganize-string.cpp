#include "public.h"

//0ms, 100%
//统计词频找出众数, 他的数量只要<= 其他数字数量+1就可以

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
			//先放众数, 然后放其他数
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
			//坐标从0开始放, 每次隔一个
			//放完了再从1开始放
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
