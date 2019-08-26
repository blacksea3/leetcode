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
    public int minDepth(TreeNode root) {
        if(root==null){
            return 0;
        }
        int l = minDepth(root.left);
        int r = minDepth(root.right);
        
        if(l==0&&r==0){
            return 1;
        }else if(l==0){
            return r+1;
        }else if(r==0){
            return l+1;
        }else{
            return 1+Math.min(l,r);
        }
    }
}
