#include "public.h"

//4ms, 98.18%

//use stack

//support s only contains : '(', ')', '[', ']', '{', '}'

class Solution {
public:
	bool isValid(string s) {
		unordered_map<char, char> cmp = { {')', '('}, {']', '['}, {'}', '{'} };
		int slen = s.size();
		stack<char> stack = {};

		for (int i = 0; i < slen; ++i)
		{
			switch (s[i])
			{
			case '(':
			case '[':
			case '{':
			{
				stack.push(s[i]);
				break;
			}
			case ')':
			case ']':
			case '}':
			{
				if (stack.empty()) return false;
				if (stack.top() != cmp[s[i]]) return false;
				else stack.pop();
				break;
			}
			default:
				break;
			}
		}
		return (stack.empty()) ? true : false;
	}
};