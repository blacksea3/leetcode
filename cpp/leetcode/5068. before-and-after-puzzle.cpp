#include "public.h"

//
//暴力O(n^2)

class Solution {
private:
	vector<string> getPreAndLat(string input)
	{
		vector<string> res(2);
		if (input.find(' ') == input.npos) return { input, input };

		//正序倒序各一次
		int preIndex = 0;
		while (input[preIndex] != ' ') preIndex++;
		res[0] = input.substr(0, preIndex);

		preIndex = input.size() - 1;
		while (input[preIndex] != ' ') preIndex--;
		res[1] = input.substr(preIndex + 1);
		return res;
	}

public:
	vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
		int pSize = phrases.size();

		vector<string> pre(pSize);
		vector<string> lat(pSize);

		for (int index = 0; index < pSize; ++index)
		{
			vector<string> tempres = getPreAndLat(phrases[index]);
			pre[index] = tempres[0];
			lat[index] = tempres[1];
		}

		//生成
		set<string> setRes;

		for (int preIndex = 0; preIndex < pSize; ++preIndex)
		{
			string target = pre[preIndex];
			for (int latIndex = 0; latIndex < pSize; ++latIndex)
			{
				if (lat[latIndex] == target && preIndex != latIndex)
				{
					setRes.insert(phrases[latIndex] + phrases[preIndex].substr(target.size()));
				}
			}
		}

		vector<string> vecRes(setRes.begin(), setRes.end());
		return vecRes;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> phrases = { "a", "b", "a" };
	auto res = s->beforeAndAfterPuzzles(phrases);
	return 0;
}
*/
