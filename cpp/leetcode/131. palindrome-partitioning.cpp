#include "public.h"

//24ms, 96.83%

//µÝ¹é±©Á¦ËÑË÷

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

	void recu_partition(const string& s, int start)
	{
		if (start >= s.size()) res.push_back(pre);

		//±©Á¦
		for (int i = start; i < s.size(); i++)
		{
			if (is_partition(s, start, i))
			{
				pre.push_back(s.substr(start, i - start + 1));
				recu_partition(s, i + 1);
				pre.pop_back();
			}
		}
	}


public:
	vector<vector<string>> partition(string s) {
		//µÝ¹é
		recu_partition(s, 0);
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
