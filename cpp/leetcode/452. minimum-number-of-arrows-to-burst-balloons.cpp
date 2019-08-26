#include "public.h"

//152ms, 94.70%
//贪婪
//按气球结束坐标排序, 然后每次都射当前气球的结束坐标, 判断其他气球的起始坐标, 这样一定能同时射下最多的别的气球

class Solution {
private:
	static bool msort(const vector<int>& v1, const vector<int>& v2)
	{
		if (v1[1] > v2[1]) return false;
		else if (v1[1] < v2[1]) return true;
		else return v1[0] <= v2[0];
	}

public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.size() == 0) return 0;

		sort(points.begin(), points.end(), msort);
		int res = 0;
		int prex = points[0][1];
		int loc = 1;
		if (loc == points.size()) res++;
		
		while (loc < points.size())
		{
			while (loc < points.size() && points[loc][0] <= prex) loc++;
			res++;
			if (loc != points.size())
			{
				prex = points[loc][1];
				loc++;
				if (loc == points.size()) res++;
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> points1 = { {9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7} };
	cout << s->findMinArrowShots(points1) << endl;
	vector<vector<int>> points2 = { {1,2},{3,4}};
	cout << s->findMinArrowShots(points2) << endl;
	vector<vector<int>> points3 = { {1,2} };
	cout << s->findMinArrowShots(points3) << endl;
	return 0;
}
*/
