#include "public.h"

//4180ms, 19.72%
//暴力并查集

class Solution {
private:
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

	bool issimilar(const string& s1, const string& s2)
	{
		int loc = 0;
		int dif = 0;
		while (loc < s1.size())
		{
			if (s1[loc] != s2[loc])
			{
				dif++;
			}
			if (dif > 2) return false;
			loc++;
		}
		return true;
	}

public:
	int numSimilarGroups(vector<string>& A) {
		vector<int> vals;
		for (int i = 0; i < A.size(); ++i)
			vals.push_back(i);
		init(vals);

		for (int i = 0; i < A.size() - 1; ++i)
		{
			for (int j = i + 1; j < A.size(); ++j)
			{
				if (GetFather(i) == GetFather(j)) continue;
				else
				{
					if (issimilar(A[i], A[j])) Merge(i, j);
				}
			}
		}

		unordered_set<int> us;
		for (int i = 0; i < A.size(); ++i)
		{
			us.insert(GetFather(i));
		}
		return us.size();
	}
};
