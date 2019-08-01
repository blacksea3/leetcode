#include "public.h"

//328ms, 86.11%
//设置一个数字->频率map,
//设置一个频率->stack数字map

class FreqStack {
private:
	unordered_map<int, int> numfreq;
	map<int, stack<int>, greater<int> > freqnum;

public:
	FreqStack() {
		;
	}

	void push(int x) {
		if (numfreq.find(x) == numfreq.end())
		{
			numfreq[x] = 1;
			freqnum[1].push(x);
		}
		else
		{
			numfreq[x]++;
			freqnum[numfreq[x]].push(x);
		}
	}

	int pop() {
		map<int, stack<int>, greater<int> >::iterator iter = freqnum.begin();
		int res = iter->second.top();
		numfreq[res]--;
		if (iter->second.size() == 1)
			freqnum.erase(iter);
		else
			iter->second.pop();
		return res;
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
