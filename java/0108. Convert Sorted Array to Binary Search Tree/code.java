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
    public TreeNode sortedArrayToBST(int[] nums) {
        int len = nums.length;
        if(len==0){
            return null;
        }
        int mid = nums[len/2];
        TreeNode t = new TreeNode(mid);
        
        int[] l_nums = Arrays.copyOfRange(nums, 0, len/2);
        int[] r_nums = Arrays.copyOfRange(nums, len/2+1, len);
        
        
        t.left = sortedArrayToBST(l_nums);
        t.right = sortedArrayToBST(r_nums);
        return t;
    }
}
