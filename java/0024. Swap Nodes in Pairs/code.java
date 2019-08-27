/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null||head.next==null){
            return head;
        }
        ListNode head2 = head.next;
        ListNode l1 = head;
        ListNode l2 = head.next;
        while(l1!=null&&l1.next!=null){
            l1.next = l1.next.next;
            if(l2.next!=null){
                l2.next = l2.next.next;
                l2 = l2.next;
            }
            l1 = l1.next;
        }
        l1 = head;
        l2 = head2;
        while(l2.next!=null){
            ListNode l = new ListNode(l1.val);
            l.next = l2.next;
            l2.next = l;
            l2 = l2.next.next;
            l1 = l1.next;
        }
        l2.next = l1;
        
        
        return head2;
    }
}
