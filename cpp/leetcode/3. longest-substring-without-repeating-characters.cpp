#include "public.h"

//16ms 98.24%

//滑动窗口

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ssize = s.size();
		unordered_map<char, int> um;
		int start_index = 0;   //开始下标
		int max_length = 0;
		for (int i = 0; i < ssize; i++)
		{
			char ch = s[i];

			if (um.find(ch) == um.end())
				um.insert(pair<char, int>{ch, i});
			else
			{
				if (um[ch] >= start_index)
				{
					max_length = max(max_length, (i - start_index));
					start_index = um[ch] + 1;
					um[ch] = i;
				}
				else
				{
					um[ch] = i;
				}
			}
		}
		max_length = max(max_length, (ssize - start_index));

		return max_length;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->lengthOfLongestSubstring("abcabcbb");

	return 0;
}