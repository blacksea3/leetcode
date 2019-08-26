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
//ջ

class Solution {
public:
	//ע��: s�ǿ�
	//ջ
	//�������: ջΪ��������Ϊ����, ��ֱ�ӷ���
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
				if (!tempnum.empty())  //�����ǰ������, �����
					pre.add(NestedInteger(stoi(tempnum)));
				//���stack�ǿ���, �ѵ�ǰ��nestedinteger������һ��; ����ֱ�ӷ���
				st.pop();
				if (st.empty()) return pre;
				else
				{
					NestedInteger& his = st.top();  //����ʹ������(��ָ��), ����͵����ٷ����(��ʱ��)
					his.add(pre);
				}
				tempnum = "";
			}
			else  //,��, ǰ�����������, ��ôadd, ����ǰ����], ���Ѿ���ӹ���, �Ͳ��ò�����
			{
				if (!tempnum.empty())
				{
					NestedInteger& his = st.top();  //����ʹ������(��ָ��), ����͵����ٷ����(��ʱ��)
					his.add(stoi(tempnum));
					tempnum = "";
				}
			}
		}

		//�����������ʽ��ȷ, �ǲ��ᵽ�����
		return dump;
	}
};
