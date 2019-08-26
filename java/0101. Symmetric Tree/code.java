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
    public boolean isSymmetric(TreeNode root) {
        if(root==null){
            return true;
        }
        
        return issame(root.left,root.right);
    }
    public boolean issame(TreeNode root1, TreeNode root2){
        if(root1==null||root2==null){
            return root1==null&&root2==null;
        }
        if(root1.val!=root2.val){
            return false;
        }
        boolean rightmatch = (issame(root1.right, root2.left));
        boolean leftmatch = (issame(root1.left, root2.right));
        return rightmatch&&leftmatch;  
    }
}
