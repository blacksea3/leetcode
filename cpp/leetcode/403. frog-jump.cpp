#include "public.h"

//176ms, 66.22%
//DP
//用unordered_map<int, unordered_set<int>>记录{当前位置:之前跳过来时的长度(可能有多种情况)}

//注: 实际上还可以回溯, 待优化

class Solution {
public:
	bool canCross(vector<int>& stones) {
		unordered_map<int, unordered_set<int>> m;

		for (auto& stone : stones)
			m[stone] = unordered_set<int>{};
		m[0].insert(0);
		int target = stones.back();

		for (auto& stone:stones)
		{
			for (auto& next : m[stone])
				for (int step = max(next - 1, 1); step <= next + 1; ++step)
					if (m.find(stone + step) != m.end())
						m[stone + step].insert(step);
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
