#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_91_100

int Solution::numDecodings(string s)
{
	//一轮扫描

	//记录上一个字母
	//a(n) = a(n-1)(如果当前字母不是'0') + (如果上一个字母和当前字母可以合并)a(n-2)
	//注意如果当前字母是'0',上一个字母还不能合并,直接返回0

	//初始化以及特殊情况
	int slen = s.size();

	int an = 0;
	int an_ad1 = 0;
	an = (s[0] != '0') ? 1 : 0;
	if (slen == 1) return an;
	if (an == 0) return 0;

	if ((s[0] == '1') || (s[0] == '2') && (s[1] <= '6')) an_ad1 = 2;
	else an_ad1 = 1;

	bool is_ad1_bigger = true;   //是否an_ad1比an大,是就true

	//主循环部分,两个an来回操作
	for (int i = 2; i < slen; i++)
	{
		if (is_ad1_bigger)
		{
			if (s[i] == '0')
			{
				if ((s[i - 1] != '1') && (s[i - 1] != '2')) return 0;
				else
				{
					//an = an;
					is_ad1_bigger = false;
				}
			}
			else
			{
				if ((s[i - 1] == '1') || (s[i - 1] == '2') && (s[i] <= '6'))
				{
					an = an + an_ad1;
					is_ad1_bigger = false;
				}
				else
				{
					an = an_ad1;
					is_ad1_bigger = false;
				}
			}
		}
		else
		{
			if (s[i] == '0')
			{
				if ((s[i - 1] != '1') && (s[i - 1] != '2')) return 0;
				else
				{
					//an = an;
					is_ad1_bigger = true;
				}
			}
			else
			{
				if ((s[i - 1] == '1') || (s[i - 1] == '2') && (s[i] <= '6'))
				{
					an_ad1 = an_ad1 + an;
					is_ad1_bigger = true;
				}
				else
				{
					an_ad1 = an;
					is_ad1_bigger = true;
				}
			}
		}
	}

	return (is_ad1_bigger) ? an_ad1 : an;
}

ListNode * Solution::reverseBetween(ListNode * head, int m, int n)
{
	if (m == n) return head;

	//一遍扫描
	ListNode *dump = new ListNode(0);
	dump->next = head;
	int loc = 0;
	ListNode *left = dump;
	ListNode * right = dump;
	bool isstart = false;
	ListNode *preln = dump;
	while (loc < n)
	{
		if (!isstart)
		{
			if ((loc + 1) == m)
			{
				left = preln;
				isstart = true;
			}
			loc++;
			preln = preln->next;
		}
		else
		{
			right = preln;  //实际上是left->next与right->next交换
			// 1->3->2->4->5  left:1 right:2
			ListNode *temp = left->next;
			left->next = right->next;
			right->next = left->next->next;
			left->next->next = temp;

			loc++;
		}
	}
	return dump->next;
}

#else
#endif

