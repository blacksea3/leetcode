#include "public.h"

//60ms, 44.41%
//̰��
//��θ������
//����������
//��С�ı����ܸ�θ����С�ĺ���, �Ǿ͸�; ������һ������
//ֱ��û�к��ӻ��߱��ɽ���

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int gloc = 0;
		int sloc = 0;
		int res = 0;
		while (gloc < g.size() && sloc < s.size())
		{
			if (g[gloc] <= s[sloc])
			{
				res++;
				gloc++;
				sloc++;
			}
			else
			{
				sloc++;
			}
		}
		return res;
	}
};
