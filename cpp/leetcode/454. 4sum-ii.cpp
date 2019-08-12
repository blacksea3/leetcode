#include "public.h"

//684ms, 23.10%
//直接记忆化
//统计A+B的可能性
//统计C+D的可能性
//都记入至map, 然后遍历第一个map, 在第二个找就行

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
