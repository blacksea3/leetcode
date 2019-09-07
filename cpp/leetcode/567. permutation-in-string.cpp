#include "public.h"

//8ms, 96.67%
//滑动窗口, 先统计s1字符类型, 然后扫描s2

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> count(26, 0);

		for (auto& iter_s1 : s1)
		{
			count[iter_s1 - 'a']++;
		}
		int s1Size = s1.size();
		int preMatch = 0;

		int lastRight = -1;   //特别注意: 历史上使用的字符串左边界等于lastRight + 1
		int index = 0;
		while (index < s2.size() && preMatch < s1Size)
		{
			//先看是否需要移动左边界(上一个右边界)
			while (lastRight + 1 < index && count[s2[index] - 'a'] == 0)
			{
				count[s2[lastRight + 1] - 'a']++;
				preMatch--;
				lastRight++;
			}

			//判断当前index
			if (count[s2[index] - 'a'] == 0)
			{
				lastRight++;
			}
			else
			{
				count[s2[index] - 'a']--;
				preMatch++;
			}
			index++;
		}
		return (preMatch == s1Size);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->checkInclusion("ab", "eidboaoo");
	return 0;
}
*/
