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
    public void recoverTree(TreeNode root) {
        if(root==null){
            return;
        }
        TreeNode l = getmax(root.left);
        TreeNode r = getmin(root.right);
        
        if(l!=null&&r!=null){
            if(l.val>root.val&&r.val<root.val){
                int temp = l.val;
                l.val = r.val;
                r.val = temp;
                return;
            }
        }
        if(l!=null){
            if(l.val>root.val){
                int temp = l.val;
                l.val = root.val;
                root.val = temp;
                return;
            }
        }
        if(r!=null){
            if(r.val<root.val){
                int temp = r.val;
                r.val = root.val;
                root.val = temp;
                return;
            }
        }
        recoverTree(root.left);
        recoverTree(root.right);
        
    }
    
    private TreeNode getmax(TreeNode root){
        if(root==null){
            return null;
        }
        TreeNode left = getmax(root.left);
        TreeNode right = getmax(root.right);
        
        if(left!=null&&right!=null){
            return left.val>right.val ? 
                (left.val>root.val?left:root):(right.val>root.val?right:root);
        }else if(left!=null){
            return left.val>root.val ? left : root;
        }else if(right!=null){
            return right.val>root.val ? right : root;
        }else{
            return root;
        }   
    }
    private TreeNode getmin(TreeNode root){
        if(root==null){
            return null;
        }
        TreeNode left = getmin(root.left);
        TreeNode right = getmin(root.right);
        
        if(left!=null&&right!=null){
            return left.val<right.val ? (left.val<root.val?left:root):right;
        }else if(left!=null){
            return left.val<root.val ? left : root;
        }else if(right!=null){
            return right.val<root.val ? right : root;
        }else{
            return root;
        }  
    }
    
}
