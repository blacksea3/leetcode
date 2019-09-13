#include "public.h"

//44ms, 23.98%
//先二分查找到左端点插入位置, 再二分查找右端点插入位置, 非就地合并, 故效率仍然是O(n), 比传统暴力O(n)一遍扫描还要慢
//待优化

class Solution {
	//区间左端点小于插入位置左端点
	static bool comp_left(const vector<int> &a, const vector<int> &b) {
		return a[0] < b[0];
	}
	//区间右端点小于插入位置右端点
	static bool comp_right(const vector<int> &a, const vector<int> &b) {
		return a[1] < b[1];
	}
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		//查找第一个不满足cmp函数的位置
		//即查找第一个区间左端点>=插入位置左端点
		int leftAbsLoc = lower_bound(intervals.begin(), intervals.end(), newInterval, comp_left) - intervals.begin();
		//即查找第一个区间右端点>=插入位置右端点
		int rightAbsLoc = lower_bound(intervals.begin(), intervals.end(), newInterval, comp_right) - intervals.begin();

		int left = max(leftAbsLoc - 1, 0);
		int right = min(rightAbsLoc + 1, (int)intervals.size());

		//leftlis: [0:left], midlis: [left:right], rightlis: [right:]
		vector<vector<int>> leftlis(intervals.begin(), intervals.begin() + left);
		vector<vector<int>> midlis(intervals.begin() + left, intervals.begin() + right);
		vector<vector<int>> rightlis(intervals.begin() + right, intervals.end());

		if (!midlis.empty())
		{
			if (newInterval[0] <= midlis[0][1] && newInterval[1] >= midlis[midlis.size() - 1][0])
			{
				midlis = vector<vector<int>>{ {min(midlis[0][0], newInterval[0]), max(midlis[midlis.size() - 1][1], newInterval[1])} };
			}
			else if (newInterval[0] > midlis[0][1] and newInterval[1] >= midlis[midlis.size() - 1][0])
			{
				vector<int> tempNewInt =vector<int>{newInterval[0], max(midlis[midlis.size() - 1][1], newInterval[1])};
				midlis.erase(midlis.begin() + 1, midlis.end());
				midlis.emplace_back(tempNewInt);
			}
			else if (newInterval[0] <= midlis[0][1] and newInterval[1] < midlis[midlis.size() - 1][0])
			{
				vector<int> tempNewInt = vector<int>{min(midlis[0][0], newInterval[0]), newInterval[1]};
				midlis.erase(midlis.begin(), midlis.end() - 1);
				midlis.insert(midlis.begin(), tempNewInt);
			}
			else
			{
				midlis.erase(midlis.begin() + 1, midlis.end() - 1);
				midlis.insert(midlis.begin() + 1, newInterval);
			}
		}
		else
		{
			midlis = vector<vector<int>>{ newInterval };
		}

		leftlis.insert(leftlis.end(), midlis.begin(), midlis.end());
		leftlis.insert(leftlis.end(), rightlis.begin(), rightlis.end());

		return leftlis;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> intervals = { {1,3},{6,9} };
	vector<int> newInterval = {2,5};
	auto res = s->insert(intervals, newInterval);
	return 0;
}
*/
