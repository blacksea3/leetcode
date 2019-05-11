#include "include.h"

#ifdef LEETCODE_141_150
#include "public.h"
#include "leetcode.h"

bool Solution::hasCycle(ListNode * head)
{
	//O(n)内存很简单
	//采用常量内存

	//来自评论:快慢指针
	if (head == nullptr) return false;

	ListNode* fast = head;
	ListNode* slow = head;

	while (true)
	{
		if (fast->next == nullptr) break;
		if (fast->next->next == nullptr) break;
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) return true;
	}
	return false;
}

ListNode * Solution::detectCycle(ListNode * head)
{
	//快慢指针

	//假设head距离环起始处为a,环长b(总节点数即为a+b)
	//快指针将提前慢指针进圈a长度,
	//如果二者同时在圈起始点开始走,那么应当在圈起始点相遇
	//现在快指针提前了a长度,那么将在距离圈起始点a处(圈内的)相遇
	//这样从相遇出的指针和起始处的指针按同样速度走a长度后将在圈起始点处相遇

	//特殊情况
	if (head == nullptr) return nullptr;

	//第一部分
	ListNode* fast = head;
	ListNode* slow = head;

	while (true)
	{
		if (fast->next == nullptr) break;
		if (fast->next->next == nullptr) break;
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) goto step2;
	}
	return nullptr;

	//第二部分
step2:
	ListNode* start = head;
	while (start != slow)
	{
		start = start->next;
		slow = slow->next;
	}
	return start;
}

void Solution::reorderList(ListNode * head)
{
	//特殊情况
	if (head == nullptr) return;
	if (head->next == nullptr) return;

	//快慢指针找到中点,分离出后半段
	ListNode* fast = head->next;
	ListNode* slow = head;

	ListNode* latterhalf;

	while (true)
	{
		if (fast->next == nullptr)
		{
			latterhalf = slow->next;
			slow->next = nullptr;
			break;
		}
		if (fast->next->next == nullptr)
		{
			latterhalf = slow->next->next;
			slow->next->next = nullptr;
			break;
		}
		fast = fast->next->next;
		slow = slow->next;
	}

	//反转后半段
	//人工拆成两个链表,不要混在一起操作
	ListNode *pre = nullptr;
	ListNode* p2 = latterhalf;
	ListNode* p3;
	while (p2)
	{
		p3 = p2->next;
		p2->next = pre;
		pre = p2;
		p2 = p3;
	}

	//后半段插入前半段,从latterhalf开始
	latterhalf = pre;
	pre = head;

	while (latterhalf)
	{
		ListNode* temp = latterhalf->next;
		latterhalf->next = pre->next;
		pre->next = latterhalf;
		latterhalf = temp;
		pre = pre->next->next;
	}
	return;
}

vector<int> Solution::preorderTraversal(TreeNode * root)
{
	//迭代
	vector<int> res = {};
	if (root == nullptr) return res;
	stack<TreeNode*> dfs;
	TreeNode* pre = root;

	while (!dfs.empty() || pre)
	{
		if (pre)
		{
			res.push_back(pre->val);
			dfs.push(pre);
			pre = pre->left;
		}
		else
		{
			pre = dfs.top();
			pre = pre->right;
			dfs.pop();
		}
	}
	return res;
}

vector<int> Solution::postorderTraversal(TreeNode * root)
{
	//倒过来,生成反-后序遍历:即根-右-左遍历顺序

	vector<int> res = {};

	if (root == nullptr) return res;

	TreeNode* pre = root;
	stack<TreeNode*> dfs;

	while (!dfs.empty() || pre)
	{
		if (pre)
		{
			res.insert(res.begin(), pre->val);
			dfs.push(pre);
			pre = pre->right;
		}
		else
		{
			pre = dfs.top();
			dfs.pop();
			pre = pre->left;
		}
	}
	return res;
}

ListNode * Solution::insertionSortList(ListNode * head)
{
	//没什么特殊的地方
	//要原地操作

	if (head == nullptr) return nullptr;
	if (head->next == nullptr) return head;

	//
	ListNode* left;
	ListNode* right = head->next;
	ListNode* right_m1 = head;    //在right的左边一格节点

	ListNode* pre;
	ListNode* returnhead = head;
	//O(n^2)时间复杂度
	while (right != nullptr)
	{
		left = returnhead;
		if (left->val >= right->val) //最左端
		{
			right_m1->next = right->next;
			returnhead = right;
			right->next = left;
		}
		else   //在中间
		{
			while (left != right_m1)
			{
				if (left->next->val >= right->val)
				{
					//将right插到left与left->next中间
					right_m1->next = right->next;
					ListNode* temp = left->next;
					left->next = right;
					right->next = temp;
					goto elseend;
				}
				else left = left->next;
			}
			//最右端,不要操作
			right_m1 = right;
		elseend:;
		}
		right = right_m1->next;
	}
	return returnhead;
}

