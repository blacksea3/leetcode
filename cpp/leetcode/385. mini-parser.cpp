#include "public.h"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Constructor initializes an empty nested list.
	NestedInteger();

	// Constructor initializes a single integer.
	NestedInteger(int value);

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Set this NestedInteger to hold a single integer.
	void setInteger(int value);

	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger &ni);

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

//32ms, 61.48%
//栈

class Solution {
public:
	//注意: s非空
	//栈
	//特殊情况: 栈为空且输入为数字, 则直接返回
	NestedInteger deserialize(string s) {
		stack<NestedInteger> st;
		string tempnum;

		NestedInteger dump;

		for (auto& iis:s)
		{
			if (isdigit(iis) || iis == '-')
			{
				if (st.empty()) return NestedInteger(stoi(s));
				tempnum += iis;
			}
			else if (iis == '[')
			{
				NestedInteger newni = NestedInteger();
				st.push(newni);
			}
			else if (iis == ']')
			{
				NestedInteger pre = st.top();
				if (!tempnum.empty())  //如果当前有数字, 则放入
					pre.add(NestedInteger(stoi(tempnum)));
				//如果stack非空则, 把当前的nestedinteger放入上一层; 否则直接返回
				st.pop();
				if (st.empty()) return pre;
				else
				{
					NestedInteger& his = st.top();  //必须使用引用(或指针), 否则就弹出再放入吧(耗时间)
					his.add(pre);
				}
				tempnum = "";
			}
			else  //,号, 前面可能是数字, 那么add, 否则前面是], 这已经添加过了, 就不用操作了
			{
				if (!tempnum.empty())
				{
					NestedInteger& his = st.top();  //必须使用引用(或指针), 否则就弹出再放入吧(耗时间)
					his.add(stoi(tempnum));
					tempnum = "";
				}
			}
		}

		//理论上输入格式正确, 是不会到这里的
		return dump;
	}
};
