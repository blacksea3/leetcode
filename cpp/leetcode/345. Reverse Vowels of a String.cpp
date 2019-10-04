#include "public.h"

//12ms, 83.06%
//˫ָ��, һ�����ұ���һ���������

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
			swap(s[left++], s[right--]);  //ע��һ��ǰ����left==right�˳�, �˴���Ӱ�콻��
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
