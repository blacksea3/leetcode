#include "public.h"

//0ms, 100%

//双队列（一个是存储队列（如果从front看的话，front是最后push的），一个是temp）,
//对于某个push情况把其他元素移动到temp队列,然后push这个元素至存储队列，最后把temp队列的全部移动回存储队列

class MyStack {
private:
	queue<int>q1;
	queue<int>q2;
public:
	MyStack() {
		;
	}

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

	int pop() {
		int temp = q1.front();
		q1.pop();
		return temp;
	}

	int top() {
		return q1.front();
	}

	bool empty() {
		return q1.empty();
	}
};
