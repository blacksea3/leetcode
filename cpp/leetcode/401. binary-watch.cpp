#include "public.h"

//4ms, 91.58%
//DFS

class Solution {
private:
	vector<string> res;
	vector<int> nums = { 8,4,2,1,32,16,8,4,2,1 };
	void DFS(int num, vector<int> pre, int preloc, int len)
	{
		for (int k = preloc + 1; k <= 9; ++k)
		{
			pre.push_back(k);
			if (len == num)
			{
				int minute = 0;
				int hour = 0;
				string t = "";
				for (int i = 0; i < pre.size(); ++i)
				{
					if (pre[i] <= 3) hour += nums[pre[i]];
					else minute += nums[pre[i]];
				}
				if (hour < 12) t += to_string(hour);
				else goto oc;
				t += ":";
				if (minute > 59) goto oc;
				else if (minute > 9) t += to_string(minute);
				else
				{
					t += "0";
					t += to_string(minute);
				}
				res.push_back(t);

			oc:;
			}
			else DFS(num, pre, k, len + 1);
			pre.pop_back();
		}
	}
public:
	vector<string> readBinaryWatch(int num) {
		if (num == 0) return { "0:00" };
		DFS(num, vector<int> {}, -1, 1);
		return res;
	}
};
