#include "public.h"

//4ms, 87.55%
//��ѧ��, ʵ���޷���������˼��!

/*
���ߣ�LeetCode
���ӣ�https ://leetcode-cn.com/problems/two-sum/solution/shu-zi-1-de-ge-shu-by-leetcode/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

class Solution {
public:
	int countDigitOne(int n)
	{
		int countr = 0;
		for (long long i = 1; i <= n; i *= 10) {
			long long divider = i * 10;
			countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
		}
		return countr;
	}
};



