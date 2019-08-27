class package {
    //二分法搜索
    public int binarySearch(int begin, int end, int target, int[] matrix) {
        while(begin <= end){
            int mid = (begin + end) / 2;
            int mid_value = matrix[mid];

            if( mid_value == target){
                return true;

            }else if(mid_value < target){
                begin = mid+1;
            }else{
                end = mid-1;
            }
        }
    }
    
    //list<integer> 深拷贝
    public List<Integer> listclone(List<Integer> l1) { 
        List<Integer> l2 = new ArrayList<Integer>();
        for(int i=0;i<l1.size();i++){
            l2.add(l1.get(i));
        }
        return l2;
    }

    
    //滑动窗口
    public int slidingwindow(String s, String t){
	int left = 0; // 左指针
        int right = 0; // 右指针
        int ans_left = 0; // 保存最小窗口的左边界
        int ans_right = -1; // 保存最小窗口的右边界
        int ans_len = Integer.MAX_VALUE; // 当前最小窗口的长度
        int count = t.length();//判断窗口是否合理的条件 count = 0
	
	while (right < s.length()) {
	    if(case1){
		count--;
	    }
		
            while (count == 0) {
		int temp_len = right - left + 1;
                if (temp_len < ans_len) {
                    ans_left = left;
                    ans_right = right;
                    ans_len = temp_len;
                }
		
		if(case2){
		    count++;
		}
                left++; 
            }
            right++;
        }
	return ans_len;
    }

    //线段树，用于查找阶段内最小值
    //segment tree， 包括2class
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

	//index 通常为0， start,end为搜索范围
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

    
    //tree(binary tree)
    public class TreeNode {
       int val;
       TreeNode left;
       TreeNode right;
       TreeNode(int x) { val = x; }
    }

    //Traversal
    //inorder traversal 中序二叉树遍历
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


