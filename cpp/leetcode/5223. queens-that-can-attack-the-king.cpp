#include "public.h"

//
//将queens坐标转化, 然后从白国王向8个方向扩展, 寻找能找到的黑皇后, 找到一个就放一个, 到棋盘边界都找不到就算了

class Solution {
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		unordered_set<int> qLoc;

		vector<vector<int>> res;

		for (auto& queen : queens)
		{
			qLoc.insert(queen[0] * 100 + queen[1]);
		}

		//8方向
		//上下左右
		int rawr = king[0];
		int rawc = king[1];

		for (int r = rawr; r >= 0; --r)
		{
			if (qLoc.find(100 * r + rawc) != qLoc.end())
			{
				res.push_back(vector<int>{r, rawc});
				break;
			}
		}

		for (int r = rawr; r <= 7; ++r)
		{
			if (qLoc.find(100 * r + rawc) != qLoc.end())
			{
				res.push_back(vector<int>{r, rawc});
				break;
			}
		}

		for (int c = rawc; c >= 0; --c)
		{
			if (qLoc.find(100 * rawr + c) != qLoc.end())
			{
				res.push_back(vector<int>{rawr, c});
				break;
			}
		}

		for (int c = rawc; c <= 7; ++c)
		{
			if (qLoc.find(100 * rawr + c) != qLoc.end())
			{
				res.push_back(vector<int>{rawr, c});
				break;
			}
		}

		//斜的
		for (int r = rawr, c = rawc; r >= 0 && c >= 0; --r, --c)
		{
			if (qLoc.find(100 * r + c) != qLoc.end())
			{
				res.push_back(vector<int>{r, c});
				break;
			}
		}

		for (int r = rawr, c = rawc; r <= 7 && c >= 0; ++r, --c)
		{
			if (qLoc.find(100 * r + c) != qLoc.end())
			{
				res.push_back(vector<int>{r, c});
				break;
			}
		}

		for (int r = rawr, c = rawc; r <= 7 && c <= 7; ++r, ++c)
		{
			if (qLoc.find(100 * r + c) != qLoc.end())
			{
				res.push_back(vector<int>{r, c});
				break;
			}
		}

		for (int r = rawr, c = rawc; r >= 0 && c <= 7; --r, ++c)
		{
			if (qLoc.find(100 * r + c) != qLoc.end())
			{
				res.push_back(vector<int>{r, c});
				break;
			}
		}

		return res;
	}
};
