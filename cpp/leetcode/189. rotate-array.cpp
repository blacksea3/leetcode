#include "public.h"

//20ms, 98.82%
//���η�ת����

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0) return;  //dump

		//�ȵ�֪��Ч���ƶ�����
		k = k % nums.size();
		if (k == 0) return;  //����Ҫ��ת

		//�����۵ķ���,ʱ�临�Ӷ�O(n)
		//��תǰ�벿��,��벿��,ȫ��,  ���Ӷȿ�����Ϊ��O(2*n) = O(n)

		reverse(nums.begin(), nums.begin() + nums.size() - k);
		reverse(nums.begin() + nums.size() - k, nums.end());
		reverse(nums.begin(), nums.end());

	}
};
