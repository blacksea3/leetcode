#include "public.h"

//28ms, 57.02%
//对某个给定点,对所有点扫一次进行唯一性记录:按照斜率记录
//记录的值将是一个pair<int a,int b>表示 a/b (a可能是任意整数,b只能是正整数)
//init:extra = 0
//对于与给定点重复的点,extra+=1(注意,这个值必定>=1因为所有点包含那个给定点)
//然后对于大量的斜率,找到数量最高的就可以了

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		int psize = points.size();
		if (psize <= 2) return psize;
		
		int maxpoints = 0;

		//正式计算
		for (int i = 0; i < psize; i++)
		{
			int extra = 0;
			int tempmaxpoints = 0;
			unordered_map<int, unordered_map<int, int>> slice_dict;  //键y轴截距, 值为dict:(键x轴截距, 值个数)
			for (int j = 0; j < psize; j++)
			{
				if ((points[i][0] == points[j][0]) && (points[i][1] == points[j][1]))
					extra++;
				else
				{
					int dx = points[i][0] - points[j][0];
					int dy = points[i][1] - points[j][1];
					if (dx == 0)
					{
						slice_dict[1][0] += 1;
					}
					else if (dy == 0)
					{
						slice_dict[0][1] += 1;
					}
					else
					{
						int c = gcd(dy, dx);
						slice_dict[dy / c][dx / c] += 1;
					}
				}
			}
			//扫一遍slice_dict
			for (auto& slice:slice_dict)
			{
				for (auto& count : slice.second)
				{
					tempmaxpoints = max(tempmaxpoints, count.second);
				}
			}
			tempmaxpoints += extra;
			maxpoints = max(maxpoints, tempmaxpoints);
		}
		return maxpoints;
	}
};
