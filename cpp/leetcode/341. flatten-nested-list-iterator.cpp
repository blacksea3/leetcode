#include "public.h"

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

//32ms, 59.48%
//ջ

class NestedIterator {
private:
	stack<NestedInteger> st;
	int ne;

public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		for (int i = nestedList.size() - 1; i >= 0; --i)
		{
			st.push(nestedList[i]);
		}
	}

	int next() {
		return ne;
	}

	bool hasNext() {
		while (!st.empty())
		{
			NestedInteger pre = st.top();
			st.pop();
			if (pre.isInteger())
			{
				ne = pre.getInteger();
				return true;
			}
			else
			{
				vector<NestedInteger> next = pre.getList();
				for (int i = next.size() - 1; i >= 0; --i)
				{
					st.push(next[i]);
				}
			}
		}
		return false;
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
