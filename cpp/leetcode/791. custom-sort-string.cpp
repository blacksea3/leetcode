#include "public.h"

//8ms, 56.00%
//��Tת��vector, ����S��ת, �±��������, SԤ�ȶ����vector

class Solution {
public:
	string customSortString(string S, string T) {
		vector<int> convert(26, 999);
		vector<char> rev_convert(26);

		for (int i = 0; i < S.size(); ++i)
		{
			convert[S[i] - 'a'] = i;
			rev_convert[i] = S[i];
		}

		int notfound_locstart = S.size();
		for (int i = 0; i < 26; ++i)
		{
			if (convert[i] == 999)
			{
				convert[i] = notfound_locstart;
				rev_convert[notfound_locstart] = i + 'a';
				notfound_locstart++;
			}
		}

		//ת��T
		vector<int> sor(T.size());
		for (int i = 0; i < T.size(); ++i)
		{
			sor[i] = convert[T[i] - 'a'];
		}

		sort(sor.begin(), sor.end());

		//�õ����
		string res = "";
		for (auto& iis : sor) res.push_back(rev_convert[iis]);

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();

	return 0;
}
*/
