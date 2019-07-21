#include "public.h"

//
//����һ��vector<int>:��ʾ������0����
//����һ��vector<int>:��ʾ������1����
//Ĭ����0��1

class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		vector<int> zeros;
		vector<int> ones;

		int count = 0;
		bool iszero = true;
		for (int i = 0; i < A.size(); ++i)
		{
			if (iszero)
			{
				if (A[i] == 0) count++;
				else
				{
					zeros.push_back(count);
					count = 1;
					iszero = false;
				}
			}
			else
			{
				if (A[i] == 1) count++;
				else
				{
					ones.push_back(count);
					count = 1;
					iszero = true;
				}
			}
		}

		if (iszero)
		{
			zeros.push_back(count);
			ones.push_back(0);
		}
		else
		{
			ones.push_back(count);
		}

		//������0
		int res = 0;
		for (int start = 0; start <= zeros.size(); ++start)
		{
			int remaintry = K;
			int pre;
			if (start == 0) pre = 0;
			else pre = ones[start - 1];
			int pre_loc = start;

			while (pre_loc < zeros.size() && remaintry > 0)
			{
				if (remaintry >= zeros[pre_loc])
				{
					pre += zeros[pre_loc];
					pre += ones[pre_loc];
					remaintry -= zeros[pre_loc];
					pre_loc++;
				}
				else
				{
					pre += zeros[pre_loc];
					break;
				}
			}
			res = max(res, pre);
		}

		//������A����������һ��, ���൱��:
		zeros.push_back(0);
		ones.insert(ones.begin(), 0);
		//Ȼ��ת
		reverse(zeros.begin(), zeros.end());
		reverse(ones.begin(), ones.end());
		//Ȼ����ɨ��һ��
		res = 0;
		for (int start = 0; start <= zeros.size(); ++start)
		{
			int remaintry = K;
			int pre;
			if (start == 0) pre = 0;
			else pre = ones[start - 1];
			int pre_loc = start;

			while (pre_loc < zeros.size() && remaintry > 0)
			{
				if (remaintry >= zeros[pre_loc])
				{
					pre += zeros[pre_loc];
					pre += ones[pre_loc];
					remaintry -= zeros[pre_loc];
					pre_loc++;
				}
				else
				{
					pre += remaintry;
					break;
				}
			}
			res = max(res, pre);
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();

	vector<int> D = { 1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,1,1 };
	cout << s->longestOnes(D, 8) << endl;

	vector<int> C = { 1,1,1,0,0,0,0,1,1,1,1 };
	cout << s->longestOnes(C, 0) << endl;

	vector<int> A = { 1,1,1,0,0,0,1,1,1,1,0 };
	cout << s->longestOnes(A, 2) << endl;
	
	vector<int> B = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
	cout << s->longestOnes(B, 3) << endl;
	return 0;
}
*/