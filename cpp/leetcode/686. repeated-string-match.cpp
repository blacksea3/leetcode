#include "public.h"

//36ms, 40.55%
//�뱩��: ֱ�ӽ�A��չ:�����ȸպ�>=B, ������ַ����Լ�����չһ��A���ַ��� �� B�Ƚ�, �жϽ��

class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		int aSize = A.size();
		int bSize = B.size();
		int res = 1;
		int expand_aSize = aSize;

		string expandA = A;
		while (expand_aSize < bSize)
		{
			expand_aSize += aSize;
			expandA.append(A);
			res++;
		}

		if (expandA.find(B) != expandA.npos) return res;
		else
		{
			expandA.append(A);
			res++;
			if (expandA.find(B) != expandA.npos) return res;
			else return -1;
		}
	}
};
