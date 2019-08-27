/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode g_list = new ListNode(0);
        ListNode temp = head;
        ListNode gtemp = g_list;

	//set the temp to be the first valid node(<x) or null
        while(temp!=null&&temp.val>=x){
            gtemp.next = temp;
            temp = temp.next;
            gtemp = gtemp.next;
            gtemp.next = null;
        }
        head = temp;

	//if no valid start for temp, return null
        if(temp==null){
            return g_list.next;
        }

	//set the 2 linked list and combine
        while(temp.next!=null){
            if(temp.next.val>=x){
                gtemp.next = temp.next;
                temp.next = temp.next.next;
                gtemp = gtemp.next;
                gtemp.next = null;
            }else{
                temp = temp.next;
            } 
        }
        temp.next = g_list.next;
        return head;
    }
}
