#include "public.h"

//Boyer-Moore �㷨 20ms, 91.37%
/*
����ά��һ�����������������һ������Ŀǰ�ĺ�ѡ�������ͽ���������һ�������һ��ֻҪ���������� 0 ��
���Ǿͽ� nums ��֮ǰ���ʵ�����ȫ�� ���� ��������һ�����ֵ�����ѡ��������

���ߣ�LeetCode
���ӣ�https://leetcode-cn.com/problems/two-sum/solution/qiu-zhong-shu-by-leetcode-2/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int res = 0;
		int vote = 0;

		for (auto& n : nums)
		{
			if (vote == 0) res = n;

			if (res == n) vote++;
			else vote--;
		}
		return res;
	}
};
