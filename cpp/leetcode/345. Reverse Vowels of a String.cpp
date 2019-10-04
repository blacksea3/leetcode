#include "public.h"

//12ms, 83.06%
//双指针, 一个从右边走一个从左边走

class Solution {
private:
	set<char> const us = { 'a','e','i','o','u','A','E','I','O','U' };
public:
	string reverseVowels(string s) {
		//reverse only the vowels: a e i o u
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			while ((left < right) && (us.find(s[left])) == us.end())
				left++;
			while ((left < right) && (us.find(s[right])) == us.end())
				right--;
			swap(s[left++], s[right--]);  //注意一旦前面有left==right退出, 此处不影响交换
		}
		return s;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	string res = s->reverseVowels("aA");
	return 0;
}
*/
