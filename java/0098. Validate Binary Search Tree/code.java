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
    public boolean isValidBST(TreeNode root) {
        if(root==null){
            return true;
        }
        boolean leftvalid = true;
        boolean rightvalid = true;
                    
        if(root.left!=null){
            if(isValidBST(root.left)){
                int max = maxvalue(root.left);
                leftvalid = max<root.val;
            }else{
                leftvalid = false;
            }
        }
        if(root.right!=null){
            if(isValidBST(root.right)){
                int min = minvalue(root.right);
                rightvalid = min>root.val;
            }else{
                rightvalid = false;
            }
        }         
        return rightvalid&&leftvalid;
        
    }
    
    public int minvalue(TreeNode root){
        int min = root.val;
        while (root != null) {
            min = root.val;
            root = root.left;
        }
        return min;
    }
    
    public int maxvalue(TreeNode root){
        int max = root.val;
        while (root != null) {
            max = root.val;
            root = root.right;
        }
        return max;
    }
}
