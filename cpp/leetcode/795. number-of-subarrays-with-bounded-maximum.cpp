#include "public.h"

//88ms, 12.00%
//ɨ��A, �ҵ����������ڵ����Լ���(����ӽ��Լ�������loc), �ұ�����ڵ����Լ���(����ӽ��Լ�������loc), ����һ���ж�ʱ��Ҫ���ϵȺ�, ��������о���: �����ͬ������������

class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		vector<int> leftmax(A.size());
		vector<int> rightmax(A.size());

		stack<pair<int, int>> pre;
		for (int i = 0; i < A.size(); ++i)
		{
			while (!pre.empty() && pre.top().first < A[i]) pre.pop();
			if (pre.empty()) leftmax[i] = -1;
			else leftmax[i] = pre.top().second;
			pre.push({ A[i], i });
		}

		stack<pair<int, int>> pre2;
		for (int i = A.size() - 1; i >= 0; --i)
		{
			while (!pre2.empty() && pre2.top().first <= A[i]) pre2.pop();
			if (pre2.empty()) rightmax[i] = A.size();
			else rightmax[i] = pre2.top().second;
			pre2.push({ A[i], i });
		}

		int res = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			if (A[i] <= R && A[i] >= L) res += (i - leftmax[i])*(rightmax[i] - i);
		}
		return res;
	}
};
