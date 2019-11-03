#include "public.h"

//
//��������
//ת��һ������, ����num��ż������,1������,ż������...
//����ż�������õ�����

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		vector<int> even;

		int preE = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] % 2)
			{
				even.emplace_back(preE);
				preE = 0;
			}
			else preE++;
		}

		int res = 0;

		for (int left = 0; left < even.size() - k; ++left)
		{
			int right = left + k;
			res += (even[left] + 1)*(even[right] + 1);
		}
		return res;
	}
};
