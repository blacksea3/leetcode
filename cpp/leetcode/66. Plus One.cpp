#include "public.h"

//4ms, 88.90%
//ģ��, ��Ҫ���1, ע���λ���, ֱ��ԭλ����digits
//ע��: ���digits��С����һ, ��ʾ�����λ������λ����0, ��ô���Բ��ÿ�ͷinsert
//����push_back + ��ͷ0�ĳ�1

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		bool isCarry = true;

		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (++digits[i] == 10) digits[i] = 0;
			else return digits;
		}
		digits.emplace_back(0);
		digits[0] = 1;
		return digits;
	}
};
