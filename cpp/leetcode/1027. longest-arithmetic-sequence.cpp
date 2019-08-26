#include "public.h"

//1084ms, 79.28%
//记忆化: 给一个vector<unordered_map<int, int>> v(10001, 0) 下标:接下来的可能数字, 值um: 键:delta(后一个减前一个), 值:已经的连续长度

class Solution {
public:
	int longestArithSeqLength(vector<int>& A) {
		vector<unordered_map<int, int>> v(10001);
		int res = 2;

		for (int i = 1; i < A.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (A[i] == A[j]) continue;
				int temp = 2 * A[i] - A[j];
				if (temp >= 0 && temp <= 10000)
					if (v[temp].find(A[i] - A[j]) == v[temp].end())
						v[temp][A[i] - A[j]] = 2;
			}
			for (auto& mp : v[A[i]])
			{
				int nexttemp = A[i] + mp.first;
				res = max(res, mp.second + 1);
				if (nexttemp >= 0 && nexttemp <= 10000)
				{
					if (v[nexttemp].find(mp.first) == v[nexttemp].end())
						v[nexttemp][mp.first] = mp.second + 1;
					else if (v[nexttemp][mp.first] < (mp.second + 1))
						v[nexttemp][mp.first] = mp.second + 1;
				}
			}
			v[A[i]] = {};
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> A = { 3,6,9,12 };
	//vector<int> A = { 58, 100, 53, 24, 25, 38, 44, 55, 23, 17, 41, 66, 10 };
	//vector<int> A = { 24, 13, 1, 100, 0, 94, 3, 0, 3 };
	vector<int> A = { 7, 24, 7, 12, 2, 69, 9, 74, 73, 66, 77, 78, 29, 16, 31, 74, 45, 2, 4, 61, 47, 35, 55, 76, 65, 5, 65, 45, 12, 51, 2, 5, 34, 9, 61, 3, 9, 17, 49, 54, 76, 2, 32, 29, 62, 19, 52, 41, 7, 3, 41, 22, 48, 15, 8, 21, 45, 64, 51, 20, 76, 1, 50, 47, 65, 75, 55, 54, 22, 21 };
	auto res = s->longestArithSeqLength(A);
	return 0;
}
*/
