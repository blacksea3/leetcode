#include "public.h"

//12ms, 90.91%
//һ��ɨ���ȡ�����ַ��ĳ���λ��
//Ȼ����������: ����  xxxx A yyy A zzzz, ������A���Գ��� (1+���A��)*(1+�ҷ�A��)=25��, �ұ�ͬ��
//�����Ӹ����ַ��Ĳ�ͬλ���Լ���ͬ���ַ��õ����

class Solution {
public:
	int uniqueLetterString(string S) {
		vector<vector<int>> locs(256);
		int ssize = S.size();
		int MOD = 1000000007;
		for (int i = 0; i < ssize; ++i)
		{
			locs[S[i]].push_back(i);
		}

		//�������ַ�
		int res = 0;
		for (int i = 0; i < 256; ++i)
		{
			if (locs[i].empty()) continue;
			else if (locs[i].size() == 1)
			{
				res += (1 + locs[i][0])*(ssize - locs[i][0]);
				res %= MOD;
			}
			else
			{
				//��β��һ��
				res += (1 + locs[i][0])*(locs[i][1] - locs[i][0]);
				res %= MOD;
				res += (locs[i][locs[i].size() - 1] - locs[i][locs[i].size() - 2])*(ssize - locs[i][locs[i].size() - 1]);
				res %= MOD;
				for (int j = 1; j < locs[i].size() - 1; ++j)
				{
					res += (locs[i][j + 1] - locs[i][j])*(locs[i][j] - locs[i][j - 1]);
					res %= MOD;
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
	//cout << s->uniqueLetterString("ABC");
	cout << s->uniqueLetterString("ABA");
	return 0;
}
*/
