/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode Nth = head;
        ListNode last = head;
        
        for(int i=0; i<n&&last!=null; i++){
            last = last.next;
        }
        
        if(last==null){
            return head.next;
        }
        
        for(;last.next!=null;last=last.next){
            Nth = Nth.next;
        }
        
        Nth.next = Nth.next.next;
        
        return head;
    }
}
