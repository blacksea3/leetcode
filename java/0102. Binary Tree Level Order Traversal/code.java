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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> Q = new LinkedList<TreeNode>();
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        
        if(root==null){
            return list;
        }
        Q.offer(root);
        while(!Q.isEmpty()){
            int size = Q.size();
            List<Integer> l = new ArrayList<Integer>();
            for(int i=0;i<size;i++){
                if(Q.peek().left!=null) Q.offer(Q.peek().left);
                if(Q.peek().right!=null) Q.offer(Q.peek().right);
                l.add(Q.poll().val);
            }
            list.add(l);         
        }
        return list;
    }
}
