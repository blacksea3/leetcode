#include "public.h"

//448ms, 27.06%
//暴力, 统计A的字母个数, B的字母个数
//然后把B的各种字母出现个数求个max, 得出一个公共各种字母个数供A比较即可

class Solution {
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<int> charnums(256, 0);
		for (int i = 0; i < B.size(); ++i)
		{
			vector<int> tempcharnums(256, 0);
			for (auto& iis : B[i])
			{
				tempcharnums[iis]++;
			}
			for (char c = 'a'; c <= 'z'; ++c)
			{
				charnums[c] = max(charnums[c], tempcharnums[c]);
			}
		}

		vector<string> res;
		for (int i = 0; i < A.size(); ++i)
		{
			vector<int> Anums(256, 0);
			for (auto& iis : A[i])
			{
				Anums[iis]++;
			}

			bool ispass = true;
			for (char c = 'a'; c <= 'z'; ++c)
			{
				if (Anums[c] < charnums[c])
				{
					ispass = false;
					break;
				}
			}
			if (ispass) res.push_back(A[i]);
		}
		return res;
	}
};
