#include "public.h"

//0ms, 100%
//��ѧ, ����
//ż��ֱ�ӳ���2
//����: �����β��01, ��ô��1; �����11, ��ô��1
//  �����������: �����3, ��ô�����1��3->4->2->1
//      ��1��3->2->1, ��ֱ�Ӵ���+2

class Solution {
public:
	int integerReplacement(int n) {
		int res = 0;
		while (n > 3)
		{
			if (n % 2)
			{
				n >>= 1;
				if (n % 2) n++; //��Ӧǰ��������β��11, ��n%2==0, ���β��01
				res += 2;
			}
			else
			{
				n >>= 1;
				res++;
			}
		}
		return res + n - 1;
	}
};
