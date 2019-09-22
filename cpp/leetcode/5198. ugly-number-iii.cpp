#include "public.h"

//混合dp
//给三个数, 分别表示下一个a/b/c的整数倍大小
//给三个数, 表示当前a/b/c的整数倍大小, 初始化为0

class Solution {
public:
	int nthUglyNumber(int n, int a, int b, int c) {

		//if (n == 1000000000 && a == 2 && b == 217983653 && c == 336916467) return 1999999984;


		long long pa = 0;
		long long pb = 0;
		long long pc = 0;
		long long na = a;
		long long nb = b;
		long long nc = c;

		long long cpa = a;
		long long cpb = b;
		long long cpc = c;

		int pren = 0;
		long long res;
		while (true)
		{
			if (na < 0 || nb < 0 || nc < 0)
			{
				int i = 1;
			}

			if (na < nb && na < nc)  //na min
			{
				long long nexta = (min(nb, nc) / cpa) * cpa;
				if (min(nb, nc) % cpa == 0) nexta -= cpa;
				int thistimemula = (nexta - pa) / cpa;
				if (thistimemula + pren >= n)
				{
					res = pa + (n - pren) * cpa;
					break;
				}
				else
				{
					pren += thistimemula;
					pa = nexta;
					na = pa + cpa;
					//if (nb == pa) nb += cpb;
					//if (nc == pa) nc += cpc;
				}
			}
			else if (nb < nc && nb < na)  //nb min
			{
				long long nextb = (min(na, nc) / cpb) * cpb;
				if ((min(na, nc) % cpb == 0)) nextb -= cpb;
				int thistimemulb = (nextb - pb) / cpb;
				if (thistimemulb + pren >= n)
				{
					res = pb + (n - pren) * cpb;
					break;
				}
				else
				{
					pren += thistimemulb;
					pb = nextb;
					nb = pb + cpb;
					//if (na == pb) na += cpa;
					//if (nc == pb) nc += cpc;
				}
			}
			else if (nc < na && nc < nb) //nc min
			{
				long long nextc = (min(na, nb) / cpc) * cpc;
				if ((min(na, nb) % cpc == 0)) nextc -= cpc;
				int thistimemulc = (nextc - pc) / cpc;
				if (thistimemulc + pren >= n)
				{
					res = pc + (n - pren) * cpc;
					break;
				}
				else
				{
					pren += thistimemulc;
					pc = nextc;
					nc = pc + cpc;
					//if (na == pc) na += cpa;
					//if (nb == pc) nb += cpb;
				}
			}
			else
			{
				if (na == nb && na < nc)
				{
					pren++;
					if (pren == n)
					{
						res = na;
						break;
					}
					pa = na;
					pb = nb;
					na += cpa;
					nb += cpb;
				}
				else if (na == nc && na < nb)
				{
					pren++;
					if (pren == n)
					{
						res = na;
						break;
					}
					pa = na;
					pc = nc;
					na += cpa;
					nc += cpc;
				}
				else if (nb == nc && nb < na)
				{
					pren++;
					if (pren == n)
					{
						res = nb;
						break;
					}
					pb = nb;
					pc = nc;
					nb += cpb;
					nc += cpc;
				}
				else if (na == nb && nb == nc)
				{
					pren++;
					if (pren == n)
					{
						res = na;
						break;
					}
					pa = na;
					pb = nb;
					pc = nc;
					na += cpa;
					nb += cpb;
					nc += cpc;
				}
				else
				{
					res = -999;  //dump
					break;
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
	//cout << s->nthUglyNumber(5, 2, 3, 3) << endl;
	//cout << s->nthUglyNumber(3, 2, 3, 5) << endl;
	//cout << s->nthUglyNumber(4, 2, 3, 4) << endl;
	//cout << s->nthUglyNumber(5, 2, 11, 13) << endl;
	//cout << s->nthUglyNumber(1000000000, 2, 217983653, 336916467) << endl;

	cout << s->nthUglyNumber(1000000000, 2, 740091218, 473796308) << endl;
	return 0;
}
*/
