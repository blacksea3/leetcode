#include "include.h"

#ifdef LEETCODE_151_160
#include "public.h"
#include "leetcode.h"

string Solution::reverseWords(string s)
{
	int loc = s.size() - 1;
	int wordend = 0;

	bool iswording = false;   //true:当前正在读取文字

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
	if (iswording)  //添加最后一个单词
		res += s.substr(0, wordend + 1);
	else  //去除末尾空格
		res.pop_back();
	return res;
}

int Solution::maxProduct(vector<int>& nums)
{
	//存放当前的最大值和最小值
	//如果遇到0,当前最大值和最小值都等于0
	//如果遇到正数,扩展
	//如果遇到负数,交换
	int res = INT_MIN;
	int smax = 1;
	int smin = 1;
	for (auto num : nums)
	{
		if (num < 0)
		{
			int temp = 0; temp = smax; smax = smin; smin = temp; //交换
		}
		smax = max(smax*num, num);
		smin = min(smin*num, num);
		res = max(res, smax);
	}
	return res;
}

int Solution::iter_findMin(vector<int>& nums, int start, int end)
{
	//二分查找
	if (nums[start] <= nums[end]) //这里合并了了num只有一个元素的条件
		return nums[start];
	else
	{
		int mid = (start + end) / 2;  //当num长度>=2时,拆成下标start至min 与 min+1至end进行判断
		if (nums[start] <= nums[mid])
			return iter_findMin(nums, mid + 1, end);
		else
			return iter_findMin(nums, start, mid);
	}
}

int Solution::findMin(vector<int>& nums)
{
	//看起来题目绝不会输入空数组
	return iter_findMin(nums, 0, nums.size() - 1);
}

int Solution::iter_findMin_154(vector<int>& nums, int start, int end)
{
	//二分查找
	if (start == end)  //一个元素
		return nums[start];
	else
	{
		if (nums[start] < nums[end])
		{
			return nums[start];
		}
		else if (nums[start] > nums[end])
		{
			int mid = (start + end) / 2;  //当num长度>=2时,拆成下标start至min 与 min+1至end进行判断
			if (nums[start] <= nums[mid])   //形如 2 2 2 3 1或者  2 2 2 0 1都不要紧,合并进去
				return iter_findMin(nums, mid + 1, end);
			else
				return iter_findMin(nums, start, mid);
		}
		else   //要搞清楚2 3 0 1 2或者 2 2 2 2 2 或者 2 3 4 1 2
		{
			//简单点,O(n)遍历吧
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
	//遍历读取长度

	ListNode* lnA = headA;
	ListNode* lnB = headB;
	int abs = 0;  //计数

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
		//从头开始先跑一段
		while (abs-- != 0)
			lnB = lnB->next;
	}
	else if (lnA)
	{
		lnA = lnA->next;
		abs++;
		lnA = headA;
		lnB = headB;
		//从头开始先跑一段
		while (abs-- != 0)
			lnA = lnA->next;
	}
	else;

	//从头开始跑
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
