#include "public.h"

//12ms, 85.16%
//模拟:
//进行如下操作: 如果栈是空的或者栈顶不等于popped的当前值, 那么push(要是这时候pushed空了就返回false)
//否则pop, 如果pop完了, popped空了则返回true

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;

		int pushloc = 0;
		int poploc = 0;

		while (poploc < popped.size())
		{
			if (st.empty() || st.top() != popped[poploc])
			{
				if (pushloc >= pushed.size()) return false;
				else
				{
					st.push(pushed[pushloc++]);
				}
			}
			else
			{
				st.pop();
				poploc++;
			}
		}
		return true;
	}
};
