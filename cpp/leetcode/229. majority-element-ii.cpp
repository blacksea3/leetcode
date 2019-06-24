#include "public.h"

//20ms, 81.62%
//Ħ��ͶƱ��
//ע��:�������ֻ��������������1/3����
//���:ÿ��ѡ������ѡ��,һ������������,�ͺ����Ǻϲ�(��ѡ��������һ)
//�����ѡ��������0,����һ������Ϊ��ѡ��
//��ô���������������1/3����,����Ȼ��ÿһ�ֵĺϲ�״̬�е�����,���һ�����!
//������һ���������,���ں�ѡ��
//������ж�һ�κ�ѡ���Ƿ�ȷʵ������

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int p;
		int q;  //p/q��ѡ��
		int pnums = 0;
		int qnums = 0;

		//��һ��
		for (auto& n : nums)
		{
			if ((!pnums) && (!qnums))
			{
				p = n;
				pnums++;
			}
			else if (!pnums)
			{
				if (n != q)
				{
					p = n;
					pnums++;
				}
				else
					qnums++;
			}
			else if (!qnums)
			{
				if (n != p)
				{
					q = n;
					qnums++;
				}
				else
					pnums++;
			}
			else if (n == q) qnums++;
			else if (n == p) pnums++;
			else
			{
				qnums--;
				pnums--;
			}
		}

		//�ڶ���
		pnums = 0;
		qnums = 0;
		for (auto& n : nums)
		{
			if (n == p) pnums++;
			else if (n == q) qnums++;
		}
		vector<int> res;
		if (pnums > nums.size() / 3) res.push_back(p);
		if (qnums > nums.size() / 3) res.push_back(q);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 3,0,3,4 };
	vector<int> res = s->majorityElement(nums);
	return 0;
}
