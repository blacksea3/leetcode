#include "include.h"

#ifdef LEETCODE_151_160
#include "public.h"
#include "leetcode.h"

string Solution::reverseWords(string s)
{
	int loc = s.size() - 1;
	int wordend = 0;

	bool iswording = false;   //true:��ǰ���ڶ�ȡ����

	string res = "";

	while (loc >= 0)
	{
		if (iswording)
		{
			if (s[loc] == ' ')
			{
				res += s.substr(loc + 1, wordend - loc);
				res += " ";
				iswording = false;
			}
		}
		else
		{
			if (s[loc] != ' ')
			{
				iswording = true;
				wordend = loc;
			}
		}
		loc--;
	}
	if (iswording)  //������һ������
		res += s.substr(0, wordend + 1);
	else  //ȥ��ĩβ�ո�
		res.pop_back();
	return res;
}

int Solution::maxProduct(vector<int>& nums)
{
	//��ŵ�ǰ�����ֵ����Сֵ
	//�������0,��ǰ���ֵ����Сֵ������0
	//�����������,��չ
	//�����������,����
	int res = INT_MIN;
	int smax = 1;
	int smin = 1;
	for (auto num : nums)
	{
		if (num < 0)
		{
			int temp = 0; temp = smax; smax = smin; smin = temp; //����
		}
		smax = max(smax*num, num);
		smin = min(smin*num, num);
		res = max(res, smax);
	}
	return res;
}

int Solution::iter_findMin(vector<int>& nums, int start, int end)
{
	//���ֲ���
	if (nums[start] <= nums[end]) //����ϲ�����numֻ��һ��Ԫ�ص�����
		return nums[start];
	else
	{
		int mid = (start + end) / 2;  //��num����>=2ʱ,����±�start��min �� min+1��end�����ж�
		if (nums[start] <= nums[mid])
			return iter_findMin(nums, mid + 1, end);
		else
			return iter_findMin(nums, start, mid);
	}
}

int Solution::findMin(vector<int>& nums)
{
	//��������Ŀ���������������
	return iter_findMin(nums, 0, nums.size() - 1);
}

int Solution::iter_findMin_154(vector<int>& nums, int start, int end)
{
	//���ֲ���
	if (start == end)  //һ��Ԫ��
		return nums[start];
	else
	{
		if (nums[start] < nums[end])
		{
			return nums[start];
		}
		else if (nums[start] > nums[end])
		{
			int mid = (start + end) / 2;  //��num����>=2ʱ,����±�start��min �� min+1��end�����ж�
			if (nums[start] <= nums[mid])   //���� 2 2 2 3 1����  2 2 2 0 1����Ҫ��,�ϲ���ȥ
				return iter_findMin(nums, mid + 1, end);
			else
				return iter_findMin(nums, start, mid);
		}
		else   //Ҫ�����2 3 0 1 2���� 2 2 2 2 2 ���� 2 3 4 1 2
		{
			//�򵥵�,O(n)������
			for (int i = start; i <= end; i++)
			{
				if (nums[i] < nums[start])
					return nums[i];
				else if (nums[i] > nums[start])
				{
					return iter_findMin(nums, i, end);
				}
				else;
			}
			return nums[start];
		}
	}
}

int Solution::findMin_154(vector<int>& nums)
{
	return iter_findMin(nums, 0, nums.size() - 1);
}

ListNode * Solution::getIntersectionNode(ListNode * headA, ListNode * headB)
{
	//������ȡ����

	ListNode* lnA = headA;
	ListNode* lnB = headB;
	int abs = 0;  //����

	while (true)
	{
		if ((lnB) && (lnA))
		{
			lnB = lnB->next;
			lnA = lnA->next;
		}
		else
			break;
	}
	if (lnB)
	{
		lnB = lnB->next;
		abs++;
		lnA = headA;
		lnB = headB;
		//��ͷ��ʼ����һ��
		while (abs-- != 0)
			lnB = lnB->next;
	}
	else if (lnA)
	{
		lnA = lnA->next;
		abs++;
		lnA = headA;
		lnB = headB;
		//��ͷ��ʼ����һ��
		while (abs-- != 0)
			lnA = lnA->next;
	}
	else;

	//��ͷ��ʼ��
	while (true)
	{
		if (lnB == lnA)
			return lnB;
		else if ((lnB) && (lnA))
		{
			lnB = lnB->next;
			lnA = lnA->next;
		}
		else
			break;
	}
	return nullptr;
}

#else
#endif
