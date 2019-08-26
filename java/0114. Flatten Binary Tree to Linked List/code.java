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
    public void flatten(TreeNode root) {
        if(root==null){
            return;
        }
        
        TreeNode temp = DFS(root, new TreeNode(0));
        root.left = null;   
        root.right =  newroot1.right.right;
    }
    
    private TreeNode DFS(TreeNode root, TreeNode newroot){
        if(root==null){
            return newroot;
        }
        newroot.right = new TreeNode(root.val); 
        TreeNode node1 = DFS(root.left, newroot.right);            
        TreeNode node2 = DFS(root.right, node1);
        
        return node2;
    }
        
}
