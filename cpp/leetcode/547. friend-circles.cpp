#include "public.h"

//52ms, 10.80%
//²¢²é¼¯

class Solution {
	unordered_map<int, int> um;
	void init(vector<int>& vals)
	{
		for (auto& s : vals)
		{
			um[s] = s;
		}
	}
	int GetFather(int x) {
		return (um[x] == x ? x : um[x] = GetFather(um[x]));
	}
	void Merge(int x, int y) {
		int a = GetFather(x);
		int b = GetFather(y);
		if (a != b)
		{
			um[b] = a;
		}
	}

public:
	int findCircleNum(vector<vector<int>>& M) {
		int Msize = M.size();
		vector<int> allStudents(Msize);
		for (int index = 0; index < Msize; ++index)
		{
			allStudents[index] = index;
		}
		init(allStudents);

		for (int index = 0; index < Msize; ++index)
		{
			for (int second = index + 1; second < Msize; ++second)
			{
				if (M[index][second] == 1)
				{
					Merge(index, second);
				}
			}
		}

		unordered_set<int> fathers;
		for (int index = 0; index < Msize; ++index)
		{
			fathers.insert(GetFather(index));
		}
		return fathers.size();
	}
};
