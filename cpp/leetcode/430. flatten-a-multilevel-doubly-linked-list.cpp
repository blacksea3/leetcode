#include "public.h"

//200ms, 39.37%
//ջ

// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution {
public:
	Node* flatten(Node* head) {
		stack<Node*> st;
		Node* pre = head;

		while (pre)
		{
			if (pre->child)
			{
				if (pre->next) st.push(pre->next);
				pre->next = pre->child;
				pre->child->prev = pre;
				Node* temp = pre->child;
				pre->child = nullptr;
				pre = temp;
			}
			else if (pre->next)
			{
				pre = pre->next;
			}
			else
			{
				if (!st.empty())
				{
					Node* temp = st.top();
					pre->next = temp;
					temp->prev = pre;
					pre = temp;
					st.pop();
				}
				else pre = nullptr;
			}
		}
		return head;
	}
};
