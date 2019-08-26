#include "public.h"

//92ms, 25.83%
//����+����
//�����������һ��<=��, >=�������
//����ĳ����������, �����ж��Ƿ�����, Ѱ��x����:x-1��������, x��������
//�ڵ�������������ʱ��ʹ�ö��ֲ���
//ʱ�临�Ӷ�ΪO(nlogn)

class Solution {
private:
	bool isok(const vector<int>& weights, int store, int D)
	{
		int loc = 0;
		int pres = 0;
		int days = 1;
		while (loc < weights.size())
		{
			if (pres + weights[loc] > store)
			{
				if (days == D) return false;
				days++;
				pres = 0;
			}
			else
			{
				pres += weights[loc];
				loc++;
			}
		}
		return true;
	}

public:
	int shipWithinDays(vector<int>& weights, int D) {
		int maxl = 0;
		for (auto& w : weights) maxl = max(maxl, w);

		int left = maxl;
		int right = accumulate(weights.begin(), weights.end(), 0);

		while (left <= right)
		{
			int mid = (right - left) / 2 + left;
			if (!isok(weights, mid, D)) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> weights = { 1,2,3,4,5,6,7,8,9,10};
	auto res = s->shipWithinDays(weights, 5);
	return 0;
}
*/
