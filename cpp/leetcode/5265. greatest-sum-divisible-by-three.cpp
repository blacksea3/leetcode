#include "public.h"

//��������
//����, ����������

class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		multiset<int> ms0;
		multiset<int> ms1;
		multiset<int> ms2;

		for (auto& n : nums)
		{
			if ((n % 3) == 0)
			{
				ms0.insert(n);
			}
			else if ((n % 3) == 1)
			{
				ms1.insert(n);
			}
			else
			{
				ms2.insert(n);
			}
		}

		//��ѧ�⣬��������

		int ms1mod3 = ms1.size() % 3;
		int ms2mod3 = ms2.size() % 3;

		int sum = accumulate(nums.begin(), nums.end(), 0);
		int del = 0;

		if (ms1mod3 == 0)
		{
			if (ms2mod3 == 0)
			{
				;
			}
			else if (ms2mod3 == 1)
			{
				//Ҫôɾ��ms2��Сֵ, Ҫôɾ����ms1��Сֵ����еĻ�
				del = *ms2.begin();
				if (ms1.size() >= 2)
				{
					int anodel = 0;
					anodel = *ms1.begin();
					ms1.erase(ms1.begin());
					anodel += *ms1.begin();
					del = min(del, anodel);
				}
			}
			else //Ҫôɾ����ms2��Сֵ, Ҫôɾ��һms1��Сֵ����еĻ�
			{
				del = *ms2.begin();
				ms2.erase(ms2.begin());
				del += *ms2.begin();
				if (ms1.size() >= 1)
				{
					del = min(del, *ms1.begin());
				}
			}
		}
		else if (ms1mod3 == 1)
		{
			if (ms2mod3 == 0) //Ҫôɾ��ms1��Сֵ, Ҫôɾ����ms2��Сֵ����еĻ�
			{
				del = *ms1.begin();
				if (ms2.size() >= 2)
				{
					int anodel = 0;
					anodel = *ms2.begin();
					ms2.erase(ms2.begin());
					anodel += *ms2.begin();
					del = min(del, anodel);
				}
			}
			else if (ms2mod3 == 1)
			{
				; //ojbj
			}
			else //Ҫôɾ����ms1��Сֵ����еĻ�, Ҫôɾ��һms2��Сֵ
			{
				del = *ms2.begin();
				if (ms1.size() >= 2)
				{
					int anodel = 0;
					anodel = *ms1.begin();
					ms1.erase(ms1.begin());
					anodel += *ms1.begin();
					del = min(del, anodel);
				}
			}
		}
		else
		{
			if (ms2mod3 == 0) //Ҫôɾ����ms1��Сֵ, Ҫôɾ��һms2��Сֵ����еĻ�
			{
				del = *ms1.begin();
				ms1.erase(ms1.begin());
				del += *ms1.begin();
				if (ms2.size() >= 1)
				{
					del = min(del, *ms2.begin());
				}
			}
			else if (ms2mod3 == 1)  //Ҫôɾ��һ��ms1��Сֵ��Ҫôɾ������ms2��Сֵ����еĻ�
			{
				del = *ms1.begin();
				if (ms2.size() >= 2)
				{
					int anodel = 0;
					anodel = *ms2.begin();
					ms2.erase(ms2.begin());
					anodel += *ms2.begin();
					del = min(del, anodel);
				}
			}
			else
			{
				; //ojbj
			}
		}

		return sum - del;

	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums00 = { 2,6,2,2,7 };
	cout << s->maxSumDivThree(nums00) << endl;

	vector<int> nums0 = { 3,6,5,1,8 };
	cout << s->maxSumDivThree(nums0) << endl;
	vector<int> nums1 = { 4 };
	cout << s->maxSumDivThree(nums1) << endl;
	vector<int> nums2 = { 1,2,3,4,4 };
	cout << s->maxSumDivThree(nums2) << endl;
	return 0;
}
*/
