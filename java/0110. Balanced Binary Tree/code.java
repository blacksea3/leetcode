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
    public boolean isBalanced(TreeNode root) {
        return getdepth(root)!=-2;
    }
    public int getdepth(TreeNode root){
        if(root==null){
            return 0;
        }
        int l = getdepth(root.left);
        int r = getdepth(root.right);
        
        if(l==-2||r==-2||l-r>1||r-l>1){
            return -2;
        }else{
            return 1+Math.max(l,r);
        }
    }
}
