#include "public.h"

//60ms, 80.65%
//�������Լ۱���������
//�����Լ۱�������workers, �Ե�ǰĳ������, ȷ���������˵��Լ۱ȶ�û����, ��ô����������˵�����µ���͹��ʾ��������Լ۱ȳ�����͵�������, ����set����������
//�������������, ��ǰ�Լ۱���ߵĹ�������Ҳ��, ��ÿһ�β��뵱ǰ����������set, Ȼ��ȥ�����������, �˴μ���Ĺ����Ѿ�������, �ⲻӰ����, ��Ϊ��ȷ�Ĺ��ʱ�Ȼ���Լ۱ȵ͵Ĺ���ѭ���������.

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
