#include "public.h"

//160ms, 44.68%
//全部放入map, 然后一组一组判断
//注意特殊情况: hand数量若不能整除W则false, 若W==1则返回true

class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {
		if (hand.size() % W != 0) return false;
		if (W == 1) return true;

		map<int, int> m;
		for (auto& h : hand)
			m[h]++;

		while (!m.empty())
		{
			pair<int, int> tempmin = *m.begin();
			int minv = tempmin.first;
			int minnums = tempmin.second;
			//直接减, 减得到零了则删除键, 减得到负值了则false
			for (int i = 1; i < W; ++i)
			{
				m[i + minv] -= minnums;
				if (m[i + minv] < 0) return false;
				else if (m[i + minv] == 0) m.erase(i + minv);
			}
			m.erase(minv);
		}
		return true;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> hand = { 1,2,3,6,2,3,4,7,8 };
	cout << s->isNStraightHand(hand, 3);
	return 0;
}
*/
