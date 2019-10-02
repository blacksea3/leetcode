#include "public.h"

//12ms, 85.62%
//数字转成字符串然后自定义排序函数，然后将排序后的字符串连接起来，去除开头的0

class Solution {
private:
	//num1 != num2
	//考虑对两个数字单独比较 从最高位开始比较
	//return false: num1 <= num2, true: num1 > num2;
	static bool msort(string const& num1, string const& num2)
	{
		string s1 = num1 + num2;
		string s2 = num2 + num1;
		return s1 > s2 ? true : false;
	}

public:
	string largestNumber(vector<int>& nums) {
		vector<string> strs;
		for (auto& n : nums) strs.emplace_back(to_string(n));

		sort(strs.begin(), strs.end(), msort);

		//遍历,生成string
		string res = "";
		for (auto& s : strs) res += s;

		//有必要去除开头的0, FUCK
		//这仅仅会出现在全是0的情况......
		while (res.size() > 1)
			if (res[0] == '0')
				res.erase(res.begin());
			else
				break;
		return res;
	}
};
