#include "public.h"

//120ms, 56.59%
//???�ⷽ��C++�ӽ�python3���ٶ�, ��ռ�ÿռ����???
//ԭ��δ֪

//̰��, O(n)
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
			int preBitOp = (1 << i);
			mask |= preBitOp;

			unordered_set<int> stores;
			for (auto& num:nums)
				stores.insert(num & mask);

			temp = res | preBitOp;
			for (auto& store : stores)
			{
				if (stores.find(store^temp) != stores.end())
				{
					res = temp;
					break;
				}
			}
		}
		return res;
	}
};
