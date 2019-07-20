#include "public.h"

//dp[i][j]: �±�i-�±�j�Ƿ�Ϊ�����Ӵ�
//if dp[i+1][j-1]=true && �������߽� && s[i]==s[j], dp[i][j]=true,  ���� dp[i][j]=false
//��ʼ������Ϊ1��2��

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return s;
		int l = s.size();
		vector<vector<bool>> dp(l, vector<bool>(l, false));

		int maxabslen = 0;
		string resstr = "";
		resstr += s[0];
		for (int i = 0; i < l; ++i) dp[i][i] = true;
		for (int i = 1; i < l; ++i)
			if (s[i - 1] == s[i])
			{
				dp[i - 1][i] = true;
				maxabslen = 1;
				resstr = s.substr(i - 1, 2);
			}
		for (int abslen = 2; abslen < l; ++abslen) //abslenָ����end-start֮��, �����ַ�����ʵ����-1
			for (int start = 0, end = start + abslen; end < l; ++start, ++end)
				if (dp[start + 1][end - 1] && s[start] == s[end])
				{
					if (abslen > maxabslen)
					{
						maxabslen = abslen;
						resstr = s.substr(start, abslen + 1);
					}
					dp[start][end] = true;
				}
		return resstr;
	}
};

/*
int main() {
	Solution* s = new Solution();
	auto res = s->longestPalindrome("aaaa");
	return 0;
}
*/