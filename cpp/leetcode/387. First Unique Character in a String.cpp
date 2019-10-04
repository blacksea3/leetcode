#include "public.h"

//24ms, 99.02%
//使用数组存储下标, 下标-2表示当前数字已重复, -1表示未找到

class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> v(256, -1);
		for (int i = 0; i < s.size(); i++)
		{
			if (v[s[i]] == -1) v[s[i]] = i;
			else v[s[i]] = -2;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (v[s[i]] > -1) return v[s[i]];
		}

		return -1;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->firstUniqChar("loveleetcode");
	return 0;
}
*/
