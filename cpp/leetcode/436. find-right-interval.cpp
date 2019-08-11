#include "public.h"

//144ms, 81.40%
//ע��:��ʼ�㲻ͬ
//����ʼ������, Ȼ����ֲ���
//�ؼ�: ������ʼ��ֵ:������unordered_map, Ȼ���ֵ����vector, ��lower_bound����

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		unordered_map<int, int> um;
		vector<int> starts;

		for (int i = 0; i < intervals.size(); ++i)
		{
			um[intervals[i][0]] = i;
			starts.push_back(intervals[i][0]);
		}

		sort(starts.begin(), starts.end());

		vector<int> res(intervals.size());

		for (int i = 0; i < intervals.size(); ++i)
		{
			vector<int>::iterator iter = lower_bound(starts.begin(), starts.end(), intervals[i][1]);
			if (iter != starts.end()) res[i] = um[*iter];
			else res[i] = -1;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> intervals = { {3,4},{2,3},{1,2} };
	auto res = s->findRightInterval(intervals);
	return 0;
}
*/
