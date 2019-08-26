#include "public.h"

/*
//44ms, 98.65%
//��ע��
//����˼·/�㷨

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//ά��һ�����ȶ���,�������߶�
		//��buildings��Ϣ�������·�ʽ����:����[2,9,10]����:(2,-10),(9,10)��ʾ��2����10���9�½�10
		//������Щ��,���յ�һ:pos���򡢵ڶ�height��������(height�����и�,�����������½��ķ���ͬ����ͬ),Ȼ�����Щ�㰴���������ȼ�����,����ܹ��������߶�(��������(����)һ�����߶Ȼ���ɾ��(�½�)һ�����߶�),��ô��¼��ǰ���߶��뵱ǰλ��,���򲻲���

		vector<vector<int>> res = {};
		if (buildings.size() == 0) return res;

		//ʹ��multiset:�ɺ��ظ�Ԫ�صļ���(��֤����)

		multiset<pair<int, int>, less<pair<int, int>>> points;   //��¼λ��,�߶�(�������ŵ�),��������,С�±��ֵС�ڴ��±��
		multiset<int, greater<int>> maxheights = { 0 }; //ֵ���Ԫ����С���±괦,��һ��0ȷ����multiset��Ϊ��

		for (auto building : buildings)
		{
			points.insert(pair<int, int> {building[0], -1 * building[2]});
			points.insert(pair<int, int> {building[1], building[2]});
		}

		int hisheight = 0;
		for (auto point : points)
		{
			if (point.second < 0) //��¥��ʼ����,�߶�����
				maxheights.insert(-1 * point.second);
			else                 //��¥��ʼ����,�߶��½�,���õ���erase��ָ��λ��,��Ϊ�㷨��������һ����Ԫ�ر��Ƴ�
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
//��ɢ��+�߶���

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
				//���´��ݸ߶�
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
