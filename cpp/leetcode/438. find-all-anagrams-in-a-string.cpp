#include "public.h"

//44ms, 88.78%
//vector先记录p词频
//然后滑动窗口

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int psize = p.size();
		int ssize = s.size();
		if (ssize < psize) return {};

		vector<int> res;

		vector<int> countp(26, 0);
		for (auto& iter_p : p) countp[iter_p - 'a']++;
		vector<int> countpre(26, 0);

		//init precount
		int preloc = 0;
		for (int i = 0; i < psize; ++i) countpre[s[i] - 'a']++;
		if (countpre == countp) res.push_back(preloc);

		//主滑动窗口
		while (preloc < ssize - psize + 1)
		{
			countpre[s[preloc - 1] - 'a']--;
			countpre[s[preloc + psize - 1] - 'a']++;
			if (countpre == countp) res.push_back(preloc);
			preloc++;
		}
		return res;
	}
};
