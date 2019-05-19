#pragma once

#include "public.h"

/**
 * Definition for singly-linked list.*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printlistnode(ListNode* input)
{
	while (input != NULL)
	{
		cout << input->val;
		input = input->next;
	}
	cout << endl;
}

//input 至少应含有一个元素
ListNode* initlistnode(vector<int> input)
{
	ListNode* return_ln = new ListNode(NULL);
	ListNode* old_ln = return_ln;
	for (vector<int>::const_iterator iter = input.cbegin(); iter != input.cend(); iter++)
	{
		ListNode* new_ln = new ListNode((*iter));
		old_ln->next = new_ln;
		old_ln = new_ln;
	}

	return return_ln->next;
}