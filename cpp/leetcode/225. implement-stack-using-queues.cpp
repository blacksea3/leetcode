#include "public.h"

//0ms, 100%

//˫���У�һ���Ǵ洢���У������front���Ļ���front�����push�ģ���һ����temp��,
//����ĳ��push���������Ԫ���ƶ���temp����,Ȼ��push���Ԫ�����洢���У�����temp���е�ȫ���ƶ��ش洢����

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
