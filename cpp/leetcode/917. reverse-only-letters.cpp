#include "public.h"

//4ms, 83.12%
//Ë«Ö¸Õë

class Solution {
public:
	string reverseOnlyLetters(string S) {
		int left = 0;
		int right = S.size() - 1;
		while (left < right)
		{
			while (left < right && !isalpha(S[left])) left++;
			while (left < right && !isalpha(S[right])) right--;
			if (left < right)
			{
				swap(S[left], S[right]);
			}
			left++;
			right--;
		}
		return S;
	}
};
