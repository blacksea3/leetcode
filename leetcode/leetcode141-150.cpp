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
#else
#endif
