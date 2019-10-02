#include "public.h"

//20ms, 97.50%
//�ȵ�֪��Ч���ƶ�����

//���η�ת����
//�����۵ķ���,ʱ�临�Ӷ�O(n)
//��תǰ�벿��,��벿��,ȫ��,  ���Ӷȿ�����Ϊ��O(2*n) = O(n)

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0) return;  //dump
		k = k % nums.size();
		if (k == 0) return;  //����Ҫ��ת
		reverse(nums.begin(), nums.begin() + nums.size() - k);
		reverse(nums.begin() + nums.size() - k, nums.end());
		reverse(nums.begin(), nums.end());
	}
};
