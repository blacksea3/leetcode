#include "public.h"

//36ms, 94.90%
//设置一个vector, 应当存入下标0至当前下标的和

class NumArray {
private:
	vector<int> vnums;
public:
	NumArray(vector<int>& nums) {
		vnums.reserve(nums.size() + 1);
		vnums[0] = 0;
		for (int i = 1; i <= nums.size(); ++i)
			vnums[i] = vnums[i - 1] + nums[i - 1];
	}

	int sumRange(int i, int j) {
		return vnums[j + 1] - vnums[i];
	}
};
