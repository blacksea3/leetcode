#include "public.h"

//8ms, 94.59%
/*
�ο������ߣ�Faber99
���ӣ�https ://leetcode-cn.com/problems/two-sum/solution/an-yao-qiu-bu-qi-shu-zu-tan-lan-by-faber99/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

����������һ������nums������1 - n����������nums���ɣ���ʱ���һ��Ԫ��num����������������� 1��num > n��
nums����ɱ�ʾ��������ֵ��Χ�� 1 - n && num - num + n�� �м�n - num��û����ʾ�ģ�
2��num <= n:
nums����ɱ�ʾ��������ֵ��Χ ����ǰ���� num�����ȣ�����1 - n ����� 1 - n + num��
��Ϊ����������������������Ը��ݴ�С���󣬸�������������� �����ӳ� �ɱ�ʾ������ֵ��Χ��ֱ��1 - n���ɱ���ʾ��

���ǵ�nums�Ѵ�С��������, ��ô����, �������1, ��������һ������n+1, ʹ�ÿɱ�ʾ����ֵ��Χ���2n+1, �������ŵ�(�Ҳ���֤��)
�������2, ֱ�Ӹ��¿ɱ�ʾ����ֵ��Χ��n + num (ע�����: ʵ��ʵ�ֵ�ʱ�򱣴��ֵpresum��Ӧ�ɱ�ʾ������ֵ��Χ��[1,presum))

���������������û�е�Ҫ��, ��ô�Ե�ǰ�ɱ�ʾ����ֵ*2 *2 ... ֱ���ﵽ��Ҫ��

*/

class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		long presum = 1;  //ע��: ʵ�ʵĿɱ�ʾ������ֵ��Χ��[1,presum)
		int res = 0;

		for (auto& in : nums)
		{
			if (in > n) break;
			while (in > presum)
			{
				res++;
				presum *= 2;
			}
			presum += in;
		}

		while (presum <= n)
		{
			res++;
			presum *= 2;
		}
		return res;
	}
};

