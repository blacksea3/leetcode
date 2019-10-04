#include "public.h"

//116ms, 100%
//用map记录区间开始/区间结束, 键升序排序
//用set记录区间开始, 便于二分查找定位

//每次先查找出最大的小于等于val的开始值, 然后分类讨论:
//  如果val在[开始值, 结束值]内, 则不变
//  如果val==结束值+1, 则扩张
//  如果val > 结束值+1, 则新建
//  此外, 判断val与下一区间开始值关系
//  如果val==下一开始值-1, 则合并

//根据不=不同情况, 调整map与set

class SummaryRanges {
private:
	map<int, int> intervals;
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		map<int, int>::iterator iter = intervals.upper_bound(val);
		if (iter == intervals.begin())  //没有小于等于val的开始值...
		{
			//判断后一个区间是否可以合并
			if ((iter != intervals.end()) && (val == iter->first - 1)) //合并
			{
				int end = intervals[val+1];
				intervals.erase(val+1);
				intervals.insert(pair<int, int>{val, end});
			}
			else
			{
				intervals.insert(pair<int, int>{val, val});
			}
		}
		else
		{
			map<int, int>::iterator afteriter = iter;
			iter--;
			//判断是否已经融入区间
			if ((iter->second >= val) && (iter->first <= val)); //已经融入, 无需操作
			else if (iter->second == val - 1) //前一个区间可以合并
			{
				//判断后一个区间是否可以合并
				if ((afteriter != intervals.end()) && (val == afteriter->first - 1)) //后一个也合并
				{
					int end = intervals[val + 1];
					intervals.erase(val + 1);
					intervals[iter->first] = end;
				}
				else //仅合并前一个
				{
					intervals[iter->first]++;
				}
			}
			else
			{
				//判断后一个区间是否可以合并
				if ((afteriter != intervals.end()) && (val == afteriter->first - 1)) //后一个可合并
				{
					int end = intervals[val + 1];
					intervals.erase(val + 1);
					intervals.insert(pair<int, int>{val, end});
				}
				else
				{
					intervals.insert(pair<int, int>{val, val});
				}
			}
		}
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> res;
		for (const auto& m : intervals)
		{
			res.push_back({m.first, m.second});
		}
		return res;
	}
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

/*
int main()
{
	SummaryRanges* obj = new SummaryRanges();
	obj->addNum(65);
	vector<vector<int>> param_2 = obj->getIntervals();
	obj->addNum(64);
	param_2 = obj->getIntervals();
}
*/
