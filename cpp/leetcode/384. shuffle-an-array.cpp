#include "public.h"

//400ms, 43.15%
//Fisher-Yates 洗牌算法
//复制一份数组, 然后对下标0 - n-1, 随机选取, 1/n的概率选到一个数, 和nums[0]交换位置;
//    然后对下标1 - n-1随机选取, 1/n-1的概率选到一个数, 当前这个数选到的总概率即为n-1/n * 1/n-1 = 1/n和第一个选中数相同,
//    和nums[1]交换位置 .... 一直操作下去
//时间复杂度O(n) 空间复杂度O(n)

class Solution {
private:
	vector<int> copy;
public:
	Solution(vector<int>& nums) {
		copy = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return copy;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> temp = copy;
		int tsize = temp.size();
		int abs = 0;

		for (int start = 0; start < temp.size(); ++start)
		{
			swap(temp[rand() % (tsize - start) + start], temp[start]);
		}

		return temp;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
