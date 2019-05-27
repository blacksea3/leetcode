#include "public.h"

//20ms, 67.35%

//use double pointer, one from left to right, another from right to left

class Solution {
public:
	string reverseVowels(string s) {
		//reverse only the vowels: a e i o u
		int left = 0;
		int right = s.size() - 1;
		vector<char> us = { 'a','e','i','o','u','A','E','I','O','U' };
		while (left < right)
		{
			while ((left < right) && (find(us.begin(), us.end(), s[left]) == us.end()))
				left++;
			while ((left < right) && (find(us.begin(), us.end(), s[right]) == us.end()))
				right--;
			if (left < right) swap(s[left++], s[right--]);
		}
		return s;
	}
};

int main()
{
	Solution* s = new Solution();
	string res = s->reverseVowels("aA");
	return 0;
}
