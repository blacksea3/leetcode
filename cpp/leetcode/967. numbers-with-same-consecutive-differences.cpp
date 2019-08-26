#include "public.h"

//24ms, 30.00%
//×éºÏ, DFS

class Solution {
private:
	vector<int> res;
	int gblN;

	int v2i(vector<int> v)
	{
		int r = 0;
		for (auto& iv : v) r = r * 10 + iv;
		return r;
	}

	void DFS(vector<int> pre, int old, int K, int pren)
	{
		if (pren == gblN)
		{
			res.push_back(v2i(pre));
		}
		else
		{
			if (K != 0)
			{
				if (((old + K) >= 0) && ((old + K) <= 9))
				{
					pre.push_back(old + K);
					DFS(pre, old + K, K, pren + 1);
					pre.pop_back();
				}
				if (((old - K) >= 0) && ((old - K) <= 9))
				{
					pre.push_back(old - K);
					DFS(pre, old - K, K, pren + 1);
					pre.pop_back();
				}
			}
			else
			{
				pre.push_back(old);
				DFS(pre, old, K, pren + 1);
				pre.pop_back();
			}
		}
	}


public:
	vector<int> numsSameConsecDiff(int N, int K) {
		gblN = N;
		for (int i = 1; i <= 9; ++i)
		{
			DFS({ i }, i, K, 1);
		}
		if (N == 1) res.push_back(0);

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->numsSameConsecDiff(6, 1);
	return 0;
}
*/
