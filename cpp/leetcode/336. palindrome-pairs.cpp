#include "public.h"

//288ms, 89.35%
//先放入unordered_map<string, int> 字符串: 索引
//然后分为四种情况: 此四种情况对单个非空字符串可以叠加
//1、自身是回文且存在空字符串则索引对添加两次(此时把空字符串也考虑进来, 有正反两对)
//2、自身反转后在map中能找到则添加
//3、自身的前一部分是回文，后一部分反转后能找到则添加
//4、自身的后一部分是回文，前一部分反转后能找到则添加

class Solution {
private:
	bool isPalindrome(string const& s)
	{
		int l = 0;
		int r = s.size() - 1;
		while (l < r && s[l] == s[r])
		{
			l++;
			r--;
		}
		return (l >= r);
	}

public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> um;

		for (int index = 0; index < words.size(); ++index) um[words[index]] = index;

		vector<vector<int>> res;
		unordered_map<string, int>::iterator iter = um.find("");
		bool isFindEmpty = (iter != um.end());

		for (auto& iterum : um)
		{
			string s = iterum.first;
			if (s == "") continue;
			for (int sIndex = 1; sIndex < s.size(); ++sIndex)
			{
				if (isPalindrome(s.substr(sIndex)))
				{
					string preS = s.substr(0, sIndex);
					reverse(preS.begin(), preS.end());
					if (um.find(preS) != um.end())
					{
						res.emplace_back(vector<int>{iterum.second, um[preS]});
					}
				}
				if (isPalindrome(s.substr(0, sIndex)))
				{
					string posS = s.substr(sIndex);
					reverse(posS.begin(), posS.end());
					if (um.find(posS) != um.end())
					{
						res.emplace_back(vector<int>{um[posS], iterum.second});
					}
				}
			}
			string cpS = s;
			reverse(cpS.begin(), cpS.end());
			if (um.find(cpS) != um.end() && um[cpS] != iterum.second)
				res.emplace_back(vector<int>{um[cpS], iterum.second});

			if (isPalindrome(s) && isFindEmpty)
			{
				res.emplace_back(vector<int>{um[""], iterum.second});
				res.emplace_back(vector<int>{iterum.second, um[""]});
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> words = {"abcd","dcba","lls","s","sssll"};
	auto res = s->palindromePairs(words);
	return 0;
}
*/
