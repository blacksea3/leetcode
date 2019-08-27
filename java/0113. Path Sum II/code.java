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
    List<List<Integer>> l = new ArrayList<List<Integer>>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root!=null){
            check(root, sum, new ArrayList<Integer>());
        }
        return l;
    }
    
    private void check(TreeNode root, int sum, List<Integer> list){
        if(root.left==null&&root.right==null){
            if(sum==root.val){
                list.add(root.val);
                List<Integer> newlist = new ArrayList<>(list);
                l.add(newlist);
                list.remove(list.size()-1);
            }
        }
        if(root.right!=null){
            list.add(root.val);
            check(root.right, sum - root.val, list);
            list.remove(list.size()-1);
        }
        if(root.left!=null){
            list.add(root.val);
            check(root.left, sum - root.val, list);
            list.remove(list.size()-1);
        }
        return;
        
    }
}
