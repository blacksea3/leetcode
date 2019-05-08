#include "include.h"

#ifdef LEETCODE_21_30
#include "public.h"
#include "leetcode.h"
ListNode * Solution::mergeTwoLists(ListNode * l1, ListNode * l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	//��Ҫй¶�ڴ�
	//������ListNode������
	ListNode* head;
	//ȷ��ListNodeͷ
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
	//˫����
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

	//һ����ĳ��������ʣ�µ�
	if (l1 == NULL) iter->next = l2;
	else iter->next = l1;

	return head;
}

vector<string> Solution::generateParenthesis(int n)
{
	/*
	#ע�⵽:���е�n��������Ͼ����Խ������²��:
	#ȡ������ߵ��������������Ӧ��������(��Ϊ������A),�⽫�����������ܵ��������,
	#һ����A���м�,һ����A���ұ�;����һ������������Ϊi(i=[0,n-1]),��һ��Ϊn-1-i.���Ƕ�����Ч���������
	#   ���Ƿֱ����ͨ����������Ϊi������Ϊn-1-i��������ϵõ�

	#���տ��Եݹ��������
	*/

	//����Ӧ�����������������Ŷ���Ϊ1��n-1��vector,������

	if (n == 0) return vector<string> {};
	if (n == 1) return vector<string> {"()"};

	vector<vector<string>> all_parenthesis = { {},{"()"} }; //�����±������п��ܵ�����

	for (int i = 2; i <= n; ++i)
	{
		vector<string> temp = {};
		for (int m = 0; m < all_parenthesis[i - 1].size(); ++m)
		{
			temp.push_back("()" + all_parenthesis[i - 1][m]);
			temp.push_back("(" + all_parenthesis[i - 1][m] + ')');
		}

		for (int j = 1; j <= i - 2; ++j)   //˫����all_parenthesis[j], all_parenthesis[i - 1 - j]
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

//�ⲿ��Ҫȷ��startloc<=endloc
//�ϲ�Klists, �����±귶Χ[startloc, endloc]
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
	//˫ָ��
	//�������,head=None
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
	//�ȸ��������
	int length = 0;
	ListNode* dump = new ListNode(0);  //dump
	dump->next = head;
	while (head != NULL)
	{
		head = head->next;
		length++;
	}
	//k=1�������
	if (k == 1)
	{
		ListNode* returnln = dump->next;
		delete dump;
		return returnln;
	}

	//init first and second ptr
	if (length >= k)
	{
		//ʵ�ʲ���    //none:dump, first:1, second:2   1->2->3
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
	//һ�ֱ���
	int nsize = nums.size();
	if (nsize == 0) return 0;  //�������

	int abs_move = 0;
	int old_num = nums[0] + 1;        //dump init value, ֻҪ��nums[0]��һ���Ϳ���
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
	//һ�ֱ���
	int nsize = nums.size();
	if (nsize == 0) return 0; //�������

	int pre_loc = 0;

	for (int i = 0; i < nsize; i++)
	{
		if (nums[i] != val) nums[pre_loc++] = nums[i];
	}
	return pre_loc;
}

//�õ���һ��ָ��λ��,�����KMP�㷨,
//�ⲿ����ȷ��0<=j<needle.size() 
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
	//ʹ��KMP�㷨
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
	//�������
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
		if ((n_dividend >> i) >= n_divisor)  //�������,��Ҫֱ��divisor<<i
		{
			n_dividend -= (n_divisor << i);
			res += (1 << i);
		}
	}
	if (res == LIMIT) return INT_MIN; //�������
	else return (ispositive) ? (int)res : -1 * (int)res;
}

vector<int> Solution::findSubstring(string s, vector<string>& words)
{
	//����ʼλ�÷�����
	int wsize = words.size();
	if (wsize == 0) return vector<int> {};  //fuck special condition
	int iter_length = words[0].size();
	if (iter_length == 0) return vector<int> {}; //fuck special condition

	int ssize = s.size();
	if (ssize < iter_length) return vector<int> {};

	//����,unordered_map���û��ĳ����ֵ��,��ô����Ϊ���м���Ӧ�ĳ�ʼ��ֵΪ0
	//�����µ�ͨ���ַ������������,����ֱ��allwords[words[i]] += 1;,���ÿ���words[i]�Ƿ�Ϊ��

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
						//��ƥ��,��ô�Ҿ�ȥ����һ��Ԫ��
						findwords[s.substr(i + (j - find_words_number + 1)*iter_length, iter_length)] -= 1;
						find_words_number--;
					}
				}
			}
			else
			{
				//����
				findwords = {};
				find_words_number = 0;
			}
		}
	}
	return returnv;
}
#else
#endif
