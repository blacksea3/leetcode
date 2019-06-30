#include "public.h"

//执行用时 :
//20 ms, 在所有 C++ 提交中击败了95.00%的用户（  速度不稳定，这是最快速度 :(  ）
//内存消耗 :15.2 MB, 在所有 C++ 提交中击败了100.00%的用户

//考虑以下的思路: 逐层递归写法
//对于某个递归函数，返回当前函数的unordered_set结果，
//  以及一个int坐标，如果有}则表示右大括号的下一个坐标，否则一定是expression.size()，即超出范围
//此函数定义
//  unordered_set<string> res;表示此函数的结果，unordered_set<string> preset;表示当前的字符串集合
//首先循环读取字符
// 如果读取到逗号，那么把preset加到res上，当前坐标+1
// 如果读取到{号，那么递归下一层，把他的返回set乘到preset上，更新当前坐标至对应的右大括号的下一个坐标/或者字符串末尾
// 如果读取到}号，那么把preset加到res上，返回unordered_set：res以及int：当前坐标+1
// 否则（即字母），直接突进读取连续字母，然后把这个字符串乘到preset上，当前坐标=连续字母末尾 

//循环结束表示坐标到expression末尾了，那么把preset加到res上，返回unordered_set：res以及int：当前坐标（即expression末尾）

//入口函数调用这个递归函数，将返回值unordered_set转换成vector然后排个序

class Solution {
private:
	//add source to raw
	//加法
	void mergeAdd(unordered_set<string>& raw, const unordered_set<string>& source)
	{
		for (auto s : source) raw.insert(s);
	}

	//Mul source to raw
	//here if source is empty, then raw will be set {}  :)
	//笛卡尔积，乘法
	void mergeMul(unordered_set<string>& raw, const unordered_set<string>& source)
	{
		if (raw.empty()) raw = source;
		else
		{
			unordered_set<string> res;
			for (auto r : raw)
				for (auto s : source)	
					res.insert(r + s);
			raw = res;
		}
	}

	pair<unordered_set<string>, int> recu_braceExpansionII(const string& expression, int startloc)
	{
		unordered_set<string> res;
		unordered_set<string> preset;
		while (startloc < expression.size())
		{
			if (expression[startloc] == ',')
			{
				mergeAdd(res, preset);
				preset.clear();
				startloc++;
			}
			else if (expression[startloc] == '{')
			{
				pair<unordered_set<string>, int> inner = recu_braceExpansionII(expression, startloc + 1);
				mergeMul(preset, inner.first);
				startloc = inner.second;
			}
			else if (expression[startloc] == '}')
			{
				mergeAdd(res, preset);
				pair<unordered_set<string>, int> returns;
				returns.first = res;
				returns.second = startloc + 1;
				return returns;
			}
			else
			{
				string curr = "";
				while (startloc < expression.size() && expression[startloc] >= 'a' && expression[startloc] <= 'z') {
					curr.push_back(expression[startloc++]);
				}
				mergeMul(preset, unordered_set<string>{curr});
			}
		}
		//到这里一定是下标startloc == expression.size()
		mergeAdd(res, preset);
		pair<unordered_set<string>, int> returns;
		returns.first = res;
		returns.second = startloc;
		return returns;
	}

public:
	vector<string> braceExpansionII(string expression) {
		pair<unordered_set<string>, int> totalres = recu_braceExpansionII(expression, 0);
		vector<string> returnres(totalres.first.begin(), totalres.first.end());
		sort(returnres.begin(), returnres.end());
		return returnres;
	}
};


/*
int main()
{
	Solution* s = new Solution();
	vector<string> res = s->braceExpansionII("{a,b}{c{d,e}}");
	return 0;
}*/