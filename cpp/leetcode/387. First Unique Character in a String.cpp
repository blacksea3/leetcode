#include "public.h"

//40ms, 96.03%

//use a vector<int> v(26,0) to store all the letters

class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> v(26, 0);
		for (int i = 0; i < s.size(); i++)
		{
			if (v[s[i] - 'a'] == 0) v[s[i] - 'a'] = i;
			else v[s[i] - 'a'] = -1;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (v[s[i] - 'a'] > 0) return v[s[i] - 'a'];
		}

		return -1;
	}
};