#include "public.h"

//12ms, 95.64%
//��ͨ��������, ��ͳ�Ƹ����ַ����ִ���, Ȼ��һ��ɨ��s

class Solution {
public:
	string minWindow(string s, string t) {
		int minLen = INT_MAX;
		string res = "";

		int lastRightIndex = -1;
		int preIndex = 0;

		vector<int> tCount(128, 0);
		for (auto& iter_t : t)
		{
			tCount[iter_t]++;
		}
		int tSize = t.size();

		vector<int> sCount(128, 0);
		int sMatch = 0;
		while (preIndex < s.size())
		{
			if (++sCount[s[preIndex]] <= tCount[s[preIndex]])
			{
				sMatch++;
				if (sMatch == tSize)
				{
					//OK��, ׼�����ز���lastRightIndex֮����ַ�
					while (true)
					{
						if (--sCount[s[lastRightIndex + 1]] < tCount[s[lastRightIndex + 1]])
						{
							sMatch--;
							if (preIndex - lastRightIndex < minLen)
							{
								minLen = preIndex - lastRightIndex;
								res = s.substr(lastRightIndex + 1, preIndex - lastRightIndex);
							}
							lastRightIndex++;
							break;
						}
						else
						{
							lastRightIndex++;
						}
					}
				}
			}
			preIndex++;
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	string res1 = s->minWindow("cabwefgewcwaefgcf", "cae");
	string res = s->minWindow("ADOBECODEBANC","ABC");
	return 0;
}
*/
