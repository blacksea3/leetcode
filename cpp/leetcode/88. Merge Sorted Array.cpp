#include "public.h"

//4ms, 98.35%
//模拟, 双下标
//从nums的最右侧开始找数字

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pre_loc = m + n - 1;
		int m_loc = m - 1;
		int n_loc = n - 1;

		while ((m_loc > -1) && (n_loc > -1))
		{
			if (nums1[m_loc] >= nums2[n_loc]) nums1[pre_loc--] = nums1[m_loc--];
			else nums1[pre_loc--] = nums2[n_loc--];
		}

		if (m_loc == -1)
			while (n_loc > -1) nums1[pre_loc--] = nums2[n_loc--];
	}
};
