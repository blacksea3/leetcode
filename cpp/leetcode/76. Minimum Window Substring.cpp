#include "public.h"

//24ms, 80.96%

//only a simple silder window

//here: straight find the left and right loc of silder window is ok
//for the right: the loc must be this: if remove s[loc], the effective letter combination of s cannot 
//  exceed or equal to letter in t

//for the left: just the same..

class Solution {
public:
	string minWindow(string s, string t) {
		int i = 0, j = 0, k = t.size(), freq_s[256] = { 0 }, freq_t[256] = { 0 };
		string minS = "";
		for (j = 0; j < t.size(); j++)
			freq_t[t[j]]++;
		for (j = 0; j < s.size(); j++)
		{
			if (freq_t[s[j]]) //try to find the FUCK right loc
			{
				freq_s[s[j]]++;
				if (freq_s[s[j]] <= freq_t[s[j]])
					k--;
			}
			while (k == 0) //try to find the FUCK left loc
			{
				if (minS.empty() || minS.size() > j - i + 1)
					minS = s.substr(i, j - i + 1);
				if (freq_s[s[i]] && freq_t[s[i]])
				{
					freq_s[s[i]]--;
					if (freq_s[s[i]] < freq_t[s[i]])
						k++;
				}
				i++;
			}
		}
		return minS;
	}
};

int main()
{
	Solution* s = new Solution();
	string res = s->minWindow("ADOBECODEBANC","ABC");
	return 0;
}


