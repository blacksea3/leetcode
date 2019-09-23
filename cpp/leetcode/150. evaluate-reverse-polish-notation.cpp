#include "public.h"

//12ms, 99.12%
//ջ

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.size() == 0) return 0;
		stack<int> st;
		for (auto& token : tokens)
		{
			if (token[0] >= '0' || (token[0] == '-' && token.size() > 1))        //������һ����������,���鿴ASCII���
				st.push(stoi(token));
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
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num2 - num1);
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
