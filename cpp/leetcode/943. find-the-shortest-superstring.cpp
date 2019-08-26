#include "public.h"

//68ms, 60.00%
//dp
//dp[mask][i] :mask是二进制数字, 1的位表示哪些字符串被选中, i是最后一个选中的字符串
//新加入的字符串一定连接在末尾
//对相同mask, 不同i加入新加的字符串后选择最短的

class Solution {
public:
	string shortestSuperstring(vector<string>& A) {
		int as = A.size();

		//计算overlap
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

		//更新dp, 已经发展到某个dp的路径parent
		vector<vector<int>> dp(1 << as, vector<int>(as));
		vector<vector<int>> parent(1 << as, vector<int>(as));

		for (int mask = 0; mask < (1 << as); ++mask)
		{
			for (int i = 0; i < as; ++i) parent[mask][i] = -1;

			//枚举最右侧字符串
			for (int bit = 0; bit < as; ++bit)
			{
				if (((mask >> bit) & 1) > 0)  //当前的字符串组合有这个bit
				{
					//现在试图计算dp[mask][bit], bit也就是A的下标
					int pmask = mask ^ (1 << bit);  //去掉这个字符串
					if (pmask == 0) continue;  //去掉就空了
					else
					{
						for (int i = 0; i < as; ++i)
						{
							if (((pmask >> i) & 1) > 0)  //去掉bit后还有这个i
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

		//重构字符串
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

		//反转perm
		for (int i = 0; i < t / 2; ++i)
		{
			int v = perm[i];
			perm[i] = perm[t - 1 - i];
			perm[t - 1 - i] = v;
		}

		//补齐perm
		for (int i = 0; i < as; ++i) if (!seen[i]) perm[t++] = i;

		//构建最终字符串
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
