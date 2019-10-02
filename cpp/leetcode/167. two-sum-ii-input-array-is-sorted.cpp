#include "public.h"

//4ms, 97.08%
//双指针, 从两端开始, 选择某个指针向中间移动
//题目已告知一定有唯一解

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0;
		int right = numbers.size() - 1;
		while (true)
		{
			if ((numbers[left] + numbers[right]) > target) right--;
			else if ((numbers[left] + numbers[right]) < target) left++;
			else return { left + 1, right + 1 };
		}
		return { -1, -1 }; //dump
	}
};
