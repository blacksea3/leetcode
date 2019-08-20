#include "public.h"

//120ms, 32.34%
//˫ָ��, ������ɨ, �����һ����, ����ɾ��һ�����ж�

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
					//����������
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
