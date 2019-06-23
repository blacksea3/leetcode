#include "public.h"

//12ms, 93.71%
//��ע��

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		//ά��һ��vector
		//������� O(n^2)
		//���TIE
		/*
		if (k < 1) return false;
		if (t < 0) return false;

		vector<int> q;

		for (int i = 0; i < nums.size(); i++)
		{
			for (auto val : q)
			{
				if (abs((long)val - nums[i]) <= t) return true;
			}
			if (q.size() == k)
			{
				q.erase(q.begin());
			}
			q.push_back(nums[i]);
		}
		return false;*/

		//��һ�ֱ������,�Ȱ�ֵ����,ͬʱ��¼�����Ķ�Ӧ�±�
		//O(n^2)
		if (k < 1) return false;
		if (t < 0) return false;

		vector<pair<int, int>> vp(nums.size(), pair<int, int> {});
		for (int i = 0; i < nums.size(); ++i)
			vp[i] = pair<int, int>{ nums[i],i };

		sort(vp.begin(), vp.end());

		int j = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			while ((j < i) && ((vp[j].first + t) < vp[i].first))
				j++;
			for (int m = j; m < i; m++)
				if (abs(vp[m].second - vp[i].second) <= k)
					return true;
		}
		return false;
	}
};
