#include "include.h"

#ifdef LEETCODE_21_30
#include "public.h"
#include "leetcode.h"
ListNode * Solution::mergeTwoLists(ListNode * l1, ListNode * l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	//不要泄露内存
	//下面俩ListNode都存在
	ListNode* head;
	//确定ListNode头
	if (l1->val >= l2->val)
	{
		ListNode* temp = new ListNode(l2->val);
		head = temp;
		l2 = l2->next;
	}
	else
	{
		ListNode* temp = new ListNode(l1->val);
		head = temp;
		l1 = l1->next;
	}

	ListNode* iter = head;
	//双遍历
	while ((l1 != NULL) && (l2 != NULL))
	{
		if (l1->val >= l2->val)
		{
			iter->next = new ListNode(l2->val);
			l2 = l2->next;
			iter = iter->next;
		}
		else
		{
			iter->next = new ListNode(l1->val);
			l1 = l1->next;
			iter = iter->next;
		}
	}

	//一定有某个链表有剩下的
	if (l1 == NULL) iter->next = l2;
	else iter->next = l1;

	return head;
}

vector<string> Solution::generateParenthesis(int n)
{
	/*
	#注意到:所有的n个括号组合均可以进行以下拆减:
	#取出最左边的左括号与其相对应的右括号(成为括号组A),这将留下两个可能的括号组合,
	#一个在A的中间,一个在A的右边;并且一个的括号数量为i(i=[0,n-1]),另一个为n-1-i.它们都是有效的括号组合
	#   它们分别可以通过遍历数量为i与数量为n-1-i的括号组合得到

	#最终可以递归这个过程
	*/

	//我们应当保存下来所有括号对数为1至n-1的vector,供迭代

	if (n == 0) return vector<string> {};
	if (n == 1) return vector<string> {"()"};

	vector<vector<string>> all_parenthesis = { {},{"()"} }; //根据下标获得所有可能的括号

	for (int i = 2; i <= n; ++i)
	{
		vector<string> temp = {};
		for (int m = 0; m < all_parenthesis[i - 1].size(); ++m)
		{
			temp.push_back("()" + all_parenthesis[i - 1][m]);
			temp.push_back("(" + all_parenthesis[i - 1][m] + ')');
		}

		for (int j = 1; j <= i - 2; ++j)   //双遍历all_parenthesis[j], all_parenthesis[i - 1 - j]
		{
			for (int k = 0; k < all_parenthesis[j].size(); ++k)
			{
				for (int l = 0; l < all_parenthesis[i - 1 - j].size(); ++l)
				{
					temp.push_back("(" + all_parenthesis[j][k] + ")" + all_parenthesis[i - 1 - j][l]);
				}
			}
		}
		all_parenthesis.push_back(temp);
	}
	return all_parenthesis[n];
}

//外部需要确保startloc<=endloc
//合并Klists, 根据下标范围[startloc, endloc]
ListNode * Solution::iter_mergeKLists(vector<ListNode*>& lists, int startloc, int endloc)
{
	if (endloc == startloc) return lists[startloc];
	else if ((endloc - startloc) == 1) return mergeTwoLists(lists[startloc], lists[endloc]);
	else
	{
		int middle = (startloc + endloc) / 2;  //here startloc1 - startloc2 >= 2
		return mergeTwoLists(iter_mergeKLists(lists, startloc, middle - 1),
			iter_mergeKLists(lists, middle, endloc));
	}
}

ListNode * Solution::mergeKLists(vector<ListNode*>& lists)
{
	if (lists.size() == 0) return nullptr;

	return iter_mergeKLists(lists, 0, lists.size() - 1);
}

ListNode * Solution::swapPairs(ListNode * head)
{
	//双指针
	//特殊情况,head=None
	if (head == NULL) return nullptr;

	//  dump->1->2  =>      a=dump, b=2  =>     a.next.next=b.next;  b.next=a.next;  a.next=b;

	ListNode* first;
	ListNode* second;
	ListNode* dump = new ListNode(0);  //dump
	dump->next = head;

	//init
	first = dump;
	second = head->next;

	while (second != NULL)
	{
		first->next->next = second->next;
		second->next = first->next;
		first->next = second;
		if (second->next->next == NULL) break;
		first = second->next;
		second = second->next->next->next;
	}

	ListNode* returnln = dump->next;
	delete dump;
	return returnln;
}

ListNode * Solution::reverseKGroup(ListNode * head, int k)
{
	//先搞清楚长度
	int length = 0;
	ListNode* dump = new ListNode(0);  //dump
	dump->next = head;
	while (head != NULL)
	{
		head = head->next;
		length++;
	}
	//k=1特殊情况
	if (k == 1)
	{
		ListNode* returnln = dump->next;
		delete dump;
		return returnln;
	}

	//init first and second ptr
	if (length >= k)
	{
		//实际操作    //none:dump, first:1, second:2   1->2->3
		// =>      2->1->3,   first = 1 will not move, second = 2 will move to first->next, none not move
		// =>      ......
		ListNode* iter_head = dump;
		ListNode* first;
		ListNode* second;
		ListNode* none;
		while (length >= k)
		{
			first = iter_head->next;
			second = iter_head->next->next;
			none = iter_head;
			for (int i = 1; i < k; i++)
			{
				first->next = second->next;
				second->next = none->next;
				none->next = second;
				second = first->next;
			}
			length -= k;
			iter_head = first;
		}
	}

	ListNode* returnln = dump->next;
	delete dump;
	return returnln;
}

