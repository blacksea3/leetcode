#include "public.h"

//0ms, 100%
//DFS, 注意题目说字符串是合法的, 无需判断合法性

class Solution {
private:
	pair<string, int> DFS(const string& s, int startloc)
	{
		string pre = "";
		int preloc = startloc;
		while (preloc < s.size())
		{
			if (s[preloc] == '[')
			{
				//BackTrack the duplicate num
				int dup = 0;
				int mul = 1;
				while ((pre.size() > 0) && (pre[pre.size()-1] >= '0') && (pre[pre.size() - 1] <= '9'))
				{
					dup += mul*(pre[pre.size() - 1] - '0');
					mul *= 10;
					pre.pop_back();
				}
				pair<string, int> next = DFS(s, preloc + 1);
				for (int i = 0; i < dup; i++) pre += next.first;
				preloc = next.second;
			}
			else if (s[preloc] == ']')
			{
				return pair<string, int> {pre, preloc + 1};
			}
			else
			{
				pre += s[preloc++];
			}
			
		}
		return pair<string, int> {pre, preloc};
	}

public:
	string decodeString(string s) {
		int startloc = 0;
		string res = "";
		while (startloc < s.size())
		{
			pair<string, int> next = DFS(s, startloc);
			res += next.first;
			startloc = next.second;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	string res = s->decodeString("3[a]2[bc]");
	return 0;
}
*/
