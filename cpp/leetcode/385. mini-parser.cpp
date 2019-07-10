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

class Solution {
private:
	//if call this func, it must be a nested list
	NestedInteger recu_deserialize(string s, int startloc)
	{
		NestedInteger res = NestedInteger();
		while (startloc < s.size())
		{
			if (isdigit(s[startloc]))
			{
				int temp = 0;
				while (startloc < s.size() && s[startloc] != ',')
				{
					temp = temp * 10 + s[startloc] - '0';
					startloc++;
				}
			}
			else if (s[startloc] == '-')
			{

			}
			else
			{

			}
		}
	}

public:
	//×¢Òâ: s·Ç¿Õ
	NestedInteger deserialize(string s) {
		if (s[0] == '[')
			return recu_deserialize(s, 1);
	}
};
