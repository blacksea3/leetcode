#include "public.h"

//280ms, 5.41%
//����ȫ��0/8/1, ��ȡ����: 0 1 2 5 6 8 9
//��λ��: 2 5 6 9 : 4
//ʮλ��: 6*7 - 2*3
//��λ��: 6*7*7 - 2*3*3
//ǧλ��: 6*7*7*7 - 2*3*3*3

//���ǵ�N<=10000, ���Ա���

class Solution {
private:
	bool canrotated(int r)
	{
		set<int> s;
		while (r > 0)
		{
			s.insert(r % 10);
			r /= 10;
		}

		//�ж�s��������
		if (s.find(3) != s.end() || s.find(4) != s.end() || s.find(7) != s.end()) return false;
		if (s.find(2) == s.end() && s.find(5) == s.end() && s.find(6) == s.end() && s.find(9) == s.end()) return false;
		return true;
	}


public:
	int rotatedDigits(int N) {
		int res = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (canrotated(i)) res++;
		}
		return res;
	}
};
