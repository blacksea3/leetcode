#include "public.h"

//
//̰��: ����С�������ϲ�(ȡ��ֵ+split)���½ڵ�

class Solution {
public:
	int minBuildTime(vector<int>& blocks, int split) {
		multiset<int> vals(blocks.begin(), blocks.end());

		while (vals.size() > 1)
		{
			int minVal = *vals.begin();
			vals.erase(vals.begin());
			int minVal2 = *vals.begin();  //���һ����ǰһ��������
			vals.erase(vals.begin());
			vals.insert(minVal2 + split);
		}

		return *vals.begin();
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> blocks = { 1,2,3 };
	cout << s->minBuildTime(blocks, 1);
	return 0;
}
*/
