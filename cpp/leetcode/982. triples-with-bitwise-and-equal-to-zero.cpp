#include "public.h"

//488ms, 45.45%
//将每一个A内的数都和0-65535与一下, 并且记录与结果是0的个数, 统计到vector<int> d(65535) 中
//然后对A内双重循环遍历组合, 从d中查找调出的两个值的与的结果 存储的值, 这个值相当于有多少个元素和双重循环的两个值相与结果为0

class Solution {
public:
	int countTriplets(vector<int>& A) {
		vector<int> d(65536, 0);

		for (auto& a : A)
			for (int i = 0; i < 65536; ++i)
			{
				if ((a&i) == 0) d[i]++;
			}

		int res = 0;
		for (auto& a : A)
			for (auto& b : A)
			{
				res += d[a&b];
			}

		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> A = { 2,1,3 };
	auto res = s->countTriplets(A);
	return 0;
}
