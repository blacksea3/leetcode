#include "public.h"

//

class Solution {
private:
	unordered_map<int, int> um;

	void init(vector<int>& vals)
	{
		for (auto& s : vals)
		{
			um[s] = s;
		}
	}

	int GetFather(int x) {
		return (um[x] == x ? x : um[x] = GetFather(um[x]));
	}

	void Merge(int x, int y) {
		int a = GetFather(x);
		int b = GetFather(y);
		if (a != b)
		{
			um[b] = a;
		}
	}

	vector<string> split(string t)
	{
		string pre = "";
		vector<string> res;
		for (auto& ite : t)
		{
			if (ite == ' ')
			{
				res.push_back(pre);
				pre = "";
			}
			else pre.push_back(ite);
		}
		res.push_back(pre);
		return res;
	}

	string strmerge(vector<string> input)
	{
		string pre;
		for (auto& ite : input)
		{
			pre += ite;
			pre += " ";
		}
		pre.pop_back();
		return pre;
	}

public:
	vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
		vector<int> vinit;

		vector<string> textsp = split(text);

		unordered_map<int, string> relation;
		unordered_map<string, int> relationrev;
		unordered_map<int, vector<string>> umgroup;
		int count = 0;
		for (auto& s : synonyms)
		{
			if (relationrev.find(s[0]) == relationrev.end())
			{
				vinit.push_back(count);
				relation[count] = s[0];
				relationrev[s[0]] = count;
				count++;
			}
			if (relationrev.find(s[1]) == relationrev.end())
			{
				vinit.push_back(count);
				relation[count] = s[1];
				relationrev[s[1]] = count;
				count++;
			}
		}
		for (auto& itertextsp : textsp)
		{
			if (relationrev.find(itertextsp) == relationrev.end())
			{
				vinit.push_back(count);
				relation[count] = itertextsp;
				relationrev[itertextsp] = count;
				count++;
			}
		}


		init(vinit);

		for (auto& s : synonyms)
		{
			Merge(relationrev[s[0]], relationrev[s[1]]);
		}

		//分组
		vector<vector<string>> vgroup;
		for (auto& id : vinit)
		{
			umgroup[GetFather(id)].push_back(relation[id]);
		}

		for (auto& ium : umgroup)
			vgroup.push_back(ium.second);

		//text转数组
		vector<int> resArr;

		for (auto& itertextsp : textsp)
		{
			resArr.push_back(GetFather(relationrev[itertextsp]));
		}

		vector<vector<string>> resVstr = { textsp };

		for (int i = 0; i < resArr.size(); ++i)
		{
			vector<vector<string>> tempStr;
			for (auto& itersub : umgroup[resArr[i]])
			{
				for (auto oneKindres : resVstr)
				{
					oneKindres[i] = itersub;
					tempStr.push_back(oneKindres);
				}
			}
			resVstr = tempStr;
		}

		vector<string> sRES;
		for (auto& itt : resVstr)
			sRES.push_back(strmerge(itt));

		sort(sRES.begin(), sRES.end());

		return sRES;

	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<string>> synonyms = { {"happy","joy"},{"sad","sorrow"},{"joy","cheerful"} };
	auto res = s->generateSentences(synonyms, "I am happy today but was sad yesterday");
	return 0;
}
*/
