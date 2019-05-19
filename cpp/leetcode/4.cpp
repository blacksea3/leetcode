#include "public.h"

//20ms 99.62%

//����ȷ��:nums1�ĳ���С�ڵ���nums2
//���ǵĻ��򽻻�

//���轻����nums1����m,nums����n(m<=n)

//��nums1��Χ���г�ʼ��:left = 0;, right = m;
//Ȼ��ѡȡnums1�еķָ��i=(m+n)/2,���Ӧ��nums2�еķָ��j=(m + n + 1) / 2 - i

//ע�⵽�˿�: nums1���ָ�� nums1[0],nums1[1]....nums1[i-1]      nums1[i]..nums1[m-1]
//nums2���ָ�� nums2[0],nums2[1]....nums2[j-1]      nums2[j]..nums1[n-1]

//ע�⵽���m��n��Ϊż��,��ônums1��nums2�����γ���֮��=�Ұ�γ���֮��
//���m��n֮��Ϊ����,��ônums1��nums2�����γ���֮��(i+j) = �Ұ�γ���֮��(m+n-i-j) + 1

//���nums1[i-1] > nums2[j], ��Ӧ����i��С���ƶ�, �������ƶ�right��i-1
//���nums2[j-1] > nums2[i], ��Ӧ����i�������ƶ�, �������ƶ�left��i+1
//�������߽�i=0����i=m-1�����ƶ���, (m<=n)��Ϊ��ȷ��nums2����nums1�ﵽ�߽�֮ǰ�ﵽ�߽�

//������,���m��n֮��Ϊ����,��δ�ﵽ�߽�����,��ôȡnums1[i-1]��nums2[j-1]����
//���i=0,��ȡnums2[j-1],���j=0(i���),��ȡnums1[i-1]

//���m��n֮��Ϊż��,��δ�ﵽ�߽�����,��ôȡnums1[i-1]��nums2[j-1]������nums1[i]��nums2[j]С�ߵ�ƽ��ֵ
//���i=m,�����ȡnums2[j];j=n�����ȡnums1[i], �����������ȡ������m��n֮��Ϊ������ȡ��������ƽ��


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
