#include "public.h"

//8ms, 98.69%

//数字转成字符串然后自定义排序函数，然后将排序后的字符串连接起来，去除开头的0

class Solution {
private:
	//num1 != num2
	//考虑对两个数字单独比较 从最高位开始比较
	//return false: num1 <= num2, true: num1 > num2;
	static bool cmpnum_179(const string& num1, const string& num2)
	{
		//直接把num1拼到num2上面去吧
		//用string 比较!
		string s1 = num1 + num2;
		string s2 = num2 + num1;
		return s1 > s2 ? true : false;
	}

public:
	string largestNumber(vector<int>& nums) {
		//相当于给nums排序
		//考虑对两个数字单独比较 从最高位开始比较
		//使用内置sort
		vector<string> strs;
		for (auto& n : nums) strs.push_back(to_string(n));

		sort(strs.begin(), strs.end(), cmpnum_179);

		//遍历,生成string
		string res = "";
		for (auto s : strs) res += s;

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
