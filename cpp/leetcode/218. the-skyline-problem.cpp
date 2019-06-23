#include "public.h"

//44ms, 98.65%
//见注释
//特殊思路/算法

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//维护一个优先队列,储存最大高度
		//把buildings信息按照以下方式排序:对于[2,9,10]记作:(2,-10),(9,10)表示从2上升10与从9下降10
		//对于这些点,按照第一:pos升序、第二height升序排序(height有正有负,根据上升与下降的方向不同而不同),然后把这些点按此升序优先级遍历,如果能够调整最大高度(包括增加(上升)一个最大高度或者删除(下降)一个最大高度),那么记录当前最大高度与当前位置,否则不操作

		vector<vector<int>> res = {};
		if (buildings.size() == 0) return res;

		//使用multiset:可含重复元素的集合(保证有序)

		multiset<pair<int, int>, less<pair<int, int>>> points;   //记录位置,高度(带正负号的),升序排序,小下标的值小于大下标的
		multiset<int, greater<int>> maxheights = { 0 }; //值大的元素在小的下标处,填一个0确保这multiset不为空

		for (auto building : buildings)
		{
			points.insert(pair<int, int> {building[0], -1 * building[2]});
			points.insert(pair<int, int> {building[1], building[2]});
		}

		int hisheight = 0;
		for (auto point : points)
		{
			if (point.second < 0) //大楼起始坐标,高度上升
				maxheights.insert(-1 * point.second);
			else                 //大楼起始坐标,高度下降,不用担心erase空指针位置,因为算法决定这里一定有元素被移除
				maxheights.erase(maxheights.find(point.second));
			multiset<int, greater<int>>::iterator it = maxheights.begin();
			if (hisheight != *it)
				res.push_back(vector<int> {point.first, *it});
			hisheight = *it;
		}

		return res;
	}
};
