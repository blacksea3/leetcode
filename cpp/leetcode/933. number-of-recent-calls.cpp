#include "public.h"

//268ms, 90.71%
//����: �Ƚ��ȳ�

class RecentCounter {
private:
	queue<int> q;
public:
	RecentCounter() {
		;
	}

	int ping(int t) {
		while (!q.empty() && ((t - q.front()) > 3000)) q.pop();
		q.push(t);
		return q.size();
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
