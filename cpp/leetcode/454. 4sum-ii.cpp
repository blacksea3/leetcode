#include "public.h"

//684ms, 23.10%
//ֱ�Ӽ��仯
//ͳ��A+B�Ŀ�����
//ͳ��C+D�Ŀ�����
//��������map, Ȼ�������һ��map, �ڵڶ����Ҿ���

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> memoryAB;
		unordered_map<int, int> memoryCD;

		for (auto& a : A)
			for (auto& b : B)
				memoryAB[a + b]++;
		for (auto& c : C)
			for (auto& d : D)
				memoryCD[c + d]++;

		int res = 0;
		for (auto& iter_memoryAB : memoryAB)
			if (memoryCD.find(-1 * iter_memoryAB.first) != memoryCD.end())
				res += iter_memoryAB.second * memoryCD[-1 * iter_memoryAB.first];

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> A = { 1,2};
	//vector<int> B = { -2, -1};
	//vector<int> C = { -1, 2};
	//vector<int> D = { 0, 2};
	//cout << s->fourSumCount(A, B, C, D);
	vector<int> A = { -1,-1 };
	vector<int> B = { -1, 1 };
	vector<int> C = { -1, 1 };
	vector<int> D = { 1, -1 };
	cout << s->fourSumCount(A, B, C, D);
	return 0;
}
*/
