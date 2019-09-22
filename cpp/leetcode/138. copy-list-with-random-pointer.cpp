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
//三轮操作, 详情看注释

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* pre = head;
        
        //第一轮复制,给每个节点复制到自己的后面
        while (pre != nullptr)
        {
            Node* newn = new Node(pre->val, pre->next, nullptr);
            pre->next = newn;
            pre = newn->next;
        }
        
        //第二轮复制,查找每个原始节点(认为是奇数节点),得出random,然后把复制节点(认为是偶数节点)的random指向原始节点random的后面(就是一个random复制节点)
        pre = head;
        while (pre != nullptr)
        {
            if (pre->random)
                pre->next->random = pre->random->next;
            pre = pre->next->next;
        }
        
        //第三轮,拆出复制节点
        Node* returnhead = head->next;
        pre = head;
        while (pre->next != nullptr)
        {
            Node* temp = pre->next;
            pre->next = pre->next->next;
            pre = temp;
        }
		return returnhead;
    }
};
