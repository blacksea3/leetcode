#include "public.h"

//12ms, 95.64%
//普通滑动窗口, 先统计各个字符出现次数, 然后一遍扫描s

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
					//OK了, 准备撤回部分lastRightIndex之后的字符
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
