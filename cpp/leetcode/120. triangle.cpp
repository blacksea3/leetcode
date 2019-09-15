#include "public.h"

//4ms, 97.47%
//DP问题, 倒序, 从下往上按行扫描

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		//一行一行扫下来,扫的时候就把当前最小路径算出来!
		//倒序,从下往上扫

		int nline = triangle.size();
		if (nline == 0) return 0;
		else
		{
			for (int i = nline - 2; i >= 0; --i)   //i表示第i+1行
			{
				for (int j = 0; j < i + 1; ++j)  //操作第i+1行的下标为j的元素
					triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];  //最小值就是顶元素
	}
};
