class Node// 节点
{
    int start;// 区间的左端点
    int end;// 区间的右端点
    int data;// 该区间的最小值
    int index; // 该节点最小值对应数组的下标

    public Node(int start, int end)// 构造方法中传入左端点和右端点
    {
        this.start = start;
        this.end = end;
    }

}

class SegmentTree {
    private int[] base;// 给定数组
    Node[] nodes;// 存储线段树的数组

    public SegmentTree(int[] nums) {
        base = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            base[i] = nums[i];
        }
        //需要 4n 的空间，上边链接给出了原因
        nodes = new Node[base.length * 4];
    }

    public void build(int index)// 构造一颗线段树，传入下标
    {
        Node node = nodes[index];// 取出该下标下的节点
        if (node == null) {// 根节点需要手动创建
            nodes[index] = new Node(0, this.base.length - 1);
            node = nodes[index];
        }
        if (node.start == node.end) {// 如果这个线段的左端点等于右端点则这个点是叶子节点
            node.data = base[node.start];
            node.index = node.start;
        } else { // 否则递归构造左右子树
            int mid = (node.start + node.end) >> 1;// 现在这个线段的中点
            nodes[(index << 1) + 1] = new Node(node.start, mid);// 左孩子线段
            nodes[(index << 1) + 2] = new Node(mid + 1, node.end);// 右孩子线段
            build((index << 1) + 1);// 构造左孩子
            build((index << 1) + 2);// 构造右孩子
            if (nodes[(index << 1) + 1].data <= nodes[(index << 1) + 2].data) {
                node.data = nodes[(index << 1) + 1].data;
                node.index = nodes[(index << 1) + 1].index;
            } else {
                node.data = nodes[(index << 1) + 2].data;
                node.index = nodes[(index << 1) + 2].index;
            }
        }
    }

    public Node query(int index, int start, int end) {
        Node node = nodes[index];
        if (node.start > end || node.end < start)
            return null;// 当前区间和待查询区间没有交集，那么返回一个极大值
        if (node.start >= start && node.end <= end)
            return node;// 如果当前的区间被包含在待查询的区间内则返回当前区间的最小值
        Node left = query((index << 1) + 1, start, end);
        int dataLeft = left == null ? Integer.MAX_VALUE : left.data;
        Node right = query((index << 1) + 2, start, end);
        int dataRight = right == null ? Integer.MAX_VALUE : right.data;
        return dataLeft <= dataRight ? left : right;

    }
}
class Solution {
    public int largestRectangleArea(int[] heights) {
        if (heights.length == 0) {
            return 0;
        }
        //构造线段树
        SegmentTree tree = new SegmentTree(heights);
        tree.build(0);
        return getMaxArea(tree, 0, heights.length - 1, heights);
    }
    /**
     *  查询某个区间的最小值
     * @param tree 构造好的线段树 
     * @param start 待查询的区间的左端点
     * @param end 待查询的区间的右端点
     * @param heights 给定的数组
     * @return 返回当前区间的矩形区域的最大值
     */
    private int getMaxArea(SegmentTree tree, int start, int end, int[] heights) {
        if (start == end) {
            return heights[start];
        }
        //非法情况，返回一个最小值，防止影响正确的最大值
        if (start > end) {
            return Integer.MIN_VALUE;
        }
        //找出最小的柱子的下标
        int min = tree.query(0, start, end).index;
        //最大矩形区域包含选定柱子的区域。
        int area1 = heights[min] * (end - start + 1);
        //最大矩形区域在不包含选定柱子的左半区域。
        int area2 = getMaxArea(tree, start, min - 1, heights);
        //最大矩形区域在不包含选定柱子的右半区域。
        int area3 = getMaxArea(tree, min + 1, end, heights);
        //返回最大的情况
        return Math.max(Math.max(area1, area2), area3);
    }
}
