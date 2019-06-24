#include "public.h"

//4ms, 90.78%

//双队列（一个是存储队列（如果从front看的话，front是最后push的），一个是temp）,
//对于某个push情况把其他元素移动到temp队列,然后push这个元素至存储队列，最后把temp队列的全部移动回存储队列

class MyStack {
private:
	queue<int>q1;
	queue<int>q2;
public:
	/** Initialize your data structure here. */
	MyStack() {
		;
	}

	/** Push element x onto stack. */
	void push(int x) {
		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		q1.push(x);
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int temp = q1.front();
		q1.pop();
		return temp;
	}

	/** Get the top element. */
	int top() {
		return q1.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */