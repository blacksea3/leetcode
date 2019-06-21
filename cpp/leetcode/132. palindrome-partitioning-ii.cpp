#include "public.h"

//DP problem, 12ms, 98.57%

class Solution {
public:
	int minCut(string s) {
		//Ӧ��ע�⵽ ���ָ��������ʱ����Щ�����ִ��ĳ��ȶ������Ĵ������
		//����dp[i]��ʾ��i�±괦�����ٷָ���� d��ʼ��INTMAX
		//��ÿ��λ�ö�������ɢ ���ǻ��� dp��չλ��ֵ������߽���dp��һ���߲���
		int ssize = s.size();

		vector<int> dp(ssize, 0);
		for (int i = 0; i < ssize; i++)
			dp[i] = i;

		for (int i = 0; i < ssize; i++)
		{
			//�жϻ���
			int left = i;
			int right = i;
			while ((left >= 0) && (right < ssize) && (s[left] == s[right]))
			{
				if (left == 0) dp[right] = 0;
				else dp[right] = min(dp[right], dp[left - 1] + 1);
				left--;
				right++;
			}
			left = i;
			right = i + 1;
			while ((left >= 0) && (right < ssize) && (s[left] == s[right]))
			{
				if (left == 0) dp[right] = 0;
				else dp[right] = min(dp[right], dp[left - 1] + 1);
				left--;
				right++;
			}
		}

		return dp[ssize - 1];
	}
};