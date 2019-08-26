#include "public.h"

//108ms, 93.55%
//ע: �����е�Ԫ������: ���滻�����޶�, ���仰˵, ���������е�a���û���ͬһ��Ԫ��, e i o u ͬ��
//ע�����ȼ�����, �������word��Сд/passԪ����ͬ, Ӧ����¼ǰһ��, ��ô���絹�����wordlist:)

class Solution {
private:
	string tolow(string raw)
	{
		for (int i = 0; i < raw.size(); ++i)
		{
			raw[i] = (raw[i] <= 'z' && raw[i] >= 'a') ? raw[i] : raw[i] - 'A' + 'a';
		}
		return raw;
	}
	string passvowel(string raw)
	{
		for (int i = 0; i < raw.size(); ++i)
		{
			raw[i] = (raw[i] == 'a' || raw[i] == 'e' || raw[i] == 'i' || raw[i] == 'o' || raw[i] == 'u') ? '*' : raw[i];
		}
		return raw;
	}

public:
	vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
		unordered_set<string> perfect;
		unordered_map<string, string> low;
		unordered_map<string, string> pass_vowel;

		for (int i = wordlist.size() - 1; i >= 0; --i)
		{
			perfect.insert(wordlist[i]);
			low[tolow(wordlist[i])] = wordlist[i];
			pass_vowel[passvowel(tolow(wordlist[i]))] = wordlist[i];
		}

		vector<string> res;
		for (int i = 0; i < queries.size(); ++i)
		{
			if (perfect.find(queries[i]) != perfect.end()) res.push_back(queries[i]);
			else if (low.find(tolow(queries[i])) != low.end()) res.push_back(low[tolow(queries[i])]);
			else if (pass_vowel.find(passvowel(tolow(queries[i]))) != pass_vowel.end()) res.push_back(pass_vowel[passvowel(tolow(queries[i]))]);
			else res.push_back("");
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<string> wordlist = { "KiTe","kite","hare","Hare" };
	vector<string> queries = { "kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto" };
	auto res = s->spellchecker(wordlist, queries);
	return 0;
}
