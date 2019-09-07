#include "public.h"

//44ms, 34.03%
//ͼ
//�����������ӹ�ϵ: ��������i, i����һ���ڵ���A[i]
//���ǵ��������ǡ�ð���0 - N-1, û���ظ�Ԫ��, ��˿�����Ϊ
//ͼ�ɶ�������
//��ôֻ��Ҫһ�������Ϳ�

class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int nsize = nums.size();
		vector<bool> isSearched(nsize, false);

		int index = 0;
		int res = 0;

		while (index < nsize)
		{
			//��ʼ����
			int preLen = 0;
			while (!isSearched[index])
			{
				isSearched[index] = true;
				index = nums[index];
				preLen++;
			}
			res = max(res, preLen);
			//�ƶ��������
			while (index < nsize && isSearched[index]) index++;
		}
		return res;
	}
};
