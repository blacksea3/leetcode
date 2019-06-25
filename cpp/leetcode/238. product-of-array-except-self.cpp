#include "public.h"

//60ms, 86.53%

//�������µ�����
//1,2,3,4
//���Ӧ����
//  1 1 1
//2   2 2
//3 3   3
//4 4 4 
//��ôʵ���Ͽ��Դ��������ɨ���ұ߳�һ��
//�ٴ��ұ�ɨ����߳�һ��,�����ٳ�����
//���ǵ�������鲻����Ϊ����ռ�,��ô:��һ��ֱ�ӱ��������������
//�ڶ��ֵ�����ȥ
//ֻ��Ҫһ��int temp����ռ�,����ҪһЩ�ռ�洢loc����

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		//��Ŀ˵��nums.size()>1
		vector<int> res(nums.size(), 1);

		int temp = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
		    res[i] = temp;
			temp *= nums[i];
		}

		temp = 1;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
		    res[i] *= temp;
			temp *= nums[i];
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2,3,4 };
	vector<int> res = s->productExceptSelf(nums);
	return 0;
}
*/