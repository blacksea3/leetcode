#include "public.h"

//FIRST:dp   140ms, 47.95%
//if p[j] != '*' dp[i][j] = dp[i-1][j-1] && ((s[i] == p[j]) || (p[j] == '?'))
//else dp[i][j] = dp[i][j-1] || dp[i-1][j]

//dp[i][j]: whether s[0:i-1] and p[0:j-1] is match, i==0 or j==0 means empty string

/*
class Solution {
public:
	bool isMatch(string s, string p) {
		int ssize = s.size();
		int psize = p.size();

		vector<vector<bool>> dp(psize + 1, vector<bool>(ssize + 1, false));

		dp[0][0] = true;  //"" and "" are match

		for (int i = 1; i <= psize; i++)
			dp[i][0] = dp[i - 1][0] && (p[i - 1] == '*');

		for (int i = 1; i <= psize; i++)
			for (int j = 1; j <= ssize; j++)
			{
				if (p[i - 1] != '*')
					dp[i][j] = dp[i - 1][j - 1] && ((s[j - 1] == p[i - 1]) || (p[i - 1] == '?'));
				else
					dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
			}

		if (dp[psize][ssize]) return true;
		else return false;
	}
};
*/

//16ms, 97.20%
//SECOND: state mathine and BackTracking

class Solution {
public:
	bool isMatch(string s, string p)
	{
		int i = 0;
		int j = 0;
		int si = -1;
		int sj = -1;
		while (i < s.size())
		{
			if (s[i] == p[j] || '?' == p[j])
			{
				++i;
				++j;
			}
			else if ('*' == p[j])
			{
				si = i;
				sj = j++;

			}
			else if (si >= 0)
			{
				i = ++si;
				j = sj + 1;
			}
			else return false;
		}
		while (j < p.size() && p[j] == '*') ++j;
		return j == p.size();
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->isMatch("abbc", "a*bc");
	return 0;
}