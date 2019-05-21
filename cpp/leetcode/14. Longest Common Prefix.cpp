#include "public.h"

//12ms, 93.14%

//可能有这么思考复杂的:先找出最短的字符串
//然后二分查找比较: 先比较前一半的,如果都公共,比较后一半中的前一半,否则比较前一半中的前一半
//这样实际上也存在重复比较,(好像)并不会产生形如O(logn)的时间复杂度

//我查看了评论以及耗时低的算法,发现:1、直接暴力就行 
//2、特殊操作:考虑到以下情形:一坨字符串他们拥有公共字符串前缀+自己的字符串们,
//  那么最大的字符串与最小字符串的公共字符串前缀一定是所有的字符串前缀:
//  理由:删除公共字符串前缀之后,最大字符串与最小字符串的第一个字母一定拥有极大的差距,如果二者相同那么所有大小
//  介于最大字符串与最小字符串的字符串也拥有相同的第一个字母,这与删除公共字符串前缀矛盾
//  这种特殊操作的优点是极大降低了代码长度

class Solution {
private:
	string max_element_m(vector<string>& strs)
	{
		string res = strs[0];
		for (int i = 1; i < strs.size(); i++)
			res = (res < strs[i]) ? strs[i] : res;
		return res;
	}

	string min_element_m(vector<string>& strs)
	{
		string res = strs[0];
		for (int i = 1; i < strs.size(); i++)
			res = (res > strs[i]) ? strs[i] : res;
		return res;
	}

	string mismatch_m(string s1, string s2)
	{
		int smallsize = min(s1.size(), s2.size());
		int loc = 0;
		while ((loc < smallsize) && (s1[loc] == s2[loc])) ++loc;
		return s1.substr(0, loc);
	}

public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];

		string maxstr = max_element_m(strs);
		string minstr = min_element_m(strs);
		return mismatch_m(maxstr, minstr);

		//我不知道这个FUCK C++的mismatch函数是干啥的
		//但是:mismatch(元素1起始指针,元素1结束指针,元素2起始指针) 其中元素1长度应当<=元素2,否则在我的VS2017里面报错?!
		// 哪个bitch设计的
		//这导致我无法使用库,FUCCCCCCKKKK
		/*
		auto maxstr = max_element(strs.begin(), strs.end());
		auto minstr = min_element(strs.begin(), strs.end());
		auto misloc = mismatch(maxstr->begin(), maxstr->end(), minstr->begin());
		return string(maxstr->begin(), misloc.first);
		*/
	}
};

int main()
{
	Solution* s = new Solution();
	vector<string> strs = { "flower", "flop" };
	string res = s->longestCommonPrefix(strs);
	delete s;
	return 0;
}
