#include "public.h"

//12ms, 46.96%
//һ��ɨ��nums, ��¼����min:
//�����, Ȼ�������ǰ���ֱȺ�һ��min����ôtrue, ���С, ȥ��һ��min, �ٱȽ�
//��ʵ���൱�ڵ���ջ

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		bool minmindump = true;
		bool minmiddump = true;
		int minmin = -1;
		int minmid = -1;

		for (auto &n : nums)
		{
			if (minmindump)
			{
				minmin = n;
				minmindump = false;
			}
			else if (minmiddump)
			{
				if (n < minmin)
				{
					minmin = n;
				}
				else if (n > minmin)
				{
					minmid = n;
					minmiddump = false;
				}
			}
			else
			{
				if (n < minmid)
				{
					if (n < minmin)
					{
						minmin = n;
						minmiddump = false;
					}
					else if (n > minmin) minmid = n;
				}
				else if (n > minmid) return true;
			}
		}
		return false;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2,1,2,1,2 };
	//vector<int> nums = { 1,0,0,-1,0,0,1000 };
	cout << s->increasingTriplet(nums);
	return 0;
}
*/
