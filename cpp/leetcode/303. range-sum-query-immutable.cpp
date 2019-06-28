#include "public.h"

//36ms, 98.20%
//设置一个vector, 应当存入下标0至当前下标的和

class NumArray {
private:
	vector<int> vnums;
public:
	NumArray(vector<int>& nums) {
		vnums.reserve(nums.size());
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			sum += nums[i];
			vnums[i] = sum;
		}
	}

	int sumRange(int i, int j) {
		if (i == 0)
		{
			return vnums[j];
		}
		else
		{
			return vnums[j] - vnums[i - 1];
		}
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
