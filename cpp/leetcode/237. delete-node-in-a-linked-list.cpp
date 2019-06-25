#include "listnode.h"

//12ms, 99.80%
//ע����Ŀ˵�Ƿ�ĩβ�ڵ㣬��ôֱ������һ���ڵ��ֵ�滻��ǰֵ��
//�ٰ���һ���ڵ����һ���ڵ���Ϊ��ǰ�ڵ��next����

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
