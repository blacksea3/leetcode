#include "public.h"

//60ms, 86.53%

//考虑以下的情形
//1,2,3,4
//结果应当是
//  1 1 1
//2   2 2
//3 3   3
//4 4 4 
//那么实际上可以从数组左边扫到右边乘一轮
//再从右边扫到左边乘一轮,两者再乘起来
//考虑到输出数组不被视为额外空间,那么:第一轮直接保存在输出数组中
//第二轮叠加上去
//只需要一个int temp额外空间,还需要一些空间存储loc坐标

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		//题目说了nums.size()>1
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