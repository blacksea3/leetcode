#include "public.h"

//40ms, 88.33%
//记录年龄出现频率至vector, 然后挨个计算
//按排序思想: 对于年龄大的, 他可以交<=他年龄且> 0.5*自己年龄+7的

class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		vector<int> va(121, 0);  //va[0] is dump
		for (auto& a : ages) va[a]++;

		int res = 0;

		//合并
		for (int i = 1; i <= 120; ++i)
		{
			for (int j = 0.5*i + 8; j <= i; ++j)
			{
				if (i != j) res += va[i] * va[j];
				else res += (va[i] * (va[i] - 1));
			}
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> ages = { 101, 56, 69, 48, 30 };
	cout << s->numFriendRequests(ages);
	return 0;
}
*/
