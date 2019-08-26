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
	//set the head to be one node before
        temp.next = head;
        head = temp;
        
        //temp itself is not duplicate
	//remove all the other duplicate ones
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
            if(testtemp!=temp.next){
                temp.next = testtemp.next;
            }else{
                temp = temp.next;
            }
        }
        return head.next;
    }
}
