#include "public.h"

//8ms, 96.45%
//ͳ��nums1�ĸ�������, Ȼ���nums2���з���
//ע:�ظ����ֲ��ظ�ͳ��

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> um1(nums1.begin(), nums1.end());

		vector<int> res = {};
		unordered_set<int>::iterator iter;
		for (auto& num2 : nums2)
		{
			iter = um1.find(num2);
			if (iter != um1.end())
			{
				res.emplace_back(num2);
				um1.erase(iter);
			}
		}
		return res;
	}
};
