#include "public.h"

//First: brute force iteratively, 8ms, 90.20%

/*
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		//here ip are formed with 4 numbers , each number :[0,255], the number which is not 0 cannot start with 0


		int slen = s.size();
		vector<string> res = {};

		for (int i = 1; i <= 3; i++)
		{
			if ((slen - i) < 3) break;
			if ((slen - i) > 9) continue;
			for (int j = 1; j <= 3; j++)
			{
				if ((slen - i - j) < 2) break;
				if ((slen - i - j) > 6) continue;
				for (int k = 1; k <= 3; k++)
				{
					if ((slen - i - j - k) < 1) break;
					if ((slen - i - j - k) > 3) continue;
					//FUCK, JUST JUDGE
					int temp;

					if (s.substr(0, 1) == "0")
						if (i != 1) continue;
					temp = atoi(s.substr(0, i).c_str());
					if (temp > 255) continue;

					if (s.substr(i, 1) == "0")
						if (j != 1) continue;
					temp = atoi(s.substr(i, j).c_str());
					if (temp > 255) continue;

					if (s.substr(i + j, 1) == "0")
						if (k != 1) continue;
					temp = atoi(s.substr(i + j, k).c_str());
					if (temp > 255) continue;

					if (s.substr(i + j + k, 1) == "0")
						if ((slen - i - j - k) != 1) continue;
					temp = atoi(s.substr(i + j + k).c_str());
					if (temp > 255) continue;

					//FUCK, SAVE THEM
					string tip = s.substr(0, i) + "." + s.substr(i, j) + "." + s.substr(i + j, k) + "." + s.substr(i + j + k);
					res.push_back(tip);
				}
			}
		}
		return res;
	}
};*/

//SECOND: BackTracking, recursively, 0ms, 100%
class Solution {
private:
	vector<string> res = {};
	void recu_restoreIpAddresses(const string& s, const int& totalloc, int startloc, vector<string> oldstrs, int oldlen)
	{
		for (int i = max(totalloc - startloc - 3 * (3 - oldlen), 1); i <= min(totalloc - startloc - (3 - oldlen), 3); ++i)
		{
			string temps = s.substr(startloc, i);
			int tempi = atoi(temps.c_str());
			if ((tempi <= 255) && (tempi >= 0))
			{
				if ((i == 1) || (s.substr(startloc, i)[0] != '0'))
				{
					oldstrs.push_back(temps);
					if (oldlen == 3)
					{
						string tres = oldstrs[0];
						for (int k = 1; k <= 3; ++k)
						{
							tres += ".";
							tres += oldstrs[k];
						}
						res.push_back(tres);
					}
					else recu_restoreIpAddresses(s, totalloc, startloc + i, oldstrs, oldlen + 1);
					oldstrs.pop_back();
				}
			}
		}
	}

public:
	vector<string> restoreIpAddresses(string s) {
		recu_restoreIpAddresses(s, s.size(), 0, {}, 0);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<string> res = s->restoreIpAddresses("25525511135");
	return 0;
}

