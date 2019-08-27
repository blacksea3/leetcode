/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode l1;
        ListNode l2;
        ListNode temp;  
        temp = head;
        if(k==1||k==0){
            return head;
        }
        
        for(int i=0;i<k;i++){
            if(temp == null){
                return head;
            }else{
                temp = temp.next;
            }   
        }
        l1 = head;
        l2 = head.next;
                
        for(int i=0;i<k-1;i++){
            //swap first node with the last
            temp = l2.next;
            l2.next = l1;
            //update l1,l2
            l1 = l2;
            l2 = temp;
        }
        head.next = reverseKGroup(l2, k) ;
        return l1;
    }
}
