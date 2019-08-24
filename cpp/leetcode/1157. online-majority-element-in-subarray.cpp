#include "public.h"

class MajorityChecker {
private:
	vector<int> v;
public:
	MajorityChecker(vector<int>& arr) {
		v = arr;
	}

	int query(int left, int right, int threshold) {
		//unordered_map<int, int> um;

		int ans;
		int flag = 0;
		for (int i = left; i <= right; i++)
		{
			if (flag > 0)
			{
				if (ans == v[i])
					flag++;
				else
					flag--;
			}
			else
			{
				flag = 1;
				ans = v[i];
			}
		}

		int num = 0;
		for (int i = left; i <= right; i++)
		{
			if (ans == v[i])
				num++;   //验证该数字是否超过一半
		}

		if (num >= threshold) return ans;
		else return -1;
	}
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */