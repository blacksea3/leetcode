#include "public.h"

//4ms, 97.32%
//分治:
//设置这样的递归函数: 统计当前范围内的字符频数, 然后先左后右截断多余的出现频数小于k的字符, 若截断至字符长度小于k则直接返回0
//   否则: 对中间任意位置进行判断, 如果中间某个字符出现频数小于k, 则截断它, return 左右子串的结果最大值
//   如果中间字符频数都大于等于k, 则返回当前字符串长度

class Solution {
private:
	int recu(const string& s, int start, int end, int k)
	{
		if (end - start + 1 < k) return 0;
		//统计频数
		vector<int> nums(26, 0);
		for (int i = start; i <= end; ++i)
		{
			nums[s[i] - 'a']++;
		}

		//截断
		while ((end - start + 1 >= k) && (nums[s[start] - 'a'] < k)) start++;
		while ((end - start + 1 >= k) && (nums[s[end] - 'a'] < k)) end--;
		if (end - start + 1 < k) return 0;

		//中间判断
		for (int i = start + 1; i < end; ++i)
		{
			if (nums[s[i] - 'a'] < k) return max(recu(s, start, i - 1, k), recu(s, i + 1, end, k));
		}
		return end - start + 1;
	}

public:
	int longestSubstring(string s, int k) {
		if ((k == 0) || (s.size() < k)) return 0;
		else return recu(s, 0, s.size() - 1, k);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->longestSubstring("aaabb", 3);
	return 0;
}*/
