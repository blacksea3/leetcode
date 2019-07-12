#include "public.h"

//88ms, 99.42%
//��Ԫ����ˮ�س���
//����ǰԪ���ǵ�i������target��Ԫ��ʱ, ��1/i�ĸ��������滻֮ǰ��Ԫ��
//ÿ���±��ȡ�ĸ�����Ϊ1/n, nΪnums�е���target��Ԫ������

class Solution {
private:
	vector<int> cpy;
public:
	Solution(vector<int>& nums) {
		cpy = nums;
	}

	int pick(int target) {
		int pre = 0;
		int loc = -1;
		//���ܸ���������һ������������, ʵ���ϲ����ڵĻ��򷵻�-1

		for (int i = 0; i < cpy.size(); ++i)
		{
			if (cpy[i] == target)
			{
				pre++;
				if (rand() % pre == 0) loc = i;
			}
		}
		return loc;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
