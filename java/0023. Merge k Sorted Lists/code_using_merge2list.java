/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 2){
            return mergeTwoLists(lists[0], lists[1]);
        }else if(lists.length == 1){
            return lists[0];
        }else if(lists.length == 0){
            return null;
        }else{
            ListNode[] newlists = new ListNode[lists.length - 1];
            for(int i = 0; i<newlists.length -1; i++){
                newlists[i] = lists[i];
            }
            newlists[newlists.length -1] = mergeTwoLists(lists[newlists.length -1], lists[newlists.length]);
            return mergeKLists(newlists);
        }
    }
    
    public ListNode mergeTwoLists(ListNode l1, ListNode l2){
		if(l1 == null) return l2;
		if(l2 == null) return l1;
		if(l1.val < l2.val){
			l1.next = mergeTwoLists(l1.next, l2);
			return l1;
		} else{
			l2.next = mergeTwoLists(l1, l2.next);
			return l2;
		}
    }
    
}
