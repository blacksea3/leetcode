class Solution {
    public int largestRectangleArea(int[] heights) {
        if (heights.length == 0) {
            return 0;
        }
        return getMaxArea(heights, 0, heights.length - 1);
    }

    private int getMaxArea(int[] heights, int left, int right) {
        if (left == right) {
            return heights[left];
        }
        int mid = left + (right - left) / 2;
        //左半部分
        int area1 = getMaxArea(heights, left, mid);
        //右半部分
        int area2 = getMaxArea(heights, mid + 1, right);
        //中间区域
        int area3 = getMidArea(heights, left, mid, right);
        //选择最大的
        return Math.max(Math.max(area1, area2), area3);
    }

    private int getMidArea(int[] heights, int left, int mid, int right) { 
        int i = mid;
        int j = mid + 1;
        int minH = Math.min(heights[i], heights[j]);
        int area = minH * 2;
        //向两端扩展
        while (i >= left && j <= right) {
            minH = Math.min(minH, Math.min(heights[i], heights[j]));
            //更新最大面积
            area = Math.max(area, minH * (j - i + 1));
            if (i == left) {
                j++;
            } else if (j == right) {
                i--;
                //选择较高的柱子
            } else if (heights[i - 1] >= heights[j + 1]) {
                i--;
            } else {
                j++;

            }
        }
        return area;
    }
}
