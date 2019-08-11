#include "public.h"

//
//扫一次text得到各种字符的出现次数
//然后扫, 如果当前数字种类>=3, 则去掉左边的...

class Solution {
public:
	int maxRepOpt1(string text) {
		vector<int> v(26, 0);
		for (auto& t : text) v[t-'a']++;

		char c1 = '!';
		char c2 = '!';
		int n1 = 0;
		int n2 = 0;

		int leftloc = 0;
		int preloc = 0;
		int res = 0;
		while (preloc < text.size())
		{
			if (text[preloc] == c1)
			{
				//给n1加
				n1++;
				if (n2 > 1 && n1 > 1)  //去掉左侧的
				{
					while (n2 > 1 && n1 > 1)
					{
						if (text[leftloc] == c1)
						{
							n1--;
						}
						else
						{
							n2--;
						}
						leftloc++;
					}
				}

			}
			else if (text[preloc] == c2)
			{
				//给n2加
				n2++;
				if (n2 > 1 && n1 > 1)  //去掉左侧的
				{
					while (n2 > 1 && n1 > 1)
					{
						if (text[leftloc] == c1)
						{
							n1--;
						}
						else
						{
							n2--;
						}
						leftloc++;
					}
				}
			}
			else if (c1 == '!')
			{
				c1 = text[preloc];
				n1 = 1;
			}
			else if (c2 == '!')
			{
				c2 = text[preloc];
				n2 = 1;
			}
			else
			{
				//去掉左侧的
				while (n1 > 0 && n2 > 0)
				{
					if (text[leftloc] == c1)
					{
						n1--;
						if (n1 == 0) c1 = '!';
					}
					else
					{
						n2--;
						if (n2 == 0) c2 = '!';
					}
					leftloc++;
				}
				if (c1 == '!')
				{
					c1 = text[preloc];
					n1 = 1;
				}
				else if (c2 == '!')
				{
					c2 = text[preloc];
					n2 = 1;
				}
			}

			if (n1 == 0)
			{
				res = max(res, n2);
			}
			else if (n2 == 0)
			{
				res = max(res, n1);
			}
			else if (n1 > n2)
			{
				res = max(res, min(v[c1 - 'a'], n1 + 1));
			}
			else if (n2 > n1)
			{
				res = max(res, min(v[c2 - 'a'], n2 + 1));
			}
			else
			{
				res = max(res, min(v[c1 - 'a'], n1 + 1));
				res = max(res, min(v[c2 - 'a'], n2 + 1));
			}
			if (res == 6)
				int i = 1;
			preloc++;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->maxRepOpt1("idhajechdbdbeichdjjddefdjicidieciebcjfcgbfgfabhbejhbediebagjhgjdafiaeiggjhdajejcacecifigbcedeejbgbdi") << endl;
	

	//cout << s->maxRepOpt1("aabaaabaaaba") << endl;
	//cout << s->maxRepOpt1("aaabbaaa") << endl;
	//cout << s->maxRepOpt1("ababa") << endl;
	return 0;
}
*/
