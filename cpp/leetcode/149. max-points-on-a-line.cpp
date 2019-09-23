#include "public.h"

//28ms, 57.02%
//��ĳ��������,�����е�ɨһ�ν���Ψһ�Լ�¼:����б�ʼ�¼
//��¼��ֵ����һ��pair<int a,int b>��ʾ a/b (a��������������,bֻ����������)
//init:extra = 0
//������������ظ��ĵ�,extra+=1(ע��,���ֵ�ض�>=1��Ϊ���е�����Ǹ�������)
//Ȼ����ڴ�����б��,�ҵ�������ߵľͿ�����

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		int psize = points.size();
		if (psize <= 2) return psize;
		
		int maxpoints = 0;

		//��ʽ����
		for (int i = 0; i < psize; i++)
		{
			int extra = 0;
			int tempmaxpoints = 0;
			unordered_map<int, unordered_map<int, int>> slice_dict;  //��y��ؾ�, ֵΪdict:(��x��ؾ�, ֵ����)
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
			//ɨһ��slice_dict
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
