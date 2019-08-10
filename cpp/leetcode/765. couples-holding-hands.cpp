#include "public.h"

//4ms, 83.75%
//暴力, 贪心: 固定奇数位找偶数位然后交换

class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int res = 0;
		for (int i = 0; i < row.size(); i += 2)
		{
			if (row[i] % 2)
			{
				//寻找row[i]-1
				if (row[i + 1] == row[i] - 1) continue;
				else
				{
					for (int j = i + 2; j < row.size(); ++j)
					{
						if (row[j] == row[i] - 1)
						{
							swap(row[j], row[i + 1]);
							break;
						}
					}
					res++;
				}
			}
			else
			{
				//寻找row[i]+1
				if (row[i + 1] == row[i] + 1) continue;
				else
				{
					for (int j = i + 2; j < row.size(); ++j)
					{
						if (row[j] == row[i] + 1)
						{
							swap(row[j], row[i + 1]);
							break;
						}
					}
					res++;
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> rows = { 0,2,1,3 };
	cout << s->minSwapsCouples(rows);
	return 0;
}
*/
