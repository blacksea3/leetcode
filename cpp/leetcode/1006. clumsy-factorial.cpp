#include "public.h"

//
//ֱ��ģ��

class Solution {
public:
	int clumsy(int N) {
		//�������
		if (N == 3) return 6;
		else if (N == 2) return 2;
		else if (N == 1) return 1;

		//������ʼ��
		int start = N * (N - 1) / (N - 2) + N - 3;
		N -= 4;

		while (N >= 4)
		{
			start = start - (N*(N - 1) / (N - 2)) + N - 3;
			N -= 4;
		}

		if (N == 3) start -= 6;
		else if (N == 2) start -= 2;
		else if (N == 1) start -= 1;
		else;

		return start;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->clumsy(8);
	return 0;
}
*/