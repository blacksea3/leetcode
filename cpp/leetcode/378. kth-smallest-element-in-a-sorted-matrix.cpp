#include "public.h"

//80ms, 35.39%
//��ָ��

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		multimap<int, pair<int, int>> sorted_value_and_loc;
		//init
		for (int i = 0; i < matrix.size(); ++i) //��ʼ��ÿ�п�ͷԪ��
			sorted_value_and_loc.insert(pair<int, pair<int, int>>{matrix[i][0], pair<int, int>{i, 0}});

		//ע��kһ����Ч
		for (int i = 1; i < k; ++i) //count k-1 times
		{
			pair<int, pair<int, int>> pre = *sorted_value_and_loc.begin();
			sorted_value_and_loc.erase(sorted_value_and_loc.begin());
			if (pre.second.second < matrix[0].size() - 1)
			{
				pre.second.second++;
				pre.first = matrix[pre.second.first][pre.second.second];
				sorted_value_and_loc.insert(pre);
			}
		}
		pair<int, pair<int, int>> pre = *sorted_value_and_loc.begin();
		return matrix[pre.second.first][pre.second.second];
	}
};
