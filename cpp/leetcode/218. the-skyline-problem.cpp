#include "public.h"

/*
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
*/

//
//96ms, 20.30%
//离散化+线段树

class Solution {
private:
	struct Node
	{
		int l = 0;
		int r = 0;
		int h = 0;
	};
	void build(vector<Node*>& nodes, int l, int r, int nindex)
	{
		nodes[nindex]->l = l;
		nodes[nindex]->r = r;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(nodes, l, mid, 2 * nindex + 1);
		build(nodes, mid + 1, r, 2 * nindex + 2);
	}

	void update(const vector<Node*>& nodes, int l, int r, int h, int nindex)
	{
		if (nodes[nindex]->h >= h) return;
		else
		{
			if (nodes[nindex]->l == l && nodes[nindex]->r == r)
			{
				nodes[nindex]->h = h;
				return;
			}
			else
			{
				//向下传递高度
				if (nodes[nindex]->h > 0)
				{
					nodes[nindex * 2 + 1]->h = max(nodes[nindex]->h, nodes[nindex * 2 + 1]->h);
					nodes[nindex * 2 + 2]->h = max(nodes[nindex]->h, nodes[nindex * 2 + 2]->h);
					nodes[nindex]->h = 0;
				}
				int mid = (nodes[nindex]->l + nodes[nindex]->r) / 2;
				if (r <= mid) update(nodes, l, r, h, nindex * 2 + 1);
				else if (l > mid) update(nodes, l, r, h, nindex * 2 + 2);
				else
				{
					update(nodes, l, mid, h, nindex * 2 + 1);
					update(nodes, mid + 1, r, h, nindex * 2 + 2);
				}
			}
		}
	}

	void query(unordered_map<int, int>& mp2, const vector<Node*>& nodes, vector<vector<int>>& res, int nindex)
	{
		if (nodes[nindex]->l == nodes[nindex]->r)
		{
			if (!res.empty() && nodes[nindex]->h == res[res.size() - 1][1])
				return;
			mp2[0];
			mp2[nodes[nindex]->l];
			vector<int> temp = {mp2[nodes[nindex]->l], nodes[nindex]->h};
			res.push_back(temp);
			return;
		}
		if (nodes[nindex]->h > 0)
		{
			nodes[nindex * 2 + 1]->h = max(nodes[nindex]->h, nodes[nindex * 2 + 1]->h);
			nodes[nindex * 2 + 2]->h = max(nodes[nindex]->h, nodes[nindex * 2 + 2]->h);
			nodes[nindex]->h = 0;
		}
		query(mp2, nodes, res, nindex * 2 + 1);
		query(mp2, nodes, res, nindex * 2 + 2);
	}

public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		unordered_map<int, int> mp;
		unordered_map<int, int> mp2;
		vector<int> indexes;
		if (buildings.size() == 0) return { {} };
		for (int i = 0; i < buildings.size(); ++i)
		{
			if (mp.find(buildings[i][0]) == mp.end())
			{
				mp[buildings[i][0]] = 1;
				indexes.push_back(buildings[i][0]);
			}
			if (mp.find(buildings[i][1]) == mp.end())
			{
				mp[buildings[i][1]] = 1;
				indexes.push_back(buildings[i][1]);
			}
		}
		sort(indexes.begin(), indexes.end());

		for (int i = 0; i < indexes.size(); ++i)
		{
			mp[indexes[i]] = i;
			mp2[i] = indexes[i];
		}

		int maxn = indexes.size();
		vector<Node*> nodes(maxn << 2);
		for (int i = 0; i < nodes.size(); ++i)
			nodes[i] = new Node();
		build(nodes, 0, maxn, 0);

		vector<vector<int>> res;
		for (int i = 0; i < buildings.size(); ++i)
			update(nodes, mp[buildings[i][0]], mp[buildings[i][1]] - 1, buildings[i][2], 0);

		query(mp2, nodes, res, 0);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> buildings = { {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8} };
	auto res = s->getSkyline(buildings);
	return 0;
}
