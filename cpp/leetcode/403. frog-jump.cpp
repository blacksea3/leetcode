#include "public.h"

//324ms, 54.88%
//DP
//用map记录{当前位置:之前跳过来时的长度}

class Solution {
public:
	bool canCross(vector<int>& stones) {
		map<int, unordered_set<int>> m;

		for (auto& stone : stones)
			m.insert(pair<int, unordered_set<int>>{stone, unordered_set<int>{}});
		m[0].insert(0);
		int target = stones[stones.size() - 1];

		map<int, unordered_set<int>>::iterator iter = m.begin();
		while (iter != m.end())
		{
			for (auto& next : iter->second)
				for (int step = max(next - 1, 1); step <= next + 1; ++step)
					if (m.find(iter->first + step) != m.end())
						m[iter->first + step].insert(step);
			iter++;
		}
		return !m[target].empty();
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> stones = { 0,1,3,5,6,8,12,17 };
	cout << s->canCross(stones);
	return 0;
}
*/
