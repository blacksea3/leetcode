/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode last = head;
        int len = 1;
        if(head==null||head.next==null){
            return head;
        }
        while(last.next!=null){
            last = last.next;
            len++;
        }
        last.next = head;
        k=k%len;
        for(int i=0;i<len-k;i++){
            last = last.next;
        }
        head = last.next;
        last.next = null;
        return head;
    }
}
