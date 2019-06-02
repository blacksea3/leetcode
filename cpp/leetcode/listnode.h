#pragma once

#include "public.h"

/**
 * Definition for singly-linked list.*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* stringToListNode(string input);
void prettyPrintLinkedList(ListNode* node);
