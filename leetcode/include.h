#pragma once

//#define LEETCODE_WC

//#define LEETCODE_01_10
//#define LEETCODE_11_20
//#define LEETCODE_21_30
//#define LEETCODE_31_40
//#define LEETCODE_41_50
//#define LEETCODE_51_60
//#define LEETCODE_61_70
//#define LEETCODE_71_80
//#define LEETCODE_81_90
//#define LEETCODE_91_100
//#define LEETCODE_101_110
//#define LEETCODE_111_120
//#define LEETCODE_121_130
//#define LEETCODE_131_140
//#define LEETCODE_141_150
//#define LEETCODE_151_160
#define LEETCODE_161_170

#ifdef LEETCODE_131_140

//for problem 133
class Node_133 {
public:
	int val;
	vector<Node_133*> neighbors;

	Node_133() {}

	Node_133(int _val, vector<Node_133*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

//for problem 138
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

#ifdef LEETCODE_151_160
//for problem 155
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
#else
#endif

#else
#endif