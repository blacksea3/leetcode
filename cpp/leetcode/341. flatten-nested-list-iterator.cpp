#include "public.h"

/*
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
	public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

//24ms, 89.56%
//栈, 利用双栈存储当前遍历层数(begin和end迭代器)

class NestedIterator {
private:
	stack<vector<NestedInteger>::iterator> begins;
	stack<vector<NestedInteger>::iterator> ends;
	int ne;

public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		begins.push(nestedList.begin());
		ends.push(nestedList.end());
	}

	int next() {
		return (begins.top()++)->getInteger();
	}

	bool hasNext() {
		while (!begins.empty())
		{
			if (begins.top() == ends.top())
			{
				begins.pop();
				ends.pop();
			}
			else
			{
				auto val = begins.top();
				if (val->isInteger())
					return true;
				begins.top()++;
				//注：此处若写成
				//vector<NestedInteger> v = val->getList();
				//begins.push(v.begin());
				//ends.push(v.end());
				//则在线运行 heap use after free, 原因不详

				begins.push(val->getList().begin());
				ends.push(val->getList().end());
			}
		}
		return false;
	}
};
*/

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
