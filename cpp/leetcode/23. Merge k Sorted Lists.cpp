#include "public.h"
#include "listnode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//36ms, 98.41%

//DC: divide and conquer
// at last, only need to write code: merge two lists

class Solution {
public:
	//here I use recu to mergeTwoLists
	// it seems that recu is faster then iter?(when I write my stupid code)
	ListNode * mergeTwoLists(ListNode * l1, ListNode * l2)
	{
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* l3 = NULL;
		if (l1->val < l2->val) {
			l3 = l1;
			l3->next = mergeTwoLists(l1->next, l2);
		}
		else {
			l3 = l2;
			l3->next = mergeTwoLists(l1, l2->next);
		}
		return l3;
	}

	//merge Klists
	ListNode * recu_mergeKLists(vector<ListNode*>& lists, int startloc, int endloc)
	{
		if (endloc == startloc) return lists[startloc];
		else  //if endloc == startloc + 1, mid equals startloc
		{
			int middle = (startloc + endloc) / 2;  //here startloc1 - startloc2 >= 2
			return mergeTwoLists(recu_mergeKLists(lists, startloc, middle),
				recu_mergeKLists(lists, middle + 1, endloc));
		}
	}

	ListNode * mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.size() == 0) return nullptr;
		return recu_mergeKLists(lists, 0, lists.size() - 1);
	}
};
