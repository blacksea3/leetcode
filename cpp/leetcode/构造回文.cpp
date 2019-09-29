#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestPalindrome(string s)
{
	int sSize = s.size();
	if (s.size() == 1) return 1;

	vector<vector<int>> sa(sSize, vector<int>(sSize)); 
	//dp[i][j]最长回文子串长度: 下标i-j的最长回文子串长度

	for (int index = 0; index < sSize; ++index)
	{
		sa[index][index] = 1;
	}
	for (int index = 1; index < sSize; ++index)
	{
		sa[index - 1][index] = (s[index - 1] == s[index]) ? 2 : 1;
	}

	for (int len = 3; len <= sSize; ++len)
	{
		for (int le = 0; le <= sSize - len; ++le)
		{
			int ri = le + len - 1;
			if (s[le] == s[ri]) sa[le][ri] = sa[le + 1][ri - 1] + 2;
			else sa[le][ri] = max(sa[le + 1][ri], sa[le][ri - 1]);
		}
	}
	return sa[0][sSize - 1];
}

/*
int main()
{
	ifstream cin;  //覆盖全局std:cin
	cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\gouzaohuiwen.txt", ios::in);
	if (!cin.is_open())
	{
		throw exception("FATAL ERROR");
	}
	else
	{
		string s;
		while (cin >> s)
		{
			cout << s.size() - longestPalindrome(s) << endl;
		}
	}
}*/
