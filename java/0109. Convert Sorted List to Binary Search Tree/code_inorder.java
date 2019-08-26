/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    ListNode cur = null;

    public TreeNode sortedListToBST(ListNode head) {
        cur = head;
        int end = 0;
        while (head != null) {
            end++;
            head = head.next;
        }
        return sortedArrayToBSTHelper(0, end);
    }

    private TreeNode sortedArrayToBSTHelper(int start, int end) {
        if (start == end) {
            return null;
        }
        int mid = (start + end) >>> 1;
        //遍历左子树并且将根节点返回
        TreeNode left = sortedArrayToBSTHelper(start, mid);
        //遍历当前根节点并进行赋值
        TreeNode root = new TreeNode(cur.val);
        root.left = left;
        cur = cur.next; //指针后移，进行下一次的赋值
        //遍历右子树并且将根节点返回
        TreeNode right = sortedArrayToBSTHelper(mid + 1, end);
        root.right = right;
        return root;
    }
}
