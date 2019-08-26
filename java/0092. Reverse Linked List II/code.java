/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {

        ListNode temp = head;  
        ListNode reverse_start = new ListNode(0);
        ListNode prev_temp;
        ListNode before_reverse = new ListNode(0);
        int index = 1;
        
        while(temp.next!=null){
            if(index==m){
                while(index<=n){
                    prev_temp = temp;
                    temp = temp.next;
                    index++;
                    
                    //set the prev_temp to be the start of reverse list
                    prev_temp.next = reverse_start.next;
                    reverse_start.next = prev_temp;
                }
                //put the reverse list into original list
                before_reverse.next = reverse_start.next;
                while(before_reverse.next!=null){
                    before_reverse = before_reverse.next;
                }
                before_reverse.next = temp;
                
                //if reverse start at first, change the head pointer
                if(m==1){
                    head = reverse_start.next;
                }
                break;
            }
            before_reverse = temp;
            temp = temp.next;
            index++;
        }
        return head;
    }
}
