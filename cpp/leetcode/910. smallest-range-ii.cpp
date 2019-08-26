#include "public.h"

//116ms, 5.33%
//����, ���趼����K, ���ڵ�������ĳһЩ���ݿ��Լ�ȥ2K
//���ǵ����ĳһ���ϴ�����ֲ���2K, ��ô����С�����ּ���2K��һ�����ή�����ֵ����Сֵ�Ĳ���
//��ôֻ��Ҫ�������������ּ���2K, Ȼ��ÿ�ζ��Ƚ�һ��max-min,

//��multiset����ֵ, �������ȡ�����С

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