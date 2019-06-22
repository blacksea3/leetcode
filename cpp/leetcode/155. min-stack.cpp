#include "public.h"

//44ms, 88.04%

class MinStack {
private:
	stack<int> real;
	stack<int> mins;

public:
	/** initialize your data structure here. */
	MinStack() {
		//˫ջ
		//һ���Ǽ�¼Ԫ�ص�ջ
		//һ���Ǽ�¼��Сֵ��ջ
	}

	void push(int x) {
		real.push(x);
		if (mins.empty())
			mins.push(x);
		else
			mins.push(min(mins.top(), x));
	}

	void pop() {
		real.pop();
		mins.pop();
	}

	int top() {
		return real.top();
	}

	int getMin() {
		return mins.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */