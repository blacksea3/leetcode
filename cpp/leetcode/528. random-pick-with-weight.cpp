#include "public.h"

//320ms, 27.88%
//��Ȩ��תΪ����
//����: ��1,2,3��ѡ��, ��ȼ�����1-6�������, 1->1, 2,3->2, 4,5,6->3
//��ô��¼1,3,6, ���ҵ�һ������0-5���ֵ�λ��

class Solution {
private:
	vector<int> locations;

public:
	Solution(vector<int>& w) {
		int preSum = 0;
		for (int index = 0; index < w.size(); ++index)
		{
			preSum += w[index];
			locations.push_back(preSum);
		}
	}

	int pickIndex() {
		int totalSum = locations[locations.size() - 1];
		int ranVal = rand() % totalSum;

		int absVal = upper_bound(locations.begin(), locations.end(), ranVal) - locations.begin();
		return absVal;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
