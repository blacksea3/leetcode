#include "public.h"

//224ms, 24.73%, 待优化
//vector<int>保存下标0至当前的元素和

class NumArray {
private:
	vector<int> sums;
public:
	NumArray(vector<int>& nums) {
		sums.resize(nums.size());
		int presum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			presum += nums[i];
			sums[i] = presum;
		}
	}

	void update(int i, int val) {
		int preval;
		if (i == 0) preval = sums[0];
		else preval = sums[i] - sums[i - 1];
		int extra_add = val - preval;

		for (int loc = i; loc < sums.size(); ++loc)
			sums[loc] += extra_add;
	}

	int sumRange(int i, int j) {
		if (i == 0) return sums[j];
		else return sums[j] - sums[i - 1];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
