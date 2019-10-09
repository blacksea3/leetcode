#include "public.h"

//12ms, 73.01%
//dp, ��vector�洢, ��¼��char��β�����ַ����ĳ���
//���res�ø�������������, ����sum������

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		if (p.empty()) return 0;

		vector<int> length(256, 0);  //��ʵֻ���м�a-z��Ч
		//int res = 0;
		int oldlen = 1;
		length[p[0]]++;

		for (int loc = 1; loc < p.size(); ++loc)
		{
			if (p[loc] - p[loc - 1] == 1 || p[loc] - p[loc - 1] == -25)
			{
				if (length[p[loc]] <= oldlen)
				{
					oldlen++;
					length[p[loc]] = oldlen;
				}
				else oldlen++;
			}
			else
			{
				if (length[p[loc]] == 0)
				{
					length[p[loc]] = 1;
					oldlen = 1;
				}
				else oldlen = 1;
			}
		}
		return accumulate(length.begin() + 'a', length.begin() + 'z' + 1, 0);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->findSubstringInWraproundString("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	return 0;
}
*/
