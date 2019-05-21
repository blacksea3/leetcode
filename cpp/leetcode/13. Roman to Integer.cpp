#include "public.h"

//24ms, 97.29%

//一轮循环
//从头开始判断,如果当前值<下一个值说明是组合数
//考虑到:例如IV这样的组合数=V-I,因此可以由这个规律进行书写

class Solution {
public:
	int romanToInt(string s) {
		//假设输入合法
		unordered_map<char, int> um = { {'I',1}, {'V', 5}, {'X', 10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		int returnres = 0;
		int i; //循环用的,且循环外我也需要它
		for ( i = 0; i < s.size() - 1;)
		{
			if (um[s[i]] < um[s[i + 1]])
			{
				returnres += (um[s[i + 1]] - um[s[i]]);
				i += 2;
			}
			else
			{
				returnres += um[s[i]];
				++i;
			}
		}
		returnres += um[s[i]];
		return returnres;
	}
};
