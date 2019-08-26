#include "public.h"

//12ms, 90.91%
//一遍扫描获取各个字符的出现位置
//然后这样操作: 对于  xxxx A yyy A zzzz, 左边这个A可以出现 (1+左非A数)*(1+右非A数)=25次, 右边同理
//最后相加各个字符的不同位置以及不同的字符得到结果

class Solution {
public:
	int uniqueLetterString(string S) {
		vector<vector<int>> locs(256);
		int ssize = S.size();
		int MOD = 1000000007;
		for (int i = 0; i < ssize; ++i)
		{
			locs[S[i]].push_back(i);
		}

		//挨个看字符
		int res = 0;
		for (int i = 0; i < 256; ++i)
		{
			if (locs[i].empty()) continue;
			else if (locs[i].size() == 1)
			{
				res += (1 + locs[i][0])*(ssize - locs[i][0]);
				res %= MOD;
			}
			else
			{
				//首尾加一下
				res += (1 + locs[i][0])*(locs[i][1] - locs[i][0]);
				res %= MOD;
				res += (locs[i][locs[i].size() - 1] - locs[i][locs[i].size() - 2])*(ssize - locs[i][locs[i].size() - 1]);
				res %= MOD;
				for (int j = 1; j < locs[i].size() - 1; ++j)
				{
					res += (locs[i][j + 1] - locs[i][j])*(locs[i][j] - locs[i][j - 1]);
					res %= MOD;
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//cout << s->uniqueLetterString("ABC");
	cout << s->uniqueLetterString("ABA");
	return 0;
}
*/
