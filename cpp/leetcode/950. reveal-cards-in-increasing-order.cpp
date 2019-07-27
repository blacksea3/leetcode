#include "public.h"

//24ms, 60.26%
//����, Ȼ��ģ��
//������: ���Ӵ�С˳���: ���ķ�����ǰ��: Ȼ����������ó����ŵ���ͷ
//dequeģ��

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

		//����һ��
		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);

		vector<int> v(dq.begin(), dq.end());
		return v;
	}
};
