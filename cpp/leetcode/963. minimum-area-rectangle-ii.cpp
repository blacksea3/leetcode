#include "public.h"

//
//暴力, 任意选三点, 若斜率乘积为-1, 那么查看剩余点中是否有想要的点, 有则更新矩形面积

//如下判断斜率乘积: (y1-y0)/(x1-x0) * (y2-y0)/(x2-x0) = -1  =>  (y1-y0)*(x2-x0) + (y2-y0)*(x1-x0) = 0
//但是上式的两个deltax != 0, 若有一个deltax = 0, 那么另一个deltay 若=0则也可以

//从公共点衍生出去, 若公共点是(x0,y0) 那么矩形目标点 x=x2+x1-x0, y=y2+y1-y0

class Solution {
private:
	//若可以成矩阵, 返回>-1和第四个点, int可以是0, 1, 2表示公共点是第0, 1, 2个
	//否则返回-1和dump点
	pair<int, vector<int>> findpoint(vector<int> p1, vector<int> p2, vector<int> p3)
	{
		int x0 = p1[0], y0 = p1[1], x1 = p2[0], y1 = p2[1], x2 = p3[0], y2 = p3[1];
			
		if (((x0 == x1) && (x0 == x2)) || ((y0 == y1) && (y0 == y2)))
			return { -1, {-99999, -99999} };
		if ((x0 != x1) && (x0 != x2) && ((y1 - y0)*(y2 - y0) + (x2 - x0)*(x1 - x0) == 0))
		{
			return { 0, {x2 + x1 - x0, y2 + y1 - y0} };
		}
		else if (((x0 == x1) && (y0 == y2)) || ((x0 == x2) && (y0 == y1)))
		{
			return { 0, {x2 + x1 - x0, y2 + y1 - y0} };
		}
		if ((x1 != x0) && (x1 != x2) && ((y0 - y1)*(y2 - y1) + (x2 - x1)*(x0 - x1) == 0))
		{
			return { 1, {x2 + x0 - x1, y2 + y0 - y1} };
		}
		else if (((x1 == x0) && (y1 == y2)) || ((x1 == x2) && (y1 == y0)))
		{
			return { 1, {x2 + x0 - x1, y2 + y0 - y1} };
		}
		if ((x2 != x1) && (x2 != x0) && ((y1 - y2)*(y0 - y2) + (x0 - x2)*(x1 - x2) == 0))
		{
			return { 2, {x0 + x1 - x2, y0 + y1 - y2} };
		}
		else if (((x2 == x0) && (y2 == y1)) || ((x2 == x1) && (y2 == y0)))
		{
			return { 2, {x0 + x1 - x2, y0 + y1 - y2} };
		}
		else
			return { -1, {-99999, -99999} };
	}

	//获得大小
	//任意挑两两组合, 只要两种, 求的两线段长度的乘积, 取小的那个返回
	double getsize(vector<int> p1, vector<int> p2, vector<int> p3, int type)
	{
		if (type == 0) return sqrt(((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]))) * sqrt(((p1[0] - p3[0])*(p1[0] - p3[0]) + (p1[1] - p3[1])*(p1[1] - p3[1])));
		else if (type == 1) return sqrt(((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]))) * sqrt(((p2[0] - p3[0])*(p2[0] - p3[0]) + (p2[1] - p3[1])*(p2[1] - p3[1])));
		else return sqrt(((p3[0] - p2[0])*(p3[0] - p2[0]) + (p3[1] - p2[1])*(p3[1] - p2[1]))) * sqrt(((p1[0] - p3[0])*(p1[0] - p3[0]) + (p1[1] - p3[1])*(p1[1] - p3[1])));
	}

public:
	double minAreaFreeRect(vector<vector<int>>& points) {
		double dr = 999999999;

		for (int i = 0; i < points.size() - 3; ++i)
		{
			for (int j = i + 1; j < points.size() - 2; ++j)
			{
				for (int k = j + 1; k < points.size() - 1; ++k)
				{
					pair<int, vector<int>> res = findpoint(points[i], points[j], points[k]);
					if (res.first > -1)
					{
						for (int l = k + 1; l < points.size(); ++l)
						{
							if ((res.second[0] == points[l][0]) && (res.second[1] == points[l][1]))
								dr = min(dr, getsize(points[i], points[j], points[k], res.first));
						}
					}
				}
			}
		}
		return (dr == 999999999) ? 0.0 : dr;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<vector<int>> points = { {0,1},{2,1},{1,1},{1,0},{2,0} };
	//cout << s->minAreaFreeRect(points);

	//vector<vector<int>> points = { {3, 1}, { 1,1 }, { 0,1 }, { 2,1 }, { 3,3 }, { 3,2 }, { 0,2 }, { 2,3 } };
	//cout << s->minAreaFreeRect(points);
	//vector<vector<int>> points = { {7, 3}, { 8,12 }, { 13,5 }, { 6,2 }, { 8,0 }, { 12,8 }, { 14,2 }, { 2,6 } };
	vector<vector<int>> points = { {7, 3}, { 13,5 },{ 8,0 }, { 14,2 }, { 2,6 } };
	cout << s->minAreaFreeRect(points);
	
	return 0;
}
*/
