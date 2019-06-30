#include "public.h"

//76ms, 76.53%
//DP problem
//记录k个dp值, 表示下一个

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int k = primes.size();
		vector<int> res(n, 0);
		//int *res = new int[n];
		res[0] = 1;
		vector<int> pos(k, 0);
		//int **pos = new int *[k];
		for (int i = 0; i < k; i++)  //初始化k个下标
			pos[i] = 0;
		int next = 1;  //下一个存放位置
		while (next < n)
		{
			int min1 = INT_MAX;
			for (int i = 0; i < k; i++)//找出下一个该存放的丑数
			{
				min1 = (min1 < (res[pos[i]] * primes[i])) ? min1 : (res[pos[i]] * primes[i]);
			}
			res[next] = min1;
			//找到指针的位置
			for (int i = 0; i < k; i++)
			{
				if (res[pos[i]] * primes[i] == res[next])
				{
					pos[i]++;
				}
			}
			next++;
		}
		return res[n - 1];
	}
};
