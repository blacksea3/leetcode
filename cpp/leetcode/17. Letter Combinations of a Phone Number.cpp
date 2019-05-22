#include "public.h"

//8ms, 92.38%

//use BackTracking

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		unordered_map<char, vector<string>> um = {
		{'2',{"a","b","c"}},{'3',{"d","e","f"}},{'4',{"g","h","i"}},{'5',{"j","k","l"}},{'6',{"m","n","o"}},{'7',{"p","q","r","s"}},{'8',{"t","u","v"}},{'9',{"w","x","y","z"}}
		};
		unordered_set<char> lastchar{ 'c','f','i','l','o','s','v','z' };

		//回溯
		string prestr;
		int dsize = digits.size();
		bool isneed_backt = false;
		int prelen = 1;
		vector<string> res = {};

		if (dsize == 0) return vector<string>{};
		prestr += um[digits[0]][0];

		while (true)
		{
			if (isneed_backt)
			{
				if (prestr.empty()) break;
				if (lastchar.find(prestr[prestr.size() - 1]) == lastchar.end())
				{
					//修改当前字母
					prestr[prestr.size() - 1]++;
					isneed_backt = false;
				}
				else  //还需要回溯
				{
					prestr.pop_back();
					prelen--;
				}
			}
			else
			{
				if (prelen == dsize)
				{
					isneed_backt = true;
					res.push_back(prestr);
				}
				else
				{
					prestr += um[digits[prelen]][0];
					prelen++;
				}
			}
		}
		return res;
	}
};