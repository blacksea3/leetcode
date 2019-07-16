#include "public.h"

//244ms, 79.55%
//固定第一列, 通过判断别的列是否和其相同生成关于行的特定数据

class Solution {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		//fixed first column

		unordered_map<string, int> um;
		bool reverse;

		for (auto m : matrix)
		{
			if (m[0] == 1) reverse = true;
			else reverse = false;
			string unique = "";
			for (int i = 1; i < m.size(); ++i)
			{
				if (reverse)
				{
					if (m[i] == 0) unique += "1";
					else unique += "0";
				}
				else
				{
					if (m[i] == 0) unique += "0";
					else unique += "1";
				}
			}
			um[unique]++;
		}

		unordered_map<string, int>::iterator iter;
		int res = 0;
		for (iter = um.begin(); iter != um.end(); iter++)
		{
			res = max(res, iter->second);
		}
		return res;
	}
};
