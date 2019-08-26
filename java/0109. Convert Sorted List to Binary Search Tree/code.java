/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        List<Integer> l = new ArrayList<>();
        
        while(head!=null){
            l.add(head.val);
            head = head.next;
        }
        int[] a = new int[l.size()];
        for(int i=0;i<l.size();i++){
            a[i]= l.get(i);
        }
        return sortedArray(a);
    }
    public TreeNode sortedArray(int[] nums) {
        int len = nums.length;
        if(len==0){
            return null;
        }
        int mid = nums[len/2];
        TreeNode t = new TreeNode(mid);
        
        int[] l_nums = Arrays.copyOfRange(nums, 0, len/2);
        int[] r_nums = Arrays.copyOfRange(nums, len/2+1, len);
        
        
        t.left = sortedArray(l_nums);
        t.right = sortedArray(r_nums);
        return t;
    }
}
