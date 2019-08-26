#include "public.h"

//8ms, 87.02%
//统计各个字母的最后一次出现位置, 然后扫描S, 通过当前字母的最后一次出现位置得出当前块最短的长度, 如果已经出现的字母的最后一次出现位置<=当前位置, 那么OK, res++;

class Solution {
public:
	vector<int> partitionLabels(string S) {
		//vector<int> first(26, -1);
		vector<int> end(26, 999);

		/*
		for (int i = 0; i < S.size(); ++i)
		{
			if (first[S[i]-'a'] == -1) first[S[i]-'a'] = i;
		}
		*/
		//倒序扫一次
		for (int i = S.size() - 1; i >= 0; --i)
		{
			if (end[S[i] - 'a'] == 999) end[S[i] - 'a'] = i;
		}

		vector<int> res;
		int lastright = -1;
		int prelast = -1;

		for (int i = 0; i < S.size(); ++i)
		{
			prelast = max(prelast, end[S[i] - 'a']);
			if (prelast == i)
			{
				res.push_back(i - lastright);
				lastright = i;
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->partitionLabels("ababcbacadefegdehijhklij");
	return 0;
}
*/
