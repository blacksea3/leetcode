#include "public.h"

//320ms, 27.88%
//将权重转为坐标
//例如: 在1,2,3中选择, 则等价于在1-6中随机数, 1->1, 2,3->2, 4,5,6->3
//那么记录1,3,6, 查找第一个大于0-5数字的位置

class Solution {
private:
	vector<int> locations;

public:
	Solution(vector<int>& w) {
		int preSum = 0;
		for (int index = 0; index < w.size(); ++index)
		{
			preSum += w[index];
			locations.push_back(preSum);
		}
	}

	int pickIndex() {
		int totalSum = locations[locations.size() - 1];
		int ranVal = rand() % totalSum;

		int absVal = upper_bound(locations.begin(), locations.end(), ranVal) - locations.begin();
		return absVal;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
