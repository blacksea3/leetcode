#include "public.h"

//176ms, 66.22%
//DP
//��unordered_map<int, unordered_set<int>>��¼{��ǰλ��:֮ǰ������ʱ�ĳ���(�����ж������)}

//ע: ʵ���ϻ����Ի���, ���Ż�

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
