#include "public.h"

//308ms, 89.78%
//ֱ������O(nlogn)
//ֱ����ƽ���ʹ���ŷ����þ���

class Solution {
private:
	static bool msort(const pair<int, int>& v1, const pair<int, int>& v2)
	{
		return v1.first*v1.first + v1.second*v1.second < v2.first*v2.first + v2.second*v2.second;
	}

public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		vector<pair<int, int>> distances;

		for (auto& p : points)
		{
			distances.push_back(pair<int, int>{p[0], p[1]});
		}
		sort(distances.begin(), distances.end(), msort);

		vector<vector<int>> res;

		for (int i = 0; i < K; ++i)
		{
			res.push_back({ distances[i].first, distances[i].second });
		}
		return res;
	}
};
