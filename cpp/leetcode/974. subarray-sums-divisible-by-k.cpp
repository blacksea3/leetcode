#include "public.h"

//92ms, 52.89%
//设置一个vector<int>表示: 从下标0至下标i的数组和模K的余数, 按余数统计次数, 下标就是余数:)
//然后考虑以下操作: 定死第一个数: A[i], 去掉下标0至下标0形成的余数, 再寻找特定的余数有多少种
//然后定死的数右移, 更新目标余数, 去掉下标0至下标1形成的余数, 再寻找特定的余数有多少种

class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		vector<int> yushu(K, 0);

		int sum = 0;
		for (auto& a : A)
		{
			sum += a;
			if (sum >= 0) yushu[sum%K]++;
			else if (sum%K == 0) yushu[0]++;
			else yushu[K+sum%K]++;
		}

		int res = 0;
		sum = 0;
		for (auto& a : A)
		{
			if (sum >= 0) res += yushu[sum%K];
			else if (sum%K == 0) res += yushu[0];
			else res += yushu[K + sum % K];
			sum += a;
			if (sum >= 0) yushu[sum%K]--;
			else if (sum%K == 0) yushu[0]--;
			else yushu[K + sum % K]--;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> A = { 4,5,0,-2,-3,1 };
	//auto res = s->subarraysDivByK(A, 5);
	//vector<int> A = { -2 };
	//auto res = s->subarraysDivByK(A, 6);
	vector<int> A = { -4, 5 };
	auto res = s->subarraysDivByK(A, 10);
	return 0;
}
*/
