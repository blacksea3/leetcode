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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null){
            return false;
        }
        return check(root, sum);
    }
    
    private boolean check(TreeNode root, int sum){
        if(root.left==null&&root.right==null){
            return sum==root.val;
        }else if(root.left==null){
            return check(root.right, sum - root.val);
        }else if(root.right==null){
            return check(root.left, sum - root.val);
        }else{
            return check(root.left, sum - root.val)||
                check(root.right, sum - root.val);
        }
        
    }
}
