#include "public.h"

//68ms, 5.81%
//��ÿһ����Ч���ŵ���������Ŷ�ɾ��

class Solution {
public:
	string removeOuterParentheses(string S) {
		int left = 0;

		int loc = 0;
		while (loc < S.size())
		{
			if (left == 0)
			{
				S.erase(S.begin() + loc);
				left++;
			}
			else
			{
				if (S[loc] == '(')
				{
					left++;
					loc++;
				}
				else
				{
					left--;
					if (left != 0) loc++;
					else S.erase(S.begin() + loc);
				}
			}
		}
	}
};

