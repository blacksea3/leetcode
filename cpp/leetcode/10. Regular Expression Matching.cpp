#include "public.h"

//回溯法,相当复杂,不建议使用
//时间也很长 76ms
/*

class Solution {
public:
bool isMatchSpace(string p)
{
	unsigned int plen = p.size();
	if ((plen % 2) == 1) return false;
	unsigned int loc = 0;
	while (loc < plen)
	{
		if (p[loc] == '*') return false;
		if (p[loc + 1] != '*') return false;
		else loc += 2;
	}
	return true;
}

bool isMatch(string s, string p)
{
	//对于特殊的?*组合,记录至stack中

	struct star { int sloc; int ploc; int number; };  //sloc:s的起始loc, ploc:?*组合的?处的p的loc, number:匹配掉多少个s中的?字符
	stack<star> recall = {};

	int sloc = 0;
	int ploc = 0;
	int ssize = s.size();
	int psize = p.size();

	bool isneedjudge = false;  //回溯用的判断

	while (true)
	{
		if (isneedjudge)
		{
			if (recall.empty()) return false;
			star last = recall.top();
			if (p[last.ploc] == '.')
			{
				//边界判断 //再次回溯
				if ((last.sloc + last.number) >= ssize)
				{
					recall.pop();
					isneedjudge = true;
				}
				else
				{
					recall.top().number++;
					sloc = last.sloc + last.number + 1;
					ploc = last.ploc + 2;
					isneedjudge = false;
				}
			}
			else
			{
				//边界判断 //再次回溯
				if ((last.sloc + last.number) >= ssize)
				{
					recall.pop();
					isneedjudge = true;
				}
				else if (s[last.sloc + last.number] == p[last.ploc])
				{
					recall.top().number++;
					sloc = last.sloc + last.number + 1;
					ploc = last.ploc + 2;
					isneedjudge = false;
				}
				else //再次回溯
				{
					recall.pop();
					isneedjudge = true;
				}
			}
		}
		else
		{
			if (sloc == ssize)
			{
				if (ploc == psize)
					break;
				else
				{
					//判断p之后的内容
					if (isMatchSpace(p.substr(ploc))) break;
					else //回溯
						isneedjudge = true;
				}
			}
			else if (ploc == psize)
			{
				isneedjudge = true;
				//回溯
			}
			else
			{
				if ((p[ploc] <= 'z') && (p[ploc] >= 'a'))
				{
					//如果p这里正好有个?*组合,那么直接加入stack
					if ((ploc < psize - 1) && (p[ploc + 1] == '*'))
					{
						//生成栈
						star pre = star();
						pre.sloc = sloc;
						pre.ploc = ploc;
						pre.number = 0;
						recall.push(pre);
						ploc += 2;
					}
					else if (s[sloc] == p[ploc])
					{
						sloc++;
						ploc++;
					}
					else //回溯
					{
						isneedjudge = true;
					}
				}
				else if (p[ploc] == '.')
				{
					//如果p这里正好有个?*组合,那么直接加入stack
					if ((ploc < psize - 1) && (p[ploc + 1] == '*'))
					{
						//生成栈
						star pre = star();
						pre.sloc = sloc;
						pre.ploc = ploc;
						pre.number = 0;
						recall.push(pre);
						ploc += 2;
					}
					else
					{
						sloc++;
						ploc++;
					}
				}
				else  //有星号了
				{
					//判断星号合法性
					if (ploc == 0) return false;
					if (p[ploc - 1] == '*') return false;

					//生成栈
					star pre = star();
					pre.sloc = sloc - 1;
					pre.ploc = ploc - 1;
					pre.number = 0;
					recall.push(pre);
					sloc--;
					ploc++;
				}
			}
		}

	}

	return true;
}
};

*/

//动态规划 //8ms 99.33%

//按照以下规则进行
//dp[i][j]表示s直到第i个字符与p直到第j字符是否匹配  0<=i<=s.size(),  0<=j<=p.size()
//dp初始化按照全false进行处理
//第一轮初始化按照查看是否存在连续的?*组合进行选择是否赋值true

//按照以下递推关系
//if (p[j] = 字母) if (p[j] == s[i]) dp[i][j] = d[i-1][j-1] else dp[i][j] = false;
//else if (p[j] == '.') dp[i][j] = d[i-1][j-1]
//else 贪婪匹配*
//    if 
//    else if (p[j-1] != s[i])  dp[i][j] = d[i][j-2] 表示也许可以跳过吗?*组合
//    else if (p[])

class Solution {
public:
	bool isMatch(string s, string p) {

		int ssize = s.size();
		int psize = p.size();

		vector<vector<bool>> dp(ssize + 1, vector<bool>(psize + 1, false));

		dp[0][0] = true;
		//init
		for (int j = 2; j <= psize; j+=2)
			if (((p[j - 1] == '*') && (p[j - 2] != '*')) && (dp[0][j - 2]))
			    dp[0][j] = true;

		//main dp
		for (int i = 1; i <= ssize; i++)
			for (int j = 1; j <= psize; j++)
				if ((p[j - 1] == s[i - 1]) || (p[j - 1] == '.'))
					dp[i][j] = dp[i - 1][j - 1];
				else if (p[j - 1] == '*')//贪婪匹配*
					if (j != 1) //p非开头的*
					{
						if ((p[j - 2] == s[i - 1]) || (p[j - 2] == '.')) //如果*前面是字母和s对应位置相等或者是.
						{
							//分别对应*吃掉额外的s字符;*不吃字符,用原字符吃它;跳过这组?*
							dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
						}
						else if (p[j - 2] == '*') return false; //强制退出,p字符串不合法
						else //*前面是字母但是和s对应位置不等
							dp[i][j] = dp[i][j - 2];  //看是否能够跳过
					}
					else return false; //强制退出,p字符串不合法
				else
					continue;

		return dp[ssize][psize];
	}
};

int main()
{
	Solution s = Solution();
	cout << s.isMatch("aa", "a*");
	cout << s.isMatch("aa", "a**");
	cout << s.isMatch("aa", "");
	cout << s.isMatch("", "a");
	cout << s.isMatch("", "");
	cout << s.isMatch("", "*");

    cout << s.isMatch("ab", ".*");
	cout << s.isMatch("aab", "c*a*b");
	cout << s.isMatch("mississippi", "mis*is*p*.");

	cout << s.isMatch("mississippi", "mis*is*ip*.");

	cout << s.isMatch("bbbba", ".*a*a");

	cout << s.isMatch("a", ".*");
	return 0;
}

