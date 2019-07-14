#include "public.h"

//92ms, 62.89%
//ตÝน้

class Solution {
private:
	int res = 0;

	void recu_pb(vector<char> v, int prelen, int maxlen)
	{
		res++;
		if (prelen == maxlen) return;
		unordered_set<char> us;

		for (int i = 0; i < v.size(); ++i)
		{
			if (us.find(v[i]) == us.end())
			{
				us.insert(v[i]);
				char temp = v[i];
				v.erase(v.begin() + i);
				recu_pb(v, prelen + 1, maxlen);
				v.insert(v.begin() + i, temp);
			}
			else continue;
		}
	}

public:
	int numTilePossibilities(string tiles) {
		vector<char> v = {};
		for (auto c : tiles)
			v.push_back(c);

		recu_pb(v, 0, tiles.size());
		return res - 1;
	}
};
