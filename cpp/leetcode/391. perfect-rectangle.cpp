#include "public.h"

//132ms, 98.11%
//完美矩形：除了四个周围的点以外，其他点只出现两次/四次。
// 且所有矩阵面积和等于最后矩阵面积和

class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {

		unordered_map<int, unordered_set<int>> us1;
		unordered_map<int, unordered_set<int>> us2;

		int totalsize = 0;

		for (auto& rec : rectangles)
		{
			int x1 = rec[0];
			int y1 = rec[1];
			int x2 = rec[2];
			int y2 = rec[3];
			totalsize += abs(x2 - x1)*abs(y2 - y1);

			if (us1[x1].find(y1) != us1[x1].end())
			{
				us1[x1].erase(y1);
			}
			else us1[x1].insert(y1);

			if (us1[x1].find(y2) != us1[x1].end())
			{
				us1[x1].erase(y2);
			}
			else us1[x1].insert(y2);

			if (us1[x2].find(y2) != us1[x2].end())
			{
				us1[x2].erase(y2);
			}
			else us1[x2].insert(y2);

			if (us1[x2].find(y1) != us1[x2].end())
			{
				us1[x2].erase(y1);
			}
			else us1[x2].insert(y1);
		}

		unordered_set<int> remainy1s;
		unordered_set<int> remainy2s;
		int remainx1;
		int remainx2;
		for (auto& ius1 : us1)
		{
			if (!ius1.second.empty())
			{
				if (remainy1s.empty())
				{
					remainy1s = ius1.second;
					remainx1 = ius1.first;
				}
				else if (remainy2s.empty())
				{
					remainy2s = ius1.second;
					remainx2 = ius1.first;
				}
				else return false;
			}
		}

		if ((remainy1s.size() == 2) && (remainy2s.size() == 2))
		{
			unordered_set<int>::iterator iter_rey1 = remainy1s.begin();
			int y1 = *iter_rey1;
			iter_rey1++;
			int y2 = *iter_rey1;
			unordered_set<int>::iterator iter_rey2 = remainy2s.begin();
			int y3 = *iter_rey2;
			iter_rey2++;
			int y4 = *iter_rey2;
			if ((y1 == y3) && (y2 == y4))
			{
				return totalsize == abs(remainx2 - remainx1) * abs(y2 - y1);
			}
			else if ((y1 == y4) && (y2 == y3))
			{
				return totalsize == abs(remainx2 - remainx1) * abs(y2 - y1);
			}
			else return false;
		}
		else return false;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> rectangles = { {1, 1, 3, 3},{3, 1, 4, 2},{3, 2, 4, 4},{1, 3, 2, 4},{2, 3, 3, 4} };
	rectangles = { {0, 0, 4, 1}, { 7,0,8,2 }, { 6,2,8,3 }, { 5,1,6,3 }, { 4,0,5,1 }, { 6,0,7,2 }, { 4,2,5,3 }, { 2,1,4,3 }, { 0,1,2,2 }, { 0,2,2,3 }, { 4,1,5,2 }, { 5,0,6,1 } };
	auto res = s->isRectangleCover(rectangles);
	return 0;
}
*/
