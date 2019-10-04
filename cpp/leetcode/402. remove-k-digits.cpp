#include "public.h"

//4ms, 97.30%
//̰��
//���������ķ�Χ: ����num.size() = 5, k=2, ���һ������loc���������ķ�Χ��0,1,2,3
//�����������ķ�Χ������������loc: num[loc+1] < num[loc], ��������, ��ɾ�����������ķ�Χ������loc
//��������õ���ջʵ��, num�������ұ���, ��ջ��Ԫ�ش��ڵ�ǰԪ����ɾ��ջ��Ԫ��
//���ɾ��Ԫ����������, ��ô��num����Ԫ�ؿ�ʼɾ��
//O(n)

class Solution {
public:
	string removeKdigits(string num, int k) {
		int delK = 0;
		int nIndex = 0;
		string res;
		int resSize = num.size() - k;

		for (char& c : num)
		{
			while (k && !res.empty() && res.back() > c)  //�������res���ɾ��k��Ԫ��(resʵ���������num������Ԫ��)
			{
				res.pop_back();
				--k;
			}
			res.push_back(c);
		}
		res.resize(resSize);  //���ɾ��Ԫ�ز���, ��ض�����Ԫ��

		while (!res.empty() && res[0] == '0') res.erase(res.begin());
		return res.empty() ? "0" : res;
	}
};
