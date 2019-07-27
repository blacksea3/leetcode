#include "public.h"

//24ms, 60.26%
//排序, 然后模拟
//倒过来: 按从大到小顺序放: 最大的放在最前面: 然后把最后面的拿出来放到开头
//deque模拟

class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		deque<int> dq;
		sort(deck.begin(), deck.end(), greater<int>());

		for (int i = 0; i < deck.size(); ++i)
		{
			dq.push_front(deck[i]);
			int temp = dq.back();
			dq.pop_back();
			dq.push_front(temp);
		}

		//回退一步
		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);

		vector<int> v(dq.begin(), dq.end());
		return v;
	}
};
