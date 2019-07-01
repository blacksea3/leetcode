/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode temp;
        ListNode newl;
        ListNode start;
        
        if(l1==null){
            return l2;
        }else if(l2==null){
            return l1;
        }
        
        if(l1.val<l2.val){
            newl = new ListNode(l1.val);
            l1 = l1.next;
        }else{
            newl = new ListNode(l2.val);
            l2 = l2.next;
        }
        start = newl;
        while(l1!=null&&l2!=null){
            if(l1.val>l2.val){
                temp = new ListNode(l2.val);
                l2 = l2.next;
            }else{
                temp = new ListNode(l1.val);
                l1 = l1.next;
            }
            newl.next = temp;
            newl = newl.next;
        }
        
        if(l1!=null){
            newl.next = l1;
        }else if(l2!=null){
            newl.next = l2;
        }
        
        return start;
    }
}
