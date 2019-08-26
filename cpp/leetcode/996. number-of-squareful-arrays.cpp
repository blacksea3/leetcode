#include "public.h"

//4ms, 86.49%
//±©Á¦

class Solution {
private:
	int res = 0;

	void recu(int before, vector<int> chooses)
	{
		if (chooses.empty()) res++;
		else
		{
			int old = -1;
			for (int i = 0; i < chooses.size(); ++i)
			{
				int val = chooses[i];
				if (old == val) continue;
				else old = val;
				double x = sqrt(before + val);
				if (floor(x) == x)
				{
					chooses.erase(chooses.begin() + i);
					recu(val, chooses);
					chooses.insert(chooses.begin() + i, val);
				}
			}
		}
	}

public:
	int numSquarefulPerms(vector<int>& A) {
		sort(A.begin(), A.end());
		int old = -1;
		for (int i = 0; i < A.size(); ++i)
		{
			int v = A[i];
			if (old == v) continue;
			else old = v;
			A.erase(A.begin() + i);
			recu(v, A);
			A.insert(A.begin() + i, v);
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> A = { 1, 17, 8 };
	auto res = s->numSquarefulPerms(A);
	return 0;
}
