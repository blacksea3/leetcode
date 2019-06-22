#include "public.h"

//二分查找, 12ms, 77.90%

class Solution {
private:
	//外部必须确保numbers不为空,长度>=1
	//返回:true: loc 或者 false, dump(0)

	pair<bool, int> iter_two_search_find_167(vector<int>& numbers, int target, int startloc, int endloc) {
		if (startloc > endloc)
			return pair<bool, int> {false, 0};
		else if (startloc == endloc)
			if (numbers[startloc] == target)
				return pair<bool, int> {true, startloc};
			else
				return pair<bool, int> {false, 0};
		else
		{
			int mid = (startloc + endloc) / 2;
			if (numbers[mid] < target)
				return iter_two_search_find_167(numbers, target, mid + 1, endloc);
			else if (numbers[mid] > target)
				return iter_two_search_find_167(numbers, target, startloc, mid - 1);
			else
				return pair<bool, int> {true, mid};
		}
	}

public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		//二分查找,你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素
		//下标从1开始
		//好像一定能找到答案??
		int nsize_m1 = numbers.size() - 1;

		for (int i = 0; i <= nsize_m1; i++)
		{
			if ((numbers[i] + numbers[nsize_m1]) < target)
				continue;
			else
			{
				pair<bool, int> res = iter_two_search_find_167(numbers, target - numbers[i], i + 1, numbers.size());
				if (res.first)
					return vector<int> {i + 1, res.second + 1};
				else
					continue;
			}
		}
		return vector<int> {};  //dump
	}
};
