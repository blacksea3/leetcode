class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        int[] jump_loc = new int[len+1];
        int count;
        
        if(len!=0&&len!=1){
            jump_loc[0] = nums[0];
            count = 1;
            if(jump_loc[0]>=len-1){
                return 1;
            }
        }else{
            return 0;
        }
          
        for(int i=1;i<len;i++){
            if(i>jump_loc[count-1]){
                count++;
            }
            if(nums[i]+i>jump_loc[count]){
                jump_loc[count]=Math.max(nums[i]+i,jump_loc[count-1]);
            }
            
            if(jump_loc[count]>=len-1){
                return count+1;
            }
        }
        
        return 0;
    }
}
