#include "public.h"

//72ms, 97.96%
//˫�����
//���ǵ����µ�����:1 4 3 6 2 5, k=4
//��ʼ��˫�����, ����4����, �����ǰ���ȶ���ĩβ������, ��ȥ������ĩβ��, ֱ����ǰ���ȶ���ĩλ��С, ��¼������ĩβ
//����ʹ��˫����д�ͷ��β�������Ӧ����һ���������С, ���Ҵ�ͷ��β����������

//Ȼ�����ʣ��������, ά�����˫����м���

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int nsize = nums.size();
		if (nsize == 0) return {};
		vector<int> res;
		deque<int> dq;

		//init
		for (int i = 0; i < k; ++i)
		{
			while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
			dq.push_back(i);
		}
		res.push_back(nums[dq.front()]);

		for (int i = k; i < nsize; ++i)
		{
			if (dq.front() <= (i - k)) dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
			dq.push_back(i);
			res.push_back(nums[dq.front()]);
		}
		return res;
	}
};

