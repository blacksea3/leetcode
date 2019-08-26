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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        inorderT(root, list);
        return list;
    }
    private void inorderT(TreeNode root, List<Integer> list){
        if(root!=null){
            if(root.left!=null){
                inorderT(root.left, list);
            }
            list.add(root.val);
            if(root.right!=null){
                inorderT(root.right, list);
            }
        }
    }
}
