#include "public.h"

//456ms, 8.80%
//ά��һ��sorted vector

class KthLargest {
private:
	vector<int> sorted;
	int gbl_k;
public:
	KthLargest(int k, vector<int>& nums) {
		sorted = nums;
		sort(sorted.begin(), sorted.end());
		gbl_k = k;
	}

	int add(int val) {
		//Ѱ�Ҳ���λ��
		vector<int>::iterator iter = upper_bound(sorted.begin(), sorted.end(), val);
		if (iter == sorted.end())
			sorted.push_back(val);
		else
			sorted.insert(iter, val);
		return sorted[sorted.size() - gbl_k];
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
