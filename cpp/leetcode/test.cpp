#include "public.h"

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

int main() {
	vector<int> nums = {};
	NumArray* obj = new NumArray(nums);
	return 0;
}
