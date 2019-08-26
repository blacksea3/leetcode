#include "public.h"

//92ms, 52.89%
//����һ��vector<int>��ʾ: ���±�0���±�i�������ģK������, ������ͳ�ƴ���, �±��������:)
//Ȼ�������²���: ������һ����: A[i], ȥ���±�0���±�0�γɵ�����, ��Ѱ���ض��������ж�����
//Ȼ������������, ����Ŀ������, ȥ���±�0���±�1�γɵ�����, ��Ѱ���ض��������ж�����

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
