#include "listnode.h"

//8ms, 99.96%
//ע����Ŀ˵�Ƿ�ĩβ�ڵ㣬��ôֱ������һ���ڵ��ֵ�滻��ǰֵ��
//�ٰ���һ���ڵ����һ���ڵ���Ϊ��ǰ�ڵ��next����

class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};
