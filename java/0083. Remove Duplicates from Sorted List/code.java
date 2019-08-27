/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode temp = new ListNode(0);
        temp.next = head;
        head = temp;
        
        
        while(temp.next!=null){
            int next_value = temp.next.val;
            ListNode testtemp = temp.next;
            while(testtemp.next!=null){
                if(testtemp.next.val == next_value){
                    testtemp = testtemp.next;
                }else{
                    break;
                }
            }
            temp.next = testtemp;
            temp = temp.next;
        }
        return head.next;
    }
}
