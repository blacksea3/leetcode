#include "listnode.h"

//12ms, 99.80%
//注意题目说是非末尾节点，那么直接用下一个节点的值替换当前值，
//再把下一个节点的下一个节点作为当前节点的next即可

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};
