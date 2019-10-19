#include "public.h"

//
//类似滑动窗口, 双指针
//先排序

class Solution {
private:
	static bool msort(vector<int> const& v1, vector<int> const& v2)
	{
		if (v1[0] < v2[0]) return true;
		else if (v1[0] > v2[0]) return false;
		else return v1[1] < v2[1];
	}

public:
	vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
		int s1Index = 0;
		int s2Index = 0;

		int slots1Size = slots1.size();
		int slots2Size = slots2.size();

		//排序
		sort(slots1.begin(), slots1.end(), msort);
		sort(slots2.begin(), slots2.end(), msort);

		while (s1Index < slots1Size && s2Index < slots2Size)
		{
			if (slots1[s1Index][0] >= slots2[s2Index][1])
			{
				s2Index++;
			}
			else if (slots2[s2Index][0] >= slots1[s1Index][1])
			{
				s1Index++;
			}
			else
			{
				if (slots1[s1Index][0] <= slots2[s2Index][0])  //以slots2[s2Index][0]为起始
				{
					if (slots1[s1Index][1] <= slots2[s2Index][1]) //以slots1[s1Index][1]为结束
					{
						if ((slots1[s1Index][1] - slots2[s2Index][0]) >= duration)
						{
							return vector<int>{slots2[s2Index][0], slots2[s2Index][0] + duration};
						}
						else
						{
							s1Index++;
						}
					}
					else  //以slots2[s2Index][1]为结束
					{
						if ((slots2[s2Index][1] - slots2[s2Index][0]) >= duration)
						{
							return vector<int>{slots2[s2Index][0], slots2[s2Index][0] + duration};
						}
						else
						{
							s2Index++;
						}
					}
				}
				else  //以slots1[s1Index][0]为起始
				{
					if (slots1[s1Index][1] <= slots2[s2Index][1]) //以slots1[s1Index][1]为结束
					{
						if ((slots1[s1Index][1] - slots1[s1Index][0]) >= duration)
						{
							return vector<int>{slots1[s1Index][0], slots1[s1Index][0] + duration};
						}
						else
						{
							s1Index++;
						}
					}
					else  //以slots2[s2Index][1]为结束
					{
						if ((slots2[s2Index][1] - slots1[s1Index][0]) >= duration)
						{
							return vector<int>{slots1[s1Index][0], slots1[s1Index][0] + duration};
						}
						else
						{
							s2Index++;
						}
					}
				}
			}
		}
		return vector<int>{};
	}
};