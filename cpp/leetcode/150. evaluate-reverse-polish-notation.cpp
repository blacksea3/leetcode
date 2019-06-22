#include "public.h"

//20ms, 90.21%

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		//ջ
		if (tokens.size() == 0) return 0;

		stack<int> st;

		//����������Ч
		for (auto token : tokens)
		{
			if (token[0] >= '0') //������һ����������,���鿴ASCII���
				st.push(atoi(token.c_str()));
			else if (token[0] == '+')
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num1 + num2);
			}
			else if (token[0] == '-')
			{
				if (token.size() > 1)
				{
					st.push(atoi(token.c_str()));
				}
				else
				{
					int num1 = st.top();
					st.pop();
					int num2 = st.top();
					st.pop();
					st.push(num2 - num1);
				}
			}
			else if (token[0] == '*')
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num1*num2);
			}
			else
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num2 / num1);
			}
		}
		return st.top();
	}
};
