#include "public.h"

//8ms, 100%
//»ØËÝ·¨£º±©Á¦ËÑË÷

class Solution {
private:
	vector<vector<string>> res;
	vector<string> pre;

	bool is_partition(const string& s, int start, int end)
	{
		while (start < end)
		{
			if (s[start] != s[end]) return false;
			start++;
			end--;
		}
		return true;
	}

	void backTracking(const string& s, int start)
	{
		if (start >= s.size()) res.emplace_back(pre);
		for (int i = start; i < s.size(); i++)
		{
			if (is_partition(s, start, i))
			{
				pre.emplace_back(s.substr(start, i - start + 1));
				backTracking(s, i + 1);
				pre.pop_back();
			}
		}
	}
public:
	vector<vector<string>> partition(string s) {
		//µÝ¹é
		backTracking(s, 0);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<string>> res = s->partition("aab");
	return 0;
}
*/
