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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        HashMap<Integer, Integer> map = new HashMap<>();
        //put all inorder inside map
        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
        return buildTreeHelper(inorder, postorder, 0, inorder.length, 0, postorder.length, map);
    }
    
    private TreeNode buildTreeHelper(int[] inorder, int[] postorder, int i_start, int i_end, int p_start, int p_end, HashMap<Integer, Integer> map){
        if(p_start==p_end){
            return null;
        }
        int root_val = postorder[p_end-1];
        TreeNode root = new TreeNode(root_val);
        
        int i_root_index = map.get(root_val);
        int leftNum = i_root_index - i_start;
        
        root.left = buildTreeHelper(inorder, postorder, i_start, i_root_index, p_start, p_start + leftNum, map);
        root.right = buildTreeHelper(inorder, postorder, i_root_index+1, i_end, p_start + leftNum, p_end-1, map);
        return root;
    }
}
