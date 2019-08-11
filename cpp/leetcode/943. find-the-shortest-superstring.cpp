#include "public.h"

//68ms, 60.00%
//dp
//dp[mask][i] :mask�Ƕ���������, 1��λ��ʾ��Щ�ַ�����ѡ��, i�����һ��ѡ�е��ַ���
//�¼�����ַ���һ��������ĩβ
//����ͬmask, ��ͬi�����¼ӵ��ַ�����ѡ����̵�

class Solution {
public:
	string shortestSuperstring(vector<string>& A) {
		int as = A.size();

		//����overlap
		vector<vector<int>> overlap(as, vector<int>(as));

		for (int i = 0; i < as; ++i)
		{
			for (int j = 0; j < as; ++j)
			{
				if (i == j) continue;
				else
				{
					int m = min(A[i].size(), A[j].size());
					for (int k = m; k >= 0; --k)
					{
						if (A[i].substr(A[i].size() - k, k) == A[j].substr(0, k))
						{
							overlap[i][j] = k;
							break;
						}
					}
				}
			}
		}

		//����dp, �Ѿ���չ��ĳ��dp��·��parent
		vector<vector<int>> dp(1 << as, vector<int>(as));
		vector<vector<int>> parent(1 << as, vector<int>(as));

		for (int mask = 0; mask < (1 << as); ++mask)
		{
			for (int i = 0; i < as; ++i) parent[mask][i] = -1;

			//ö�����Ҳ��ַ���
			for (int bit = 0; bit < as; ++bit)
			{
				if (((mask >> bit) & 1) > 0)  //��ǰ���ַ�����������bit
				{
					//������ͼ����dp[mask][bit], bitҲ����A���±�
					int pmask = mask ^ (1 << bit);  //ȥ������ַ���
					if (pmask == 0) continue;  //ȥ���Ϳ���
					else
					{
						for (int i = 0; i < as; ++i)
						{
							if (((pmask >> i) & 1) > 0)  //ȥ��bit�������i
							{
								int val = dp[pmask][i] + overlap[i][bit];
								if (val > dp[mask][bit])
								{
									dp[mask][bit] = val;
									parent[mask][bit] = i;
								}
							}
						}
					}

				}
			}
		}

		//�ع��ַ���
		// # Answer will have length sum(len(A[i]) for i) - max(dp[-1])
		// Reconstruct answer, first as a sequence 'perm' representing
		// the indices of each word from left to right.
		vector<int> perm(as);
		vector<bool> seen(as);

		int t = 0;
		int mask = (1 << as) - 1;

		int p = 0;         // p: the last element of perm (last word written left to right)

		for (int i = 0; i < as; ++i)
			if (dp[(1 << as) - 1][i] > dp[(1 << as) - 1][p])
				p = i;

		while (p != -1)
		{
			perm[t++] = p;
			seen[p] = true;
			int p2 = parent[mask][p];
			mask ^= 1 << p;
			p = p2;
		}

		//��תperm
		for (int i = 0; i < t / 2; ++i)
		{
			int v = perm[i];
			perm[i] = perm[t - 1 - i];
			perm[t - 1 - i] = v;
		}

		//����perm
		for (int i = 0; i < as; ++i) if (!seen[i]) perm[t++] = i;

		//���������ַ���
		string res = "";
		res = A[perm[0]];
		for (int i = 1; i < as; ++i)
		{
			int ov = overlap[perm[i - 1]][perm[i]];
			res += A[perm[i]].substr(ov);
		}

		return res;
	}
};

int main()
{
	Solution*s = new Solution();
	vector<string> A = { "catg","ctaagt","gcta","ttca","atgcatc"};
	auto res = s->shortestSuperstring(A);
	return 0;
}
