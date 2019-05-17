#include "include.h"

#ifdef LEETCODE_201_210
#include "public.h"
#include "leetcode.h"

int Solution::rangeBitwiseAnd(int m, int n)
{
	//确定最高位
	int loc = 31;
	m <<= 1;
	n <<= 1;
	while (true)
	{
		if (m & 0x80000000)
			if (n & 0x80000000)
			{
				break;
			}
			else
				return 0;
		else if (n & 0x80000000)
			return 0;
		else
		{
			loc--;
			m <<= 1;
			n <<= 1;
		}
		if (loc == 0) return 0;
	}

	//此时的loc为公共的最高位，最低位的loc是1，且当前的m与n最高位已经移动到了loc处(位移动)

	int res = 0;

	while (true)
	{
		if (m & 0x80000000)
			if (n & 0x80000000)
			{
				m &= 0x7fffffff;
				n &= 0x7fffffff;
				res <<= 1;
				res |= 1;
			}
			else
				break;
		else if (n & 0x80000000)
			break;
		else
		{
			res <<= 1;
		}
		loc--;
		m <<= 1;
		n <<= 1;
		if (loc == 0) return res;
	}
	res <<= loc;

	return res;


}

int Solution::getsquaresum_202(int n)
{
	int res = 0;
	while (n > 0)
	{
		res += (n % 10)*(n % 10);
		n /= 10;
	}
	return res;
}

bool Solution::isHappy(int n)
{
	//朴素的方法,如果当前平方和已经历史上存在过,那么不是快乐数
	//如果当前平方和为1则是快乐数
	//否则循环
	unordered_set<int> his;

	while (true)
	{
		int temp = getsquaresum_202(n);
		if (temp == 1) return true;
		else if (his.find(temp) == his.end()) his.insert(temp);
		else break;
		n = temp;
	}
	return false;
}

ListNode * Solution::removeElements(ListNode * head, int val)
{
	//朴素的操作
	ListNode* dump = new ListNode(0);
	dump->next = head;
	ListNode* returnd = dump;

	while ((dump) && (dump->next))
	{
		if (dump->next->val == val)
		{
			dump->next = dump->next->next;
		}
		else
		{
			dump = dump->next;
		}
	}
	return returnd->next;
}

int Solution::countPrimes(int n)
{
	//暴力计算?
	int res = 1;
	if (n <= 2) return 0;
	//仅对小于根号n的奇数的奇数倍进行判断

	//注意:i*j也许会溢出,但我想这题目不会给那么大的n吧,这时间复杂度很大的
	for (int i = 3; i < n; i += 2)
	{
		for (int j = 3; j <= sqrt(i); j += 2)
		{
			if (i%j == 0)
			{
				goto continuebig;
				break;
			}
		}
		res++;
	continuebig:;
	}

	return res;
}

bool Solution::isIsomorphic(string s, string t)
{
	//维护两个转换表就可以
	unordered_map<char, char> um;
	unordered_map<char, char> um_r;

	if (s.size() != t.size()) return false;
	for (int i = 0; i < s.size(); i++)
	{
		if (um.find(s[i]) == um.end())
		{
			if (um_r.find(t[i]) == um_r.end())
			{
				um[s[i]] = t[i];
				um_r[t[i]] = s[i];
			}
			else
			{
				return false;
			}
		}
		else if (um_r.find(t[i]) == um_r.end())
			return false;
		else
		{
			//注意自映射问题
			if ((s[i] == t[i]) && (um[s[i]] != s[i])) return false;
			else if ((s[i] != t[i]) && (um[s[i]] == s[i])) return false;
			else continue;
		}
	}
	return true;
}

ListNode * Solution::reverseList(ListNode * head)
{
	ListNode* left = nullptr;
	ListNode* right = head;
	ListNode* temp;

	while (right)
	{
		temp = right;
		right = right->next;
		temp->next = left;
		left = temp;
	}
	return left;
}

bool Solution::canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	if (numCourses == 0) return true;

	//拓扑排序
	struct Node { int indegree = 0; vector<int> nexts = {}; };  //包含入度以及下一节点,值就是vector的下标

	//init节点们/入度为0的节点进stack
	stack<int> st;
	vector<Node> courses(numCourses, Node());
	int num_of_removed_nodes = 0;

	for (auto prere : prerequisites)
	{
		courses[prere[1]].nexts.push_back(prere[0]);
		courses[prere[0]].indegree++;
	}
	for (int i = 0; i < numCourses; i++)
		if (courses[i].indegree == 0) st.push(i);

	//拆分节点
	while (!st.empty())
	{
		int prenodeid = st.top();
		st.pop();
		num_of_removed_nodes++;
		for (auto nextnodeid : courses[prenodeid].nexts)
		{
			if (--courses[nextnodeid].indegree == 0)
				st.push(nextnodeid);
		}
	}
	return (num_of_removed_nodes == numCourses);
}

int Solution::minSubArrayLen(int s, vector<int>& nums)
{
	//直接来O(n)解法
	//滑动窗口
	queue<int> pre;
	int presum = 0;
	int loc = 0;
	int minlen = INT_MAX;
	while (loc < nums.size())
	{
		pre.push(nums[loc]);
		presum += nums[loc];
		if (presum >= s)
		{
			while (presum >= s)
			{
				presum -= pre.front();
				pre.pop();
			}
			minlen = (pre.size() + 1 < minlen) ? pre.size() + 1 : minlen;
		}
		++loc;
	}
	//按理来说,minlen不会真的是INT_MAX吧,...
	return (minlen != INT_MAX) ? minlen : 0;
}

vector<int> Solution::findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
	//复用207题
	if (numCourses == 0) return vector<int> {};

	//拓扑排序
	struct Node { int indegree = 0; vector<int> nexts = {}; };  //包含入度以及下一节点,值就是vector的下标

	//init节点们/入度为0的节点进stack
	stack<int> st;
	vector<Node> courses(numCourses, Node());
	vector<int> res = {};
	int num_of_removed_nodes = 0;

	for (auto prere : prerequisites)
	{
		courses[prere[1]].nexts.push_back(prere[0]);
		courses[prere[0]].indegree++;
	}
	for (int i = 0; i < numCourses; i++)
		if (courses[i].indegree == 0) st.push(i);

	//拆分节点
	while (!st.empty())
	{
		int prenodeid = st.top();
		res.push_back(prenodeid);
		st.pop();
		num_of_removed_nodes++;
		for (auto nextnodeid : courses[prenodeid].nexts)
		{
			if (--courses[nextnodeid].indegree == 0)
				st.push(nextnodeid);
		}
	}
	return (num_of_removed_nodes == numCourses) ? res : vector<int>{};
}

#else
#endif
