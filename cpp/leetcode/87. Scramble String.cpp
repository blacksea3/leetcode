#include "public.h"

//DP problem, 68ms, 13.33%
//Too difficult, I give up, please see https://blog.csdn.net/linhuanmars/article/details/24506703

class Solution {
public:
	bool isScramble(string s1, string s2) {
		//�ж�s2�Ƿ��ܹ�ͨ��s1���ض����������ַ��������õ�,���������ڽ��������ַ�����������,
		//ÿ����һ��,s1������        

		//�ݹ�̫������,���������ַ���,ֹͣ�����������ַ�����ȫ��ͬ
		//�ݹ�ʱ�����п��ַ������±�ݹ�,�˹�ʵ�ָ���λ�õĽ���!

		//��̬�滮 https://blog.csdn.net/linhuanmars/article/details/24506703

		//��̬�滮dp[i][j][len_m1]��ʾs1.substr(i,len_m1+1)��s2.substr(j,len_m1+1)�Ƿ�
		//Ϊ�����ַ���,len_m1��ʾ���ȼ�һ(���������±��0��ʼ)...
		//i��0~s1.size()-1;  j��0~s2.size()-1

		//len_m1=0ʱ���Լ����
		//len_m1>0ʱ,��Ϊ���������
		//����:s1��i��ʼ��ĳ��������s2��j��ʼ��ĳ��������ͬ,����֮����Ƕγ���Ҳ��Ӧ��ͬ
		//����:s1��i��ʼ��ĳ��������s2�ĵ���ĳ��������ͬ,����s2��j��ʼ����һ�γ�����s1�ĵ�����һ�γ�����ͬ

		//ע�ⲻ������dpԪ�ض��Ϸ�,����len_m1������,i��j�����޽���
		int lens = s1.size();
		if (lens == 0) return true;  //���ַ���>.<
		//ע���ⲿȷ�����볤����ͬ
		vector<vector<vector<bool>>> dp(lens, vector<vector<bool>>(lens, vector<bool>(lens, false)));

		for (int i = 0; i < lens; i++)
			for (int j = 0; j < lens; j++)
				dp[i][j][0] = (s1[i] == s2[j]);

		//����dp
		for (int lenm1 = 1; lenm1 < lens; lenm1++)   //ʵ�ʳ��ȼ�1
		{
			for (int i = 0; i < lens - lenm1; i++)
				for (int j = 0; j < lens - lenm1; j++)
				{
					//��Щ�����ֱ����Ծ,����Ҫ�������|=λ��
					//����
					for (int klenm1 = 0, klen = 1; klenm1 < lenm1; klenm1++, klen++)  //�󲿷�ʵ�ʳ��ȼ�1
					{
						if (dp[i][j][klenm1] && dp[i + klen][j + klen][lenm1 - klen])
						{
							dp[i][j][lenm1] = true;
							goto end;
						}
					}
					//����
					for (int klenm1 = 0, klen = 1; klenm1 < lenm1; klenm1++, klen++)  //�󲿷�ʵ�ʳ��ȼ�1
						if (dp[i][j + lenm1 - klenm1][klenm1] && dp[i + klen][j][lenm1 - klen])
						{
							dp[i][j][lenm1] = true;
							goto end;
						}
				end:;
				}
		}

		return dp[0][0][lens - 1];
	}
};

