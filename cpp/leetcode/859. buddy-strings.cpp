#include "public.h"

//4ms, 97.97%
//当以下情况中的一种符合, 则为true: 1:两字符串一样且有重复字符, 2:两字符串仅仅有一对位置不一样, 且这俩字符是互相一样的

class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.size() != B.size()) return false;
		else if (A == B)
		{
			//判断
			if (A.size() > 26) return true;
			else
			{
				unordered_set<int> us;
				for (auto& a : A)
				{
					if (us.find(a) == us.end()) us.insert(a);
					else return true;
				}
				return false;
			}
		}
		else
		{
			//逐步查
			char cha = '-';
			char chb = '-';
			bool isswaped = false;
			for (int i = 0; i < A.size(); ++i)
			{
				if (A[i] == B[i]) continue;
				else if (cha == '-')
				{
					cha = A[i];
					chb = B[i];
				}
				else if (!isswaped)
				{
					if (A[i] == chb && B[i] == cha) isswaped = true;
					else return false;
				}
				else return false;
			}
			return isswaped;
		}
	}
};
