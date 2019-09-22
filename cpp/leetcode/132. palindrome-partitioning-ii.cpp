#include "public.h"

//8ms, 98.57%
//DP����
//Ӧ��ע�⵽ ���ָ��������ʱ����Щ�����ִ��ĳ��ȶ������Ĵ������
//����dp[i]��ʾ��i�±괦�����ٷָ���� d��ʼ��INTMAX
//��ÿ��λ�ö�������ɢ ���ǻ��� dp��չλ��ֵ������߽���dp��һ���߲���

class Solution {
public:
	int minCut(string s) {
		int sSize = s.size();

		vector<int> dp(sSize, 0);
		for (int i = 0; i < sSize; i++)
			dp[i] = i;

		for (int i = 0; i < sSize; i++)
		{
			//�жϻ��ģ����������Ȼ����жϣ���ż�����Ȼ����ж�
			int left = i;
			int right = i;
			while ((left >= 0) && (right < sSize) && (s[left] == s[right]))
			{
				if (left == 0) dp[right] = 0;
				else dp[right] = min(dp[right], dp[left - 1] + 1);
				left--;
				right++;
			}
			left = i;
			right = i + 1;
			while ((left >= 0) && (right < sSize) && (s[left] == s[right]))
			{
				if (left == 0) dp[right] = 0;
				else dp[right] = min(dp[right], dp[left - 1] + 1);
				left--;
				right++;
			}
		}
		return dp[sSize - 1];
	}
};
