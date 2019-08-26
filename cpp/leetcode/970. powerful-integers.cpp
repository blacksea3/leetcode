#include "public.h"

//4mss, 93.21%
//±©Á¦

class Solution {
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		unordered_set<int> res;
		int i = 0;

		while (pow(x, i) <= bound)
		{
			int j = 0;
			while ((pow(x, i) + pow(y, j)) <= bound)
			{
				res.insert((int)((pow(x, i) + pow(y, j))));
				if (y == 1) break;
				j++;
			}
			if (x == 1) break;
			i++;
		}

		vector<int> v;
		for (auto& r : res) v.push_back(r);

		return v;
	}
};
