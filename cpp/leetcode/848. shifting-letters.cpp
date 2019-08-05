#include "public.h"

//96ms, 7.77%
//��������shifts�����һ��Ԫ�ؿ�ʼ��λ

class Solution {
public:
	string shiftingLetters(string S, vector<int>& shifts) {
		int premove = 0;
		for (int i = shifts.size() - 1; i >= 0; --i)
		{
			premove += shifts[i];
			premove %= 26;
			S[i] = ((S[i] + premove)) <= 'z' ? S[i] + premove : S[i] + premove - 26;
		}
		return S;
	}
};
