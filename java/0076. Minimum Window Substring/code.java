class Solution {
    public String minWindow(String s, String t) {
        int[] map = new int[128];
        // 遍历字符串 t，初始化每个字母的次数
        for (int i = 0; i < t.length(); i++) {
            char char_i = t.charAt(i);
            map[char_i]++;
        }
        int left = 0; // 左指针
        int right = 0; // 右指针
        int ans_left = 0; // 保存最小窗口的左边界
        int ans_right = -1; // 保存最小窗口的右边界
        int ans_len = Integer.MAX_VALUE; // 当前最小窗口的长度
        int count = t.length();
        // 遍历字符串 s
        while (right < s.length()) {
            char char_right = s.charAt(right);

            // 当前的字母次数减一
            map[char_right]--;

            //代表当前符合了一个字母
            if (map[char_right] >= 0) {
                count--;
            }
            // 开始移动左指针，减小窗口
            while (count == 0) { // 如果当前窗口包含所有字母，就进入循环
                // 当前窗口大小
                int temp_len = right - left + 1;
                // 如果当前窗口更小，则更新相应变量
                if (temp_len < ans_len) {
                    ans_left = left;
                    ans_right = right;
                    ans_len = temp_len;
                }
                // 得到左指针的字母
                char key = s.charAt(left);
                // 因为要把当前字母移除，所有相应次数要加 1
                map[key]++;
                //此时的 map[key] 大于 0 了，表示缺少当前字母了，count++
                if (map[key] > 0) {
                    count++;
                }
                left++; // 左指针右移
            }
            // 右指针右移扩大窗口
            right++;
        }
        return s.substring(ans_left, ans_right + 1);
    }
}
