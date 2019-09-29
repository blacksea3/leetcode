#include "public.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

//32ms, 99.76%
//���ֲ���, ���鿴ע��

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* pre = head;
        
        //��һ�ָ���,��ÿ���ڵ㸴�Ƶ��Լ��ĺ���
        while (pre != nullptr)
        {
            Node* newn = new Node(pre->val, pre->next, nullptr);
            pre->next = newn;
            pre = newn->next;
        }
        
        //�ڶ��ָ���,����ÿ��ԭʼ�ڵ�(��Ϊ�������ڵ�),�ó�random,Ȼ��Ѹ��ƽڵ�(��Ϊ��ż���ڵ�)��randomָ��ԭʼ�ڵ�random�ĺ���(����һ��random���ƽڵ�)
        pre = head;
        while (pre != nullptr)
        {
            if (pre->random)
                pre->next->random = pre->random->next;
            pre = pre->next->next;
        }
        
        //������,������ƽڵ�
		Node* ptr_old_list = head;         // A->B->C
		Node* ptr_new_list = head->next;   // A'->B'->C'
		Node* returnhead = ptr_new_list;
		while (ptr_old_list) {
			ptr_old_list->next = ptr_old_list->next->next;
			ptr_new_list->next = (ptr_new_list->next) ? ptr_new_list->next->next : nullptr;
			ptr_old_list = ptr_old_list->next;
			ptr_new_list = ptr_new_list->next;
		}

		return returnhead;
    }
};
