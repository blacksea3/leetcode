#include "public.h"

//12ms, 90.42%

class Solution {
public:
	bool isPalindrome(string s) {
		//左右同时向中间扫

		int left = 0;
		int right = s.size() - 1;

		char diff = 'a' - 'A';

		while (left < right)
		{
			if (!isdigit(s[left]) && !isalpha(s[left]))
				left++;
			else if (!isdigit(s[right]) && !isalpha(s[right]))
				right--;
			else
			{
				if (isdigit(s[left]) && isdigit(s[right]))
				{
					if (s[left] != s[right]) return false;
				}
				else if (isalpha(s[left]) && isalpha(s[right]))
				{
					if ((s[left] != s[right]) && (s[left] != s[right] - diff) && (s[right] != s[left] - diff))
						return false;
				}
				else
					return false;
				left++;
				right--;
			}
		}
		return true;
	}
};