#include "public.h"

/*
给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。

给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

*/

class Solution {
private:
	static bool m_cmp_lessthan(const vector<int>& p1, const vector<int> p2)
	{
		if (p1[0] < p2[0]) return true;
		else if (p1[0] > p2[0]) return false;
		else
		{
			if (p1[1] <= p2[1]) return true;
			else return false;
		}
	}


public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), m_cmp_lessthan);

		map<int, int> mm;

		//考虑以下的操作：总是记录pairs的第二个数为key，当前最大数对链的长度为value

		for (auto pre : pairs)
		{
			int hismaxlen = 0;
			for (map<int, int>::iterator iter = mm.begin(); iter != mm.end(); ++iter)
			{
				if (iter->first < pre[0])
					hismaxlen = max(hismaxlen, iter->second);
				else break;
			}
			mm[pre[1]] = max(mm[pre[1]], hismaxlen + 1);
		}

		int resmax = 0;
		for (auto iter = mm.begin(); iter != mm.end(); ++iter)
			resmax = max(resmax, iter->second);

		return resmax;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> pairs = { {1,2},{2,3},{3,4} };
	cout << s->findLongestChain(pairs);
	return 0;
}


