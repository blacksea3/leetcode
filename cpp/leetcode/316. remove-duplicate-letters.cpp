#include "public.h"

//8ms, 85.43%
//维护一个vector
//如果vector中不存在当前值, 则如果vector中有其他值, 当前值小于vector末尾值, 且vector末尾值在字符串之后还存在, 则去掉vector末尾值, 然后再次相同loc判断;  直到while判断退出, 当前loc+1
//如果vector中存在当前值, 当前loc+1

class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<char> res;

		//先获取每个字符在s中得最后出现的位置
		vector<int> lastindex(26, -1);
		for (int i = s.size() - 1; i >= 0; --i)
			if (lastindex[s[i] - 'a'] == -1) lastindex[s[i] - 'a'] = i;

		for (int loc = 0; loc < s.size(); ++loc)
		{
			if (find(res.begin(), res.end(), s[loc]) != res.end()) continue;
			else
			{
				while (!res.empty() && res[res.size() - 1] > s[loc] && loc < lastindex[res[res.size() - 1] - 'a'])
					res.pop_back();
			}
			res.push_back(s[loc]);
		}
		string sres = "";
		for (int i = 0; i < res.size(); ++i)
			sres += res[i];
		return sres;
	}
};

int main()
{
	Solution* s = new Solution();
	string res = s->removeDuplicateLetters("bcabc");
	return 0;
}
