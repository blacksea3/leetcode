class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> all = new ArrayList<>();
        Arrays.sort(nums);
        upset(nums, 0, all);
        return all;
    }

    private void upset(int[] nums, int begin, List<List<Integer>> all) {
        if (begin == nums.length) {
            ArrayList<Integer> temp = new ArrayList<Integer>(); 
            for (int i = 0; i < nums.length; i++) {
                temp.add(nums[i]);
            }
            all.add(new ArrayList<Integer>(temp));
            return;
        }
        HashSet<Integer> set = new HashSet<>();
        for (int i = begin; i < nums.length; i++) {
            if (set.contains(nums[i])) continue;
        
            set.add(nums[i]);
            swap(nums, i, begin);
            upset(nums, begin + 1, all);
            swap(nums, i, begin);
        }

    }

    private void swap(int[] nums, int i, int begin) {
        int temp = nums[i];
        nums[i] = nums[begin];
        nums[begin] = temp;
    }
}
