#include "public.h"

//��ϣ��28ms, 76.22%
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//���Ǵ���
		//O(n)
		int halfsize = nums.size() / 2;
		unordered_map<int, int> m;
		for (auto& num : nums)
		{
			m[num]++;
			if (m[num] > halfsize) return num;
		}
		//dump
		return -999;
	}
};

//Boyer-Moore �㷨 24ms, 92.45%
/*
����ά��һ�����������������һ������Ŀǰ�ĺ�ѡ�������ͽ���������һ�������һ��ֻҪ���������� 0 �����Ǿͽ� nums ��֮ǰ���ʵ�����ȫ�� ���� ��������һ�����ֵ�����ѡ��������

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
			if (vote == 0)
			{
				res = n;
				vote++;
			}
			else
			{
				if (res == n) vote++;
				else vote--;
			}
		}
		return res;
	}
};


