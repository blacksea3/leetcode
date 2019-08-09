#include "public.h"

//88ms, 12.00%
//扫描A, 找到从左边起大于等于自己的(且最接近自己的数字loc), 右边起大于等于自己的(且最接近自己的数字loc), 其中一边判断时不要加上等号, 具体可自行举例: 多个相同数字连续摆列

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
