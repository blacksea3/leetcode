#include "public.h"

/*
//20ms, 98.51%
//ԭλ����
//���������0, 1, 2..
//����, ����ض������ڵ�ǰλ��, ���Ҳ�����nums.size(), ��ô��������������������λ���ϵ����ֽ���,
//Ȼ��Ե�ǰλ���ٴ��ж�

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++)
			while (!((nums[i] == n) || (nums[i] == i))) swap(nums[i], nums[nums[i]]);

		for (int i = 0; i < n; i++) if (nums[i] == n) return i;
		return n;
	}
};
*/

//24ms, 91.59%
//����ֱ�Ӷ�0-n���, Ȼ�����������ǰ����
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		return (nums.size())*(nums.size() + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
	}
};
