#include "include.h"

#ifdef LEETCODE_141_150
#include "public.h"
#include "leetcode.h"

bool Solution::hasCycle(ListNode * head)
{
	//O(n)�ڴ�ܼ�
	//���ó����ڴ�

	//��������:����ָ��
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
	//����ָ��

	//����head���뻷��ʼ��Ϊa,����b(�ܽڵ�����Ϊa+b)
	//��ָ�뽫��ǰ��ָ���Ȧa����,
	//�������ͬʱ��Ȧ��ʼ�㿪ʼ��,��ôӦ����Ȧ��ʼ������
	//���ڿ�ָ����ǰ��a����,��ô���ھ���Ȧ��ʼ��a��(Ȧ�ڵ�)����
	//��������������ָ�����ʼ����ָ�밴ͬ���ٶ���a���Ⱥ���Ȧ��ʼ�㴦����

	//�������
	if (head == nullptr) return nullptr;

	//��һ����
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

	//�ڶ�����
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
	//�������
	if (head == nullptr) return;
	if (head->next == nullptr) return;

	//����ָ���ҵ��е�,���������
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

	//��ת����
	//�˹������������,��Ҫ����һ�����
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

	//���β���ǰ���,��latterhalf��ʼ
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
	//����
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
	//������,���ɷ�-�������:����-��-�����˳��

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
	//ûʲô����ĵط�
	//Ҫԭ�ز���

	if (head == nullptr) return nullptr;
	if (head->next == nullptr) return head;

	//
	ListNode* left;
	ListNode* right = head->next;
	ListNode* right_m1 = head;    //��right�����һ��ڵ�

	ListNode* pre;
	ListNode* returnhead = head;
	//O(n^2)ʱ�临�Ӷ�
	while (right != nullptr)
	{
		left = returnhead;
		if (left->val >= right->val) //�����
		{
			right_m1->next = right->next;
			returnhead = right;
			right->next = left;
		}
		else   //���м�
		{
			while (left != right_m1)
			{
				if (left->next->val >= right->val)
				{
					//��right�嵽left��left->next�м�
					right_m1->next = right->next;
					ListNode* temp = left->next;
					left->next = right;
					right->next = temp;
					goto elseend;
				}
				else left = left->next;
			}
			//���Ҷ�,��Ҫ����
			right_m1 = right;
		elseend:;
		}
		right = right_m1->next;
	}
	return returnhead;
}

ListNode * Solution::iter_sortList(ListNode * head)
{
	//ԭ���㷨
	//�鲢����
	if (head->next == nullptr) return head;

	//��˫ָ���и�����
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
	//slow->nextΪ�������

	ListNode* lefthalf = head;
	ListNode* righthalf = slow->next;
	slow->next = nullptr;
	lefthalf = iter_sortList(lefthalf);
	righthalf = iter_sortList(righthalf);

	//�ϲ�
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
	if (head == nullptr) return nullptr;  //�˴����״ε���
	return iter_sortList(head);
}

pair<int, int> Solution::iter_gcd(pair<int, int> input)
{
	//�������,md
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
	//��ĳ��������,�����е�ɨһ�ν���Ψһ�Լ�¼:����б�ʼ�¼
	//��¼��ֵ����һ��pair<int a,int b>��ʾ a/b (a��������������,bֻ����������)
	//init:extra = 0
	//������������ظ��ĵ�,extra+=1(ע��,���ֵ�ض�>=1��Ϊ���е�����Ǹ�������)
	//Ȼ����ڴ�����б��,�ҵ�������ߵľͿ�����
	int psize = points.size();
	if (psize <= 2) return psize;
	map<pair<int, int>, int> slice_dict;
	int maxpoints = 0;

	//��ʽ����
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
		//ɨһ��slice_dict
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
	//ջ
	if (tokens.size() == 0) return 0;

	stack<int> st;

	//����������Ч
	for (auto token : tokens)
	{
		if (token[0] >= '0') //������һ����������,���鿴ASCII���
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
