#include "public.h"

//12ms, 92.67%
//˼·:��numsȥ�ط���unordered_set
//��ÿ��nums���������,��unordered_set������������ı���С��/�����ı������(��չ�߽�)
//ͬʱ���ڲ鵽�����ֶ���unordered_set����ȥ��,
//Ȼ����´�

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> us(nums.begin(), nums.end());
		int res = 0;
		for (auto& num : nums)
		{
			if (!us.count(num)) continue;
			us.erase(num);
			int left = num - 1;
			while (us.find(left) != us.end()) us.erase(left--);
			int right = num + 1;
			while (us.find(right) != us.end()) us.erase(right++);
			res = max(res, right - left - 1);
		}
		return res;
	}
};
