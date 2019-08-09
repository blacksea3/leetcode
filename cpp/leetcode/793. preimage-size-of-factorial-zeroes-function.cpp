#include "public.h"

//4ms, 74.49%
//数5的因子数量
//原本有道题目是这样操作: 从5的很大次方开始, 例如从125开始, K/125=2, 那么加2(125和250都有第三个5), 然后/25, 加x(它们都有第二个5), ...依此类推 

//现在反过来: 注意到答案仅可能是5或者0
//如果K能表示成 K = a1 + a1/5 + a1/25 + a1/125... 那么答案则为5, 否则为0
//思路：
//反过来记录每一个复杂块的0个数: 1, (5+1), (5+1)*5+1...
//  1, 6, 31, 156, 781, 3906, 19531, 97656, 
//然后K逐次减掉相应数, 通过取模判断是否存在

class Solution {
public:
	int preimageSizeFZF(int K) {
		vector<long long> specials;

		long long start = 0;
		for (int i = 0; ; ++i)
		{
			start *= 5;
			start++;
			if (start > 1000000000) break;
			specials.push_back(start);
		}

		//从specials[maxloc]开始减
		int cpK = K;
		int maxloc = specials.size() - 1;
		while (cpK > 0 && maxloc >= 0)
		{
			while (cpK > specials[maxloc])
			{
				cpK -= specials[maxloc];
			}
			if (cpK%specials[maxloc] >= (specials[maxloc] - maxloc))
			{
				return 0;
			}
			else
			{
				maxloc--;
			}
		}

		return 5;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->preimageSizeFZF(5) << endl;
	cout << s->preimageSizeFZF(3) << endl;
	return 0;
}
*/
