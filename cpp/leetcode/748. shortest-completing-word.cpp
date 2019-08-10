#include "public.h"

//24ms, 80.48%
//将牌照转成vector统计词频, 然后每个word也是

class Solution {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		vector<int> l(26, 0);

		for (auto& iil : licensePlate)
		{
			if (iil <= 'z' && iil >= 'a') l[iil - 'a']++;
			else if (iil <= 'Z' && iil >= 'A') l[iil - 'A']++;
		}

		string res;
		int minlen = 999;

		for (auto& word : words)
		{
			vector<int> temp(26, 0);
			for (auto& iiw : word)
			{
				temp[iiw - 'a']++;
			}

			bool isok = true;
			for (int i = 0; i < 26; ++i)
			{
				if (temp[i] < l[i])
				{
					isok = false;
					break;
				}
			}
			if (isok)
			{
				if (minlen > word.size())
				{
					res = word;
					minlen = word.size();
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> words = { "step","steps","stripe","stepple" };
	auto res = s->shortestCompletingWord("1s3 PSt", words);
	return 0;
}
*/
