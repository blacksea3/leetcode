#include "public.h"

//
//����һ��unordered_map<int, int> um: ���߶�, ֵloc
//����һ��deque<int> �߶���, 
//upper_bound Ѱ�Ҹ߶��Ǵ��ڲ���ֵ�ĵ�һ��λ��, ��ômaxbias = max(maxbias, ��λ��-����λ��-1), ����������λ����begin��һ��, ��ô��������߶���λ��

class Solution {
public:
	int maxWidthRamp(vector<int>& A) {
		unordered_map<int, int> um;
		deque<int> heights;

		int res = 0;
		um[A[0]] = 0;
		heights.push_back(A[0]);

		for (int i = 1; i < A.size(); ++i)
		{
			deque<int>::iterator iter = upper_bound(heights.begin(), heights.end(), A[i]);
			if (iter == heights.begin())
			{
				um[A[i]] = i;
				heights.push_front(A[i]);
			}
			else
			{
				res = max(res, i - um[*(iter - 1)]);
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 6,0,8,2,1,5 };
	auto res = s->maxWidthRamp(A);
	return 0;
}
*/
