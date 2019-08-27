class Solution {
    public int removeDuplicates(int[] nums) {
        
        if(nums.length==0){
            return 0;
        }
        int loc = 0;
        int prev_value = nums[0];
        boolean single = true;
        
        for(int i=1;i<nums.length;i++){
            if(prev_value==nums[i]){
                single = false;
            }else{
                nums[loc] = prev_value;
                if(!single){
                    nums[loc+1]=prev_value;
                    loc++;
                }
                loc++;
                prev_value = nums[i];
                single = true;
            }
        }
        nums[loc] = prev_value;
        if(!single){
            nums[loc+1]=prev_value;
            loc++;
        }
        return loc+1;
    }
}
