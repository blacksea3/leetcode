class Solution {
    public int largestRectangleArea(int[] heights) {
        HashSet<Integer> heightsSet = new HashSet<Integer>();
        //得到所有的高度，也就是去重。
        for (int i = 0; i < heights.length; i++) {
            heightsSet.add(heights[i]);
        }
        int maxArea = 0;
        //遍历每一个高度
        for (int h : heightsSet) {
            int width = 0;
            int maxWidth = 1;
            //找出连续的大于等于当前高度的柱形个数的最大值
            for (int i = 0; i < heights.length; i++) {
                if (heights[i] >= h) {
                    width++;
                //出现小于当前高度的就归零，并且更新最大宽度
                } else {
                    maxWidth = Math.max(width, maxWidth);
                    width = 0;
                }
            }
            maxWidth = Math.max(width, maxWidth);
            //更新最大区域的面积
            maxArea = Math.max(maxArea, h * maxWidth);
        }
        return maxArea;
    }
}
