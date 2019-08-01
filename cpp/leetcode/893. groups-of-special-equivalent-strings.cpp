#include "public.h"

//36ms, 22.81%
//对字符串进行这样的处理: 数奇数位和偶数位的各种字符个数, 转化为一个特殊值, 作为标记放入set
//最后看set的长度

class Solution {
private:
	string convert(const string& s)
	{
		//奇数位
		vector<int> odd(26, 0);
		vector<int> even(26, 0);

		for (int i = 0; i < s.size(); i += 2)
		{
			odd[s[i] - 'a']++;
		}
		for (int i = 1; i < s.size(); i += 2)
		{
			even[s[i] - 'a']++;
		}

		string res;

		for (int i = 0; i < 26; ++i)
		{
			if (odd[i] > 0)
			{
				res += to_string(odd[i]);
				res.push_back(i + 'a');
			}
		}
		for (int i = 0; i < 26; ++i)
		{
			if (even[i] > 0)
			{
				res += to_string(even[i]);
				res.push_back(i + 'a');
			}
		}
		return res;
	}


public:
	int numSpecialEquivGroups(vector<string>& A) {
		set<string> s;
		for (auto& a : A)
		{
			s.insert(convert(a));
		}
		return s.size();
	}
};
