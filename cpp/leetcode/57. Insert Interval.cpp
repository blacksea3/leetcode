#include "public.h"

//44ms, 23.98%
//�ȶ��ֲ��ҵ���˵����λ��, �ٶ��ֲ����Ҷ˵����λ��, �Ǿ͵غϲ�, ��Ч����Ȼ��O(n), �ȴ�ͳ����O(n)һ��ɨ�軹Ҫ��
//���Ż�

class Solution {
	//������˵�С�ڲ���λ����˵�
	static bool comp_left(const vector<int> &a, const vector<int> &b) {
		return a[0] < b[0];
	}
	//�����Ҷ˵�С�ڲ���λ���Ҷ˵�
	static bool comp_right(const vector<int> &a, const vector<int> &b) {
		return a[1] < b[1];
	}
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		//���ҵ�һ��������cmp������λ��
		//�����ҵ�һ��������˵�>=����λ����˵�
		int leftAbsLoc = lower_bound(intervals.begin(), intervals.end(), newInterval, comp_left) - intervals.begin();
		//�����ҵ�һ�������Ҷ˵�>=����λ���Ҷ˵�
		int rightAbsLoc = lower_bound(intervals.begin(), intervals.end(), newInterval, comp_right) - intervals.begin();

		int left = max(leftAbsLoc - 1, 0);
		int right = min(rightAbsLoc + 1, (int)intervals.size());

		//leftlis: [0:left], midlis: [left:right], rightlis: [right:]
		vector<vector<int>> leftlis(intervals.begin(), intervals.begin() + left);
		vector<vector<int>> midlis(intervals.begin() + left, intervals.begin() + right);
		vector<vector<int>> rightlis(intervals.begin() + right, intervals.end());

		if (!midlis.empty())
		{
			if (newInterval[0] <= midlis[0][1] && newInterval[1] >= midlis[midlis.size() - 1][0])
			{
				midlis = vector<vector<int>>{ {min(midlis[0][0], newInterval[0]), max(midlis[midlis.size() - 1][1], newInterval[1])} };
			}
			else if (newInterval[0] > midlis[0][1] and newInterval[1] >= midlis[midlis.size() - 1][0])
			{
				vector<int> tempNewInt =vector<int>{newInterval[0], max(midlis[midlis.size() - 1][1], newInterval[1])};
				midlis.erase(midlis.begin() + 1, midlis.end());
				midlis.emplace_back(tempNewInt);
			}
			else if (newInterval[0] <= midlis[0][1] and newInterval[1] < midlis[midlis.size() - 1][0])
			{
				vector<int> tempNewInt = vector<int>{min(midlis[0][0], newInterval[0]), newInterval[1]};
				midlis.erase(midlis.begin(), midlis.end() - 1);
				midlis.insert(midlis.begin(), tempNewInt);
			}
			else
			{
				midlis.erase(midlis.begin() + 1, midlis.end() - 1);
				midlis.insert(midlis.begin() + 1, newInterval);
			}
		}
		else
		{
			midlis = vector<vector<int>>{ newInterval };
		}

		leftlis.insert(leftlis.end(), midlis.begin(), midlis.end());
		leftlis.insert(leftlis.end(), rightlis.begin(), rightlis.end());

		return leftlis;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> intervals = { {1,3},{6,9} };
	vector<int> newInterval = {2,5};
	auto res = s->insert(intervals, newInterval);
	return 0;
}
*/
