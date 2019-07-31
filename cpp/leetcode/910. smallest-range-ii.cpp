#include "public.h"

//116ms, 5.33%
//排序, 假设都加了K, 现在的问题是某一些数据可以减去2K
//考虑到如果某一个较大的数字不减2K, 那么比它小的数字减掉2K是一定不会降低最大值与最小值的差距的
//那么只需要挨个把最大的数字减掉2K, 然后每次都比较一下max-min,

//用multiset保存值, 从里面获取最大最小

class Solution {
public:
	int smallestRangeII(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		int loc = A.size() - 1;
		multiset<int> ms;
		for (auto& a : A) ms.insert(a);
		int res = *ms.rbegin() - *ms.begin();

		while (loc > 0)
		{
			ms.erase(ms.find(A[loc]));
			ms.insert(A[loc] - 2 * K);
			loc--;
			res = min(res, *ms.rbegin() - *ms.begin());
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> A = { 0,10 };
	cout << s->smallestRangeII(A, 2);
	return 0;
}