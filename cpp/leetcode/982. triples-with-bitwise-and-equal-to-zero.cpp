#include "public.h"

//488ms, 45.45%
//��ÿһ��A�ڵ�������0-65535��һ��, ���Ҽ�¼������0�ĸ���, ͳ�Ƶ�vector<int> d(65535) ��
//Ȼ���A��˫��ѭ���������, ��d�в��ҵ���������ֵ����Ľ�� �洢��ֵ, ���ֵ�൱���ж��ٸ�Ԫ�غ�˫��ѭ��������ֵ������Ϊ0

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
