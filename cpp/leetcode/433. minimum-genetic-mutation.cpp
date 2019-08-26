#include "public.h"

//8ms, 33.33%
//直接BFS

class Solution {
private:
	//若就差一字母则返回true
	bool issimilar(const string& s1, const string& s2)
	{
		bool dif = false;
		for (int i = 0; i < s1.size(); ++i)
		{
			if (s1[i] == s2[i]) continue;
			else
			{
				if (!dif) dif = true;
				else return false;
			}
		}
		return true;
	}

public:
	int minMutation(string start, string end, vector<string>& bank) {
		unordered_set<string> pre;
		pre.insert(start);

		int res = 0;

		while (!pre.empty())
		{
			int bloc = 0;
			unordered_set<string> next;
			for (auto& iter_p : pre)
			{
				if (iter_p == end) return res;
				while (bloc < bank.size())
				{
					if (issimilar(bank[bloc], iter_p))
					{
						next.insert(bank[bloc]);
						bank.erase(bank.begin() + bloc);
					}
					else bloc++;
				}
			}
			pre = next;
			res++;
		}
		return -1;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> bank = { "AC" };
	cout << s->minMutation("AB", "AC", bank);
	return 0;
}
*/
