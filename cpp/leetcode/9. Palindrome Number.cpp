#include "public.h"

//8ms 99.79%

//����,��ǰ��ת����ֵ > ȥ��һλ���ֵ�����ֵ ��ʾ��Ϊ������   ,  �˻�����Ϊ��������
//��ǰ��ת����ֵ == ȥ��һλ���ֵ�����ֵ ��ʾΪ������         ,  �˻�����Ϊ��������
//��ǰ��ת����ֵ == δȥ��һλ���ֵ�����ֵ ��ʾ��Ϊ������     ,  �˻�����Ϊż������
//��ǰ��ת����ֵ == δȥ��һλ���ֵ�����ֵ ��ʾΪ������       ,  �˻�����Ϊż������

//�߽����:�Ը�λ����������

class Solution {
public:
	bool isPalindrome(int x) {
		//�߽����
		if (x < 0) return false;
		if (x < 10) return true;
		if (x % 10 == 0) return false;

		int reverse = 0;
		int temp = 0;
		int nextx = 0;

		while (true)
		{
			nextx = x / 10;
			temp = reverse * 10 + x % 10;
			if (reverse > nextx) return false;
			else if (reverse == nextx) return true;
			else
			{
				if (temp > nextx) return false;
				else if (temp == nextx) return true;
				else
				{
					reverse = temp;
					x = nextx;
				}
			}
		}
		return false;   //dump, code will not arrive here
	}
};
