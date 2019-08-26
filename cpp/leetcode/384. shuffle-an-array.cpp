#include "public.h"

//400ms, 43.15%
//Fisher-Yates ϴ���㷨
//����һ������, Ȼ����±�0 - n-1, ���ѡȡ, 1/n�ĸ���ѡ��һ����, ��nums[0]����λ��;
//    Ȼ����±�1 - n-1���ѡȡ, 1/n-1�ĸ���ѡ��һ����, ��ǰ�����ѡ�����ܸ��ʼ�Ϊn-1/n * 1/n-1 = 1/n�͵�һ��ѡ������ͬ,
//    ��nums[1]����λ�� .... һֱ������ȥ
//ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(n)

class Solution {
private:
	vector<int> copy;
public:
	Solution(vector<int>& nums) {
		copy = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return copy;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> temp = copy;
		int tsize = temp.size();
		int abs = 0;

		for (int start = 0; start < temp.size(); ++start)
		{
			swap(temp[rand() % (tsize - start) + start], temp[start]);
		}

		return temp;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
