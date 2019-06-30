#include "public.h"

//76ms, 76.53%
//DP problem
//��¼k��dpֵ, ��ʾ��һ��

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int k = primes.size();
		vector<int> res(n, 0);
		//int *res = new int[n];
		res[0] = 1;
		vector<int> pos(k, 0);
		//int **pos = new int *[k];
		for (int i = 0; i < k; i++)  //��ʼ��k���±�
			pos[i] = 0;
		int next = 1;  //��һ�����λ��
		while (next < n)
		{
			int min1 = INT_MAX;
			for (int i = 0; i < k; i++)//�ҳ���һ���ô�ŵĳ���
			{
				min1 = (min1 < (res[pos[i]] * primes[i])) ? min1 : (res[pos[i]] * primes[i]);
			}
			res[next] = min1;
			//�ҵ�ָ���λ��
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