int Solution::removeDuplicates(vector<int>& nums)
{
	//一轮遍历
	int nsize = nums.size();
	if (nsize == 0) return 0;  //特殊情况

	int abs_move = 0;
	int old_num = nums[0] + 1;        //dump init value, 只要和nums[0]不一样就可以
	for (int i = 0; i < nsize; i++)
	{
		if (nums[i] != old_num)
		{
			old_num = nums[i];
			nums[i - abs_move] = nums[i];
		}
		else
		{
			abs_move++;
		}
	}
	return (nsize - abs_move);
}

int Solution::removeElement(vector<int>& nums, int val)
{
	//一轮遍历
	int nsize = nums.size();
	if (nsize == 0) return 0; //特殊情况

	int pre_loc = 0;

	for (int i = 0; i < nsize; i++)
	{
		if (nums[i] != val) nums[pre_loc++] = nums[i];
	}
	return pre_loc;
}

//得到下一个指针位置,详情见KMP算法,
//外部必须确保0<=j<needle.size() 
int Solution::strStr_next(string needle, int j)
{
	vector<int> next(j+1);
	next[0] = -1;
	int k = -1;
	int iterloc = 0;

	while (iterloc < j)
	{
		if ((k == -1) || (needle[k] == needle[iterloc]))
		{
			iterloc++;
			k++;
			next[iterloc] = k;
		}
		else k = next[k];
	}
	return next[j];
}

int Solution::strStr(string haystack, string needle)
{
	//使用KMP算法
	if (needle == "") return 0;
	if (haystack.size() < needle.size()) return -1;

	int i = 0;
	int j = 0;
	int jmax = needle.size() - 1;
	while (true)
	{
		if (i == haystack.size()) break;
		if (haystack[i] == needle[j])
		{
			if (j == jmax) return i - jmax;
			else
			{
				j++;
				i++;
			}
		}
		else
		{
			int resj = strStr_next(needle, j);
			if (resj == -1)
			{
				j = 0;
				i++;
			}
			else j = resj;
		}
	}

	return -1;
}

#define LIMIT 0x80000000

int Solution::divide(int dividend, int divisor)
{
	//特殊情况
	if ((dividend == INT_MIN) && (divisor == -1)) return (INT_MAX);

	bool ispositive;
	if (dividend < 0)
		if (divisor < 0) ispositive = true;
		else ispositive = false;
	else
		if (divisor < 0) ispositive = false;
		else ispositive = true;

	unsigned int n_dividend = (dividend == INT_MIN) ? LIMIT : abs(dividend);
	unsigned int n_divisor = (divisor == INT_MIN) ? LIMIT : abs(divisor);

	unsigned int res = 0;
	for (int i = 31; i >= 0; i--)
	{
		if ((n_dividend >> i) >= n_divisor)  //避免溢出,不要直接divisor<<i
		{
			n_dividend -= (n_divisor << i);
			res += (1 << i);
		}
	}
	if (res == LIMIT) return INT_MIN; //特殊情况
	else return (ispositive) ? (int)res : -1 * (int)res;
}

vector<int> Solution::findSubstring(string s, vector<string>& words)
{
	//对起始位置分组找
	int wsize = words.size();
	if (wsize == 0) return vector<int> {};  //fuck special condition
	int iter_length = words[0].size();
	if (iter_length == 0) return vector<int> {}; //fuck special condition

	int ssize = s.size();
	if (ssize < iter_length) return vector<int> {};

	//技巧,unordered_map如果没有某个键值对,那么可认为所有键对应的初始化值为0
	//在以下的通过字符串分类计数中,可以直接allwords[words[i]] += 1;,不用考虑words[i]是否为键

	//init map
	unordered_map<string, int> allwords = {};
	for (int i = 0; i < wsize; i++)
	{
		allwords[words[i]] += 1;
		//if (allwords.find(words[i]) != allwords.end()) allwords.insert(pair<string, int> {words[i], 1});
		//else allwords[words[i]] += 1;
	}

	//find locs
	vector<int> returnv = {};
	for (int i = 0; i < iter_length; i++)
	{
		unordered_map<string, int> findwords = {};
		int find_words_number = 0;
		for (int j = 0; j <= (ssize - i - (wsize - find_words_number)* iter_length) / iter_length; j++)
		{
			string pre_str = s.substr(i + j * iter_length, iter_length);
			if (allwords.find(pre_str) != allwords.end())
			{
				findwords[pre_str] += 1;
				find_words_number++;
				if (findwords[pre_str] > allwords[pre_str])
				{
					while (true)
					{
						string oldstr = s.substr(i + (j - find_words_number + 1)*iter_length, iter_length);
						findwords[oldstr] -= 1;
						find_words_number--;
						if (oldstr == pre_str) break;
					}
				}
				else
				{
					if (find_words_number == wsize)
					{
						returnv.push_back(i + (j - find_words_number + 1)*iter_length);
						//已匹配,那么我就去掉第一个元素
						findwords[s.substr(i + (j - find_words_number + 1)*iter_length, iter_length)] -= 1;
						find_words_number--;
					}
				}
			}
			else
			{
				//重置
				findwords = {};
				find_words_number = 0;
			}
		}
	}
	return returnv;
}
#else
#endif
