#include "public.h"

//̰��
//ʹ��mask: ǰ����1������0
//��nums�е���������ģ���벢�洢, Ȼ��Ӹߵ��ͼ��赱ǰλ�ÿ�����1, ��洢�е��������, ������������ڴ洢��, ˵��ȷʵ������1, ����ֻ����0
//�Ӹ�λ����λ�����ж�

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {

		int mask = 0;
		int nsize = nums.size();

		int temp = 0;
		int res = 0;

		for (int i = 31; i >= 0; --i)
		{
			mask |= (1 << i);

			unordered_set<int> stores;
			for (int j = 0; j < nsize; ++j)
				stores.insert(nums[j] & mask);

			temp = res | (1 << i);

			for (auto& store : stores)
			{
				if (stores.find(store^temp) != stores.end())
				{
					res |= (1 << i);
					break;
				}
			}
		}
		return res;
	}
};
