#include "public.h"

//52ms, 20.14%
//�Ƚ��ַ���ת�ɷ���, Ȼ������, Ȼ�������Ƚ�
//ע����λ�ٱȽ�һ��

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		vector<int> minutes;

		for (auto& timePoint : timePoints)
		{
			minutes.push_back(atoi(timePoint.substr(0, 2).c_str()) * 60 +
				atoi(timePoint.substr(3).c_str()));
		}

		sort(minutes.begin(), minutes.end());

		int res = INT_MAX;
		for (int index = 1; index < minutes.size(); ++index)
		{
			res = min(res, minutes[index] - minutes[index - 1]);
		}

		res = min(res, 24 * 60 - minutes[minutes.size() - 1] + minutes[0]);

		return res;
	}
};
