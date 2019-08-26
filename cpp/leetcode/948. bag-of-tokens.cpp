#include "public.h"

//12ms, 74.70%
//̰��
//P-min, res++; Ȼ��p+max, res--; Ȼ��p-���min, res+=���; Ȼ��p+һ�����, res--......

class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int P) {
		if (tokens.size() == 0) return 0;
		sort(tokens.begin(), tokens.end());
		if (tokens[0] > P) return 0;
		else
		{
			int left = 0;
			int right = tokens.size() - 1;
			int res = 0;
			int realres = 0;
			//ѭ��ģ��
			while (left <= right)
			{
				//�����С��
				while (left <= right && P >= tokens[left])
				{
					P -= tokens[left];
					left++;
					res++;
				}
				realres = max(res, realres); //���ֵ�����ڲ��ܼ�С�ĵ����
				//��һ�����
				if (left <= right)
				{
					P += tokens[right];
					right--;
					res--;
				}
			}
			return realres;
		}
	}
};
