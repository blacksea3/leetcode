#include "public.h"

//60ms, 58.99%
//��ɨһ��, ��ǰn��Ͷ�k��ȡģ, ��ģ����
//��ô��С����Ϊ1, �ܺ�Ϊk�ı�����������������������sum(ÿ��ģ������-1), �����ģ��0��, ��Ҫ�ټ�1(�������)
//Ȼ����ɨһ��, �����������k�ı���
//�����������Ƿ���Ⱦ������

//ע��: ����k��ʲô���ֶ�Ҫ�ж��Ƿ���������0
//Ȼ�����k�Ǹ��ľ�ת������, k��0�������ģ�������

class Solution {
private:
	bool HasConsecutiveZero(const vector<int>& nums)
	{
		for (int index = 0; index < nums.size() - 1; ++index)
		{
			if (nums[index] == nums[index + 1] && nums[index] == 0)
				return true;
		}
		return false;
	}


public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		//�ж��Ƿ���������0
		if (k == 0)
		{
			return HasConsecutiveZero(nums);
		}
		else
		{
			if (HasConsecutiveZero(nums)) return true;

			k = abs(k);
			if (k == 1) return (nums.size() > 1);

			int preSum = 0;
			unordered_map<int, int> modGroup;

			for (auto& num : nums)
			{
				preSum += num;
				modGroup[preSum%k]++;
			}

			int resAll = 0;
			for (auto& m : modGroup)
			{
				if (m.second > 1)
				{
					resAll += m.second - 1;
				}
			}
			if (modGroup.find(0) != modGroup.end()) resAll++;

			for (auto& num : nums)
			{
				if (num%k == 0)
				{
					resAll--;
				}
			}
			return resAll > 0;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums1 = { 0,1,0 };
	cout << s->checkSubarraySum(nums1, -1);
	vector<int> nums2 = { 1,1 };
	cout << s->checkSubarraySum(nums2, 2);
	return 0;
}
*/
