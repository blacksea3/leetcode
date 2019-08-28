#include "public.h"

//188ms, 55.65%
//��unordered_map��¼�ض�ֵ:x��һ����nums�г��ֵ�index, ��ֵx��ʾ�ӿ�ͷ��ʼ��0������ȥ1����
//��ʼ��unordered_map[0] = -1
//��ڶ��γ������ֵ��ʱ��, �м�������������0������1������ͬ

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int preX = 0;
		unordered_map<int, int> count;
		count[0] = -1;
		int res = 0;

		for (int index = 0; index < nums.size(); ++index)
		{
			if (nums[index] == 0)
			{
				preX++;
			}
			else
			{
				preX--;
			}

			if (count.find(preX) == count.end())
			{
				count[preX] = index;
			}
			else
			{
				res = max(res, index - count[preX]);
			}
		}
		return res;
	}
};
