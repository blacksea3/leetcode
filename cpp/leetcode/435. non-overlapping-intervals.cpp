#include "public.h"

//24ms, 72.18%
//按起点排序,
//然后: 依次判断邻近的两个区间, 如果重叠, 移除终点长的, 否则res++;

class Solution {
private:
	//v[0]小的在前, 若相等则v[1]小的在前, 若还相等则位置不变
	static bool msort(const vector<int>& v1, const vector<int>& v2)
	{
		if (v1[0] < v2[0]) return true;
		else if (v1[0] > v2[0]) return false;
		else return v1[1] < v2[1];
	}

public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.size() == 0) return 0;
		int rawsize = intervals.size();
		sort(intervals.begin(), intervals.end(), msort);

		int res = 0;
		int left = 0;
		int right = 1;
		while (right < intervals.size())
		{
			if (intervals[left][1] <= intervals[right][0])
			{
				left = right;
				right++;
				res++;
			}
			else
			{
				if (intervals[left][1] > intervals[right][1])
				{
					left = right;
					right++;
				}
				else
				{
					right++;
				}
			}
		}
		return rawsize - (res + 1);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> intervals = { {1,100},{11,22},{1,11},{2,12} };
	cout << s->eraseOverlapIntervals(intervals);
	//vector<vector<int>> intervals = { {1,2},{1,2},{1,2} };
	//cout << s->eraseOverlapIntervals(intervals);
	return 0;
}
*/
