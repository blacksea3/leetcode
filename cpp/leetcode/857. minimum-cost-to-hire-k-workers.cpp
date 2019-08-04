#include "public.h"

//60ms, 80.65%
//按期望性价比升序排序
//现在性价比升序考虑workers, 对当前某个工人, 确保其他工人的性价比都没他高, 那么包含这个工人的情况下的最低工资就是他的性价比乘以最低的质量和, 故用set保存质量们
//考虑这样的情况, 当前性价比最高的工人质量也高, 在每一次插入当前工人质量进set, 然后去掉最高质量后, 此次计算的工资已经不对了, 这不影响结果, 以为正确的工资必然在性价比低的工人循环处计算过.

class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
		vector<pair<double, double>> v;
		for (int i = 0; i < quality.size(); ++i)
			v.push_back(pair<double, double>{(double)wage[i] / (double)quality[i], (double)quality[i]});

		sort(v.begin(), v.end());
		double qsum = 0.0;
		double res = INT_MAX;
		priority_queue<double> pq;
		for (auto& iv : v)
		{
			qsum += iv.second;
			pq.push(iv.second);
			if (pq.size() > K)
			{
				qsum -= pq.top();
				pq.pop();
			}
			if (pq.size() == K)
				res = min(res, qsum * iv.first);
		}
		return res;
	}
};
