#include "include.h"

#ifdef LEETCODE_161_170
#include "public.h"
#include "leetcode.h"

int Solution::findPeakElement(vector<int>& nums)
{
	//��������
	//ע�⵽:   nums[mid] < nums[mid+1]   1 4 3 2 1  �������, �ܻ���mid+1��end���ַ�ֵԪ��
	//������Ϊmid+1��end���������˶���
	//����start��midһ����Ԫ��

	//ע�����ڵ�Ԫ�ز�ͬ

	int left = 0;
	int right = nums.size() - 1;
	int mid;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < nums[mid + 1])
			left = mid + 1;
		else
			right = mid;
	}

	return left;

}

int Solution::maximumGap(vector<int>& nums)
{
	//��������
	//���ǷǸ�����!
	if (nums.size() <= 1) return 0;
	else
	{
		int nmax = 0;
		//�ȸ��������
		for (auto num : nums)
			nmax = max(num, nmax);

		//�������������ж���λ,������order10_value�����10
		int order10_value = 0;
		while (nmax > 0)
		{
			nmax /= 10;
			order10_value++;
		}

		//�������,ȫ0?????
		if (order10_value == 0)
			return 0;
		else
		{
			//��ʽ��������
			vector<queue<int>> base(10, queue<int>{});
			vector<int> constants = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

			for (int i = 1; i <= order10_value; i++)  //i��λ��
			{
				for (auto num : nums)
				{
					if (i < 10)
						base[num%constants[i] / constants[i - 1]].push(num);
					else
						base[num / constants[i - 1]].push(num);
				}
				//�ϲ���nums
				vector<int> newnums = {};
				for (int i = 0; i < 10; i++)
				{
					while (!base[i].empty())
					{
						newnums.push_back(base[i].front());
						base[i].pop();
					}
				}
				nums.clear();
				nums.assign(newnums.begin(), newnums.end());
			}

			//�������,��������ֵ
			int maxdiff = 0;
			for (int i = 1; i < nums.size(); i++)
				maxdiff = max(nums[i] - nums[i - 1], maxdiff);

			return maxdiff;
		}
	}
}

#else
#endif
