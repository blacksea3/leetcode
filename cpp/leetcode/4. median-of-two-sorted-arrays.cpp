#include "public.h"

//20ms 99.62%

//首先确保:nums1的长度小于等于nums2
//不是的话则交换

//假设交换后nums1长度m,nums长度n(m<=n)

//对nums1范围进行初始化:left = 0;, right = m;
//然后选取nums1中的分割点i=(m+n)/2,与对应的nums2中的分割点j=(m + n + 1) / 2 - i

//注意到此刻: nums1被分割成 nums1[0],nums1[1]....nums1[i-1]      nums1[i]..nums1[m-1]
//nums2被分割成 nums2[0],nums2[1]....nums2[j-1]      nums2[j]..nums1[n-1]

//注意到如果m与n和为偶数,那么nums1与nums2的左半段长度之和=右半段长度之和
//如果m与n之和为奇数,那么nums1与nums2的左半段长度之和(i+j) = 右半段长度之和(m+n-i-j) + 1

//如果nums1[i-1] > nums2[j], 则应当将i往小了移动, 方法是移动right至i-1
//如果nums2[j-1] > nums2[i], 则应当将i往大了移动, 方法是移动left至i+1
//如果到达边界i=0或者i=m-1则不能移动了, (m<=n)是为了确保nums2不在nums1达到边界之前达到边界

//接下来,如果m与n之和为奇数,且未达到边界条件,那么取nums1[i-1]与nums2[j-1]大者
//如果i=0,则取nums2[j-1],如果j=0(i最大),则取nums1[i-1]

//如果m与n之和为偶数,且未达到边界条件,那么取nums1[i-1]与nums2[j-1]大者与nums1[i]与nums2[j]小者的平均值
//如果i=m,则额外取nums2[j];j=n则额外取nums1[i], 并且拿这额外取得数和m与n之和为奇数中取的数进行平均


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m, n;
		m = nums1.size();
		n = nums2.size();
		if (m > n)
		{
			int temp = m;
			m = n;
			n = temp;
			vector<int> tempv;
			tempv.assign(nums2.begin(), nums2.end());
			nums2.assign(nums1.begin(), nums1.end());
			nums1.assign(tempv.begin(), tempv.end());
		}

		int imin = 0;
		int imax = m;
		int max_left;
		int min_right;
		while (imin <= imax)
		{
			int i = (imin + imax) / 2;
			int j = (m + n + 1) / 2 - i;
			if ((i > 0) && (j < n) && (nums1[i - 1] > nums2[j]))
				imax = i - 1;
			else if ((j > 0) && (i < m) && (nums2[j - 1] > nums1[i]))
				imin = i + 1;
			else
			{
				if (i == 0) max_left = nums2[j - 1];
				else if (j == 0) max_left = nums1[i - 1];
				else max_left = (nums1[i - 1] >= nums2[j - 1]) ? nums1[i - 1] : nums2[j - 1];

				if (((m + n) % 2) == 1) return float(max_left);

				if (i == m) min_right = nums2[j];
				else if (j == n) min_right = nums1[i];
				else min_right = (nums1[i] <= nums2[j]) ? nums1[i] : nums2[j];
				return (max_left + min_right) / 2.0;
			}
		}
		return -999;
	}

};

int main()
{
	Solution* s = new Solution();
	vector<int> nums1 = {1,2,3,4};
	vector<int> nums2 = {5};
	cout << s->findMedianSortedArrays(nums1, nums2);
	delete s;
}
