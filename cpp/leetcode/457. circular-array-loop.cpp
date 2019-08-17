#include "public.h"

//4ms, 88.97%
//模拟
//从loc=0处开始, 若不可以则换loc=1...
//使用memory记录已经访问过的节点

class Solution {
public:
	bool circularArrayLoop(vector<int>& nums) {
		int startloc = 0;
		int nsize = nums.size();

		vector<int> memory(nsize, 0); //0:未访问, 其他:访问
		int precolor = 1;

		while (startloc < nsize)
		{
			if (memory[startloc] != 0) startloc++;  //已访问过
			else
			{
				bool ispositive = (nums[startloc] > 0);
				int preloc = startloc;  //2, -1, 1, 2, 2

				if (ispositive)
				{
					do {
						if (nums[preloc] < 0 || ((nums[preloc] % nsize) == 0)) break;
						else if (memory[preloc] == precolor) return true;  //已经找到环
						else if (memory[preloc] != 0) break;
						else
						{
							memory[preloc] = precolor;
							preloc = (nums[preloc] + preloc) % nsize;
						}
					} while (true);
				}
				else
				{
					do {
						if (nums[preloc] > 0 || ((abs(nums[preloc]) % nsize) == 0)) break;
						else if (memory[preloc] == precolor) return true;  //已经找到环
						else if (memory[preloc] != 0) break;
						else
						{
							memory[preloc] = precolor;
							preloc = (nums[preloc] + preloc) % nsize;
							if (preloc < 0) preloc += nsize;
						}
					} while (true);
				}
				startloc++;
				precolor++;
			}
		}
		return false;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums3 = { -1, -2, -3, -4, -5 };
	cout << s->circularArrayLoop(nums3) << endl;
	vector<int> nums3 = { -1, -1, -1 };
	cout << s->circularArrayLoop(nums3) << endl;
	vector<int> nums = { -1, 2 };
	cout << s->circularArrayLoop(nums) << endl;
	vector<int> nums2 = {2, -1, 1, 2, 2};
	cout << s->circularArrayLoop(nums2) << endl;
	return 0;
}
*/
