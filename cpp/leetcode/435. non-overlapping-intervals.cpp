#include "public.h"

//24ms, 72.18%
//���������,
//Ȼ��: �����ж��ڽ�����������, ����ص�, �Ƴ��յ㳤��, ����res++;

class Solution {
private:
	//v[0]С����ǰ, �������v[1]С����ǰ, ���������λ�ò���
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
