#include "public.h"

//12ms, 90.22%

//Simple algorithm

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//both of nums1 and nums2 are one time traverse

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