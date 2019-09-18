#include "public.h"

//8ms, 91.88%
//模拟, 左右同时向中间扫

class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;

		while (left < right)
		{
			while (left < right && !isdigit(s[left]) && !isalpha(s[left]))
			{
				left++;
			}
			while (left < right && !isdigit(s[right]) && !isalpha(s[right]))
			{
				right--;
			}
			if (toupper(s[left]) != toupper(s[right]))
			{
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};
