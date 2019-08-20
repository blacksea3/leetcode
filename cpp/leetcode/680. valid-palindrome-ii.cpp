#include "public.h"

//120ms, 32.34%
//双指针, 从两侧扫, 如果不一样了, 尝试删除一个并判断

class Solution {
private:
	bool IsvalidPalindrome(string s)
	{
		int leftIndex = 0;
		int rightIndex = s.size() - 1;
		while (leftIndex < rightIndex)
		{
			if (s[leftIndex] == s[rightIndex])
			{
				leftIndex++;
				rightIndex--;
			}
			else
				return false;
		}
		return true;
	}

public:
	bool validPalindrome(string s) {
		int leftIndex = 0;
		int rightIndex = s.size() - 1;
		bool isDeleted = false;

		while (leftIndex < rightIndex)
		{
			if (s[leftIndex] == s[rightIndex])
			{
				leftIndex++;
				rightIndex--;
			}
			else
			{
				if (isDeleted)
				{
					return false;
				}
				else
				{
					//拆出两个情况
					return IsvalidPalindrome(s.substr(leftIndex, rightIndex - leftIndex)) ||
						IsvalidPalindrome(s.substr(leftIndex + 1, rightIndex - leftIndex));
				}
			}
		}
		return true;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
	return 0;
}
*/