ListNode * Solution::iter_sortList(ListNode * head)
{
	//原地算法
	//归并排序
	if (head->next == nullptr) return head;

	//用双指针切割链表
	ListNode* fast = head;
	ListNode* slow = head;

	while (true)
	{
		if ((fast->next) && (fast->next->next))
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		else break;
	}
	//slow->next为后半链表

	ListNode* lefthalf = head;
	ListNode* righthalf = slow->next;
	slow->next = nullptr;
	lefthalf = iter_sortList(lefthalf);
	righthalf = iter_sortList(righthalf);

	//合并
	ListNode* returnhead;
	ListNode* pre;
	if (lefthalf->val < righthalf->val)
	{
		returnhead = lefthalf;
		lefthalf = lefthalf->next;
	}
	else
	{
		returnhead = righthalf;
		righthalf = righthalf->next;
	}
	pre = returnhead;
	while (lefthalf && righthalf)
	{
		if (lefthalf->val < righthalf->val)
		{
			pre->next = lefthalf;
			lefthalf = lefthalf->next;
		}
		else
		{
			pre->next = righthalf;
			righthalf = righthalf->next;
		}
		pre = pre->next;
	}
	if (lefthalf) pre->next = lefthalf;
	else pre->next = righthalf;
	return returnhead;
}

ListNode * Solution::sortList(ListNode * head)
{
	if (head == nullptr) return nullptr;  //此处仅首次调用
	return iter_sortList(head);
}

pair<int, int> Solution::iter_gcd(pair<int, int> input)
{
	//害怕溢出,md
	long num1;
	long num2;
	bool isexchange = false;
	if (abs(input.first) < abs(input.second))
	{
		int temp = input.first;
		input.first = input.second;
		input.second = temp;
		isexchange = true;
	}

	if (input.first > 0)
	{
		num1 = (long)input.first;
	}
	else
	{
		num1 = -1 * (long)input.first;
	}
	if (input.second > 0)
	{
		num2 = (long)input.second;
	}
	else
	{
		num2 = -1 * (long)input.second;
	}
	long max_yueshu;
	while (true)
	{
		max_yueshu = num1 % num2;
		num1 = num2;
		num2 = max_yueshu;
		if (max_yueshu == 0) break;
	}
	if (!isexchange)
	{
		long res1 = (long)(input.first) / num1;
		long res2 = (long)(input.second) / num1;
		return pair<int, int> {int(res1), (int)res2};
	}
	else
	{
		long res1 = (long)(input.second) / num1;
		long res2 = (long)(input.first) / num1;
		return pair<int, int> {int(res1), (int)res2};
	}
}

int Solution::maxPoints(vector<vector<int>>& points)
{
	//对某个给定点,对所有点扫一次进行唯一性记录:按照斜率记录
	//记录的值将是一个pair<int a,int b>表示 a/b (a可能是任意整数,b只能是正整数)
	//init:extra = 0
	//对于与给定点重复的点,extra+=1(注意,这个值必定>=1因为所有点包含那个给定点)
	//然后对于大量的斜率,找到数量最高的就可以了
	int psize = points.size();
	if (psize <= 2) return psize;
	map<pair<int, int>, int> slice_dict;
	int maxpoints = 0;

	//正式计算
	for (int i = 0; i < psize; i++)
	{
		int extra = 0;
		int tempmaxpoints = 0;
		slice_dict.clear();
		for (int j = 0; j < psize; j++)
		{
			if ((points[i][0] == points[j][0]) && (points[i][1] == points[j][1]))
				extra++;
			else
			{
				int dx = points[i][0] - points[j][0];
				int dy = points[i][1] - points[j][1];
				if (dx == 0)
				{
					slice_dict[pair<int, int>(1, 0)] += 1;
				}
				else if (dy == 0)
				{
					slice_dict[pair<int, int>(0, 1)] += 1;
				}
				else
				{
					slice_dict[iter_gcd(pair<int, int>{dy, dx})] += 1;
				}
			}
		}
		//扫一遍slice_dict
		for (map<pair<int, int>, int>::iterator iter = slice_dict.begin(); iter != slice_dict.end(); iter++)
		{
			tempmaxpoints = max(tempmaxpoints, iter->second);
		}
		tempmaxpoints += extra;
		maxpoints = max(maxpoints, tempmaxpoints);
	}
	return maxpoints;
}

int Solution::evalRPN(vector<string>& tokens)
{
	//栈
	if (tokens.size() == 0) return 0;

	stack<int> st;

	//假设输入有效
	for (auto token : tokens)
	{
		if (token[0] >= '0') //这样就一定是数字了,详情看ASCII码表
			st.push(atoi(token.c_str()));
		else if (token[0] == '+')
		{
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			st.push(num1 + num2);
		}
		else if (token[0] == '-')
		{
			if (token.size() > 1)
			{
				st.push(atoi(token.c_str()));
			}
			else
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				st.push(num2 - num1);
			}
		}
		else if (token[0] == '*')
		{
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			st.push(num1*num2);
		}
		else
		{
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			st.push(num2 / num1);
		}
	}
	return st.top();
}

#else
#endif
