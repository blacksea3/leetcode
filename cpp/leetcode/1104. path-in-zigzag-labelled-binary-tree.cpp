#include "public.h"

//4ms, 80.13%
//easy problem, ÕÒ¹æÂÉ

class Solution {
public:
	vector<int> pathInZigZagTree(int label) {
		vector<int> res;
		while (label > 1)
		{
			res.insert(res.begin(), label);
			label /= 2;
		}
		res.insert(res.begin(), 1);

		if (res.size() % 2)
		{
			for (int i = 1; i < res.size(); i += 2)
			{
				res[i] = (int)pow(2, i + 1) - 1 + (int)pow(2, i) - res[i];
			}
		}
		else
		{
			for (int i = 0; i < res.size(); i += 2)
			{
				res[i] = (int)pow(2, i + 1) - 1 + (int)pow(2, i) - res[i];
			}
		}
		return res;
	}
};
