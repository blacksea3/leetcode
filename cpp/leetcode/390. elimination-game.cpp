#include "public.h"

//8ms, 88.39%
//�������µ���������: 
//1�� ��������� a ������� b ����ô������ 2a ʱ��������� 2 * (a - b + 1)
//    ���磺1 2 3 4 5 6 7 8 9 10, �ȱ�� 2 4 6 8 10���� 5 4 3 2 1���5��ʱ����2��ô���ھ���8
//2�����������ͬ��-1��ż�����

class Solution {
public:
	int lastRemaining(int n) {
		if (n == 1) return 1;
		else return 2 * (n / 2 - lastRemaining(n / 2) + 1);
	}
};
