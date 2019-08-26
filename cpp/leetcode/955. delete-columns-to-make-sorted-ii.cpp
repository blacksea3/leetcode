#include "public.h"

//12ms, 81.97%
//̰��+dp
//dp[i] i��i+1�ȵ�״̬: true: С��, false: ����
//��ʼ��ȫ��������, �����ǰdp��С��, ��ô���治�ñ�; 
//  �����ǰdp�ǵ���, ���������С����ĳ�С��, ��������ǵ����򲻱�, ��������Ǵ���, ����ֲ��ñ�, һ����ɾ��, ����һ��֮ǰ��״̬������
//  ���dp��С����, ��ôOK��, ����е��ڵ��ǵ�ĩβ��, ��ôҲok��

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		vector<bool> dp(A.size() - 1, false);
		int remain_equal = A.size() - 1;

		int res = 0;
		int loc = 0;
		while (remain_equal > 0 && loc < A[0].size())
		{
			vector<bool> temp(A.size() - 1, false);
			bool issave = true;
			int temp_remain_equal = remain_equal;
			for (int i = 0; i < A.size() - 1; ++i)
			{
				if (!dp[i])
				{
					if (A[i][loc] > A[i + 1][loc])
					{
						res++;
						issave = false;
						break;
					}
					else if (A[i][loc] < A[i + 1][loc])
					{
						temp[i] = true;
						temp_remain_equal--;
					}
					else temp[i] = false;
				}
				else temp[i] = dp[i];
			}
			if (issave)
			{
				dp = temp;
				remain_equal = temp_remain_equal;
			}
			loc++;
		}
		return res;
	}
};
