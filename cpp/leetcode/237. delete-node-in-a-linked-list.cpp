#include "listnode.h"

//8ms, 99.96%
//注意题目说是非末尾节点，那么直接用下一个节点的值替换当前值，
//再把下一个节点的下一个节点作为当前节点的next即可

class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};
