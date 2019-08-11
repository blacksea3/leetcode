#include "public.h"

//0ms, 100%
//�����ۼ�1,2,3...ֱ��sum>=target && (sum - target)��ż��, ��ʱ˵����ĳЩ���跴����������ɵõ����
//̰��: һ����ֵ��ż��, һ������һ���Ѿ��߹�������1-n�м��ĳ�����ʹ��  sum��ȥ���������ǵĺ�  �ͱ����target

class Solution {
public:
	int reachNumber(int target) {
		int res = 0;
		int presum = 0;
		target = abs(target);

		while (target)
		{
			if (presum >= target && (presum - target) % 2 == 0) break;
			res++;
			presum += res;
		}
		return res;
	}
};
