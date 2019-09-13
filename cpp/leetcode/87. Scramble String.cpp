#include "public.h"

//DP problem, 68ms, 13.33%
//Too difficult, I give up, please see https://blog.csdn.net/linhuanmars/article/details/24506703

class Solution {
public:
	bool isScramble(string s1, string s2) {
		//判断s2是否能够通过s1的特定次数的子字符串交换得到,这两个用于交换的子字符串必须连续,
		//每交换一次,s1被更新        

		//递归太暴力了,依次缩短字符串,停止条件是两个字符串完全相同
		//递归时按照切开字符串的下标递归,人工实现各种位置的交换!

		//动态规划 https://blog.csdn.net/linhuanmars/article/details/24506703

		//动态规划dp[i][j][len_m1]表示s1.substr(i,len_m1+1)与s2.substr(j,len_m1+1)是否
		//为扰乱字符串,len_m1表示长度减一(这是由于下标从0开始)...
		//i是0~s1.size()-1;  j是0~s2.size()-1

		//len_m1=0时可以简单求得
		//len_m1>0时,分为正序和乱序
		//正序:s1从i开始的某个长度与s2从j开始的某个长度相同,并且之后的那段长度也对应相同
		//乱序:s1从i开始的某个长度与s2的倒数某个长度相同,并且s2从j开始的另一段长度与s1的倒数另一段长度相同

		//注意不是所有dp元素都合法,随着len_m1的增大,i与j的上限降低
		int lens = s1.size();
		if (lens == 0) return true;  //空字符串>.<
		//注意外部确保输入长度相同
		vector<vector<vector<bool>>> dp(lens, vector<vector<bool>>(lens, vector<bool>(lens, false)));

		for (int i = 0; i < lens; i++)
			for (int j = 0; j < lens; j++)
				dp[i][j][0] = (s1[i] == s2[j]);

		//核心dp
		for (int lenm1 = 1; lenm1 < lens; lenm1++)   //实际长度减1
		{
			for (int i = 0; i < lens - lenm1; i++)
				for (int j = 0; j < lens - lenm1; j++)
				{
					//有些情况下直接跳跃,不需要遍历求解|=位或
					//正序
					for (int klenm1 = 0, klen = 1; klenm1 < lenm1; klenm1++, klen++)  //左部分实际长度减1
					{
						if (dp[i][j][klenm1] && dp[i + klen][j + klen][lenm1 - klen])
						{
							dp[i][j][lenm1] = true;
							goto end;
						}
					}
					//乱序
					for (int klenm1 = 0, klen = 1; klenm1 < lenm1; klenm1++, klen++)  //左部分实际长度减1
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

