#include "public.h"

//100ms, 57.58%
//����ջ
//������Ԫ��: �����һ����߱���С��loc1/�ұ߱���С��Ԫ���±�loc2
//��ÿ��Ԫ������: res += (loc1�뵱ǰ���±��)*(loc2�뵱ǰ���±��)*��ǰԪ��ֵ

class Solution {
public:
	int sumSubarrayMins(vector<int>& A) {
		int len_A = A.size();
		if (len_A == 0) return 0;
		else if (len_A == 1) return A[0];

		int ans = 0;
		vector<int> left(A.size());
		vector<int> right(A.size());
		stack<int> st;
		for (int i = 0; i < A.size(); ++i)
		{
			while (!st.empty() && A[st.top()] > A[i])
			{
				st.pop();
			}
			if (st.empty())
				left[i] = -1;
			else
				left[i] = st.top();
			st.push(i);
		}
					
		stack<int> st2;
		for (int i = A.size() - 1; i >= 0; --i)
		{
			while (!st2.empty() && A[st2.top()] >= A[i])
			{
				st2.pop();
			}
			if (st2.empty())
				right[i] = A.size();
			else
				right[i] = st2.top();
			st2.push(i);
		}
		for (int i = 0; i < A.size(); ++i)
		{
			ans += (i - left[i]) * (right[i] - i) * A[i];
			ans %= 1000000007;
		}
		return ans;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 3,1,2,4 };
	cout << s->sumSubarrayMins(A);
	return 0;
}
*/
