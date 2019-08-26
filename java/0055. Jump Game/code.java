class Solution {
    public boolean canJump(int[] nums) {
        int end = 0;
        int max = 0;
        for(int i=0;i<nums.length;i++){
            if(i>end){
                return false;
            }else{
                max = Math.max(max,i+nums[i]);
                if(i==end){
                    end = max;
                }
            }
        }
        return true;
    }
}
