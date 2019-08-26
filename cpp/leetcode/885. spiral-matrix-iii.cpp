#include "public.h"

//88ms, 81.08%
//暴力: 模拟
//右1下1左2上2右3下3....

class Solution {
public:
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		int total = R * C;
		vector<vector<int>> res;
		res.push_back({ r0, c0 });
		int predir = 0;  //0:右 1下 2左 3上
		int prer = r0;
		int prec = c0;
		int prelen = 1;

		int pre = 1;

		while (pre < total)
		{
			switch (predir)
			{
			case 0:
			{
				int prel = 0;
				while (prel < prelen)
				{
					c0++;
					prel++;
					if ((0 <= r0 && r0 < R) && (0 <= c0 && c0 < C))
					{
						res.push_back({ r0, c0 });
						pre++;
					}
					if (pre == total) goto end;
				}
				predir = 1;
				break;
			}
			case 1:
			{
				int prel = 0;
				while (prel < prelen)
				{
					r0++;
					prel++;
					if ((0 <= r0 && r0 < R) && (0 <= c0 && c0 < C))
					{
						res.push_back({ r0, c0 });
						pre++;
					}
					if (pre == total) goto end;
				}
				predir = 2;
				prelen++;
				break;
			}
			case 2:
			{
				int prel = 0;
				while (prel < prelen)
				{
					c0--;
					prel++;
					if ((0 <= r0 && r0 < R) && (0 <= c0 && c0 < C))
					{
						res.push_back({ r0, c0 });
						pre++;
					}
					if (pre == total) goto end;
				}
				predir = 3;
				break;
			}
			case 3:
			{
				int prel = 0;
				while (prel < prelen)
				{
					r0--;
					prel++;
					if ((0 <= r0 && r0 < R) && (0 <= c0 && c0 < C))
					{
						res.push_back({ r0, c0 });
						pre++;
					}
					if (pre == total) goto end;
				}
				predir = 0;
				prelen++;
				break;
			}
			default:
			{
				break;
			}
			}
		}
	end:
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->spiralMatrixIII(1, 4, 0, 0);
	return 0;
}
*/
