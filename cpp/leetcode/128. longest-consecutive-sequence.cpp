#include "public.h"

//����4ms����, 24ms, 74.22% :(....ʱ�両��̫����
//˼·:��numsȥ�ط���unordered_set
//��ÿ��nums���������,��unordered_set������������ı���С��/�����ı������(��չ�߽�)
//ͬʱ���ڲ鵽�����ֶ���unordered_set����ȥ��,
//Ȼ����´�

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> us(nums.begin(), nums.end());
		int res = 0;
		for (auto num : nums)
		{
			if (us.find(num) == us.end()) continue;
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