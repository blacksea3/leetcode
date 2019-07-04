#include "public.h"

//4ms, 90.32%
//̰��
//��ͣ��������/�½�ת�۵�
//ת�۵�+1=���, ע������е�init����

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty()) return 0;

		int res = 1;
		bool isup = true; //0: up, 1:down
		bool isfirst = true;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (isfirst)
			{
				if (nums[i] < nums[i + 1])
				{
					res++;
					isup = true;
					isfirst = false;
				}
				else if (nums[i] > nums[i + 1])
				{
					res++;
					isup = false;
					isfirst = false;
				}
			}
			else
			{
				if ((nums[i] < nums[i + 1]) && (!isup))
				{
					res++;
					isup = true;
				}
				else if ((nums[i] > nums[i + 1]) && (isup))
				{
					res++;
					isup = false;
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = {};
	cout << s->wiggleMaxLength(nums);
	return 0;
}
*/
