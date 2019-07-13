#include "public.h"

//44ms, 98.28%
//ʹ��set + search(DFS)
//˼·: ����ΧһȦ�ڵ���Ϊ��ʼ��, �Ӹ߶���С�Ľڵ㿪ʼ����δ�������ĵ�, ����Χ�ĵ�߶ȱ�����, �����ڹ�ˮ, ������ˮ������µ�߶�, ����������ʼ��, ֱ�����е��������

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int maxrow = heightMap.size();
		if (maxrow == 0) return 0;
		int maxcol = heightMap[0].size();
		//init mm and issearched
		multimap<int, pair<int, int>> mm;  //��: �߶�, ֵ: ����. Ĭ��: ��������
		vector<vector<bool>> issearched(maxrow, vector<bool>(maxcol, false));
		for (int row = 0; row < maxrow; ++row)
		{
			mm.insert(pair<int, pair<int, int>>{heightMap[row][0], { row, 0 }});
			mm.insert(pair<int, pair<int, int>>{heightMap[row][maxcol - 1], { row, maxcol - 1 }});
			issearched[row][0] = true;
			issearched[row][maxcol - 1] = true;
		}
		for (int col = 1; col < maxcol - 1; ++col)
		{
			mm.insert(pair<int, pair<int, int>>{heightMap[0][col], { 0, col }});
			mm.insert(pair<int, pair<int, int>>{heightMap[maxrow - 1][col], { maxrow - 1, col }});
			issearched[0][col] = true;
			issearched[maxrow - 1][col] = true;
		}

		//init res
		int res = 0;

		//start search(DFS)
		while (!mm.empty())
		{
			pair<int, pair<int, int>> pre = *mm.begin();
			int prerow = pre.second.first;
			int precol = pre.second.second;
			int preheight = pre.first;
			if ((prerow > 0) && (!issearched[prerow - 1][precol]))
			{
				if (preheight > heightMap[prerow - 1][precol])
				{
					res += preheight - heightMap[prerow - 1][precol];
					mm.insert(pair<int, pair<int, int>>{preheight, { prerow - 1, precol }});
				}
				else
				{
					mm.insert(pair<int, pair<int, int>>{heightMap[prerow - 1][precol], { prerow - 1, precol }});
				}
				issearched[prerow - 1][precol] = true;
			}
			if ((precol > 0) && (!issearched[prerow][precol - 1]))
			{
				if (preheight > heightMap[prerow][precol - 1])
				{
					res += preheight - heightMap[prerow][precol - 1];
					mm.insert(pair<int, pair<int, int>>{preheight, { prerow, precol - 1 }});
				}
				else
				{
					mm.insert(pair<int, pair<int, int>>{heightMap[prerow][precol - 1], { prerow, precol - 1 }});
				}
				issearched[prerow][precol - 1] = true;
			}
			if ((prerow < maxrow - 1) && (!issearched[prerow + 1][precol]))
			{
				if (preheight > heightMap[prerow + 1][precol])
				{
					res += preheight - heightMap[prerow + 1][precol];
					mm.insert(pair<int, pair<int, int>>{preheight, { prerow + 1, precol }});
				}
				else
				{
					mm.insert(pair<int, pair<int, int>>{heightMap[prerow + 1][precol], { prerow + 1, precol }});
				}
				issearched[prerow + 1][precol] = true;
			}
			if ((precol < maxcol - 1) && (!issearched[prerow][precol + 1]))
			{
				if (preheight > heightMap[prerow][precol + 1])
				{
					res += preheight - heightMap[prerow][precol + 1];
					mm.insert(pair<int, pair<int, int>>{preheight, { prerow, precol + 1 }});
				}
				else
				{
					mm.insert(pair<int, pair<int, int>>{heightMap[prerow][precol + 1], { prerow, precol + 1 }});
				}
				issearched[prerow][precol + 1] = true;
			}
			mm.erase(mm.begin());
		}
		return res;
	}
};

