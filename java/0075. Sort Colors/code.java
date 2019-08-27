class Solution {
    public void sortColors(int[] nums) {
        int start = 0;
        int end = nums.length-1;
        for(int i=0;i<=end;i++){
	    //if 2 exchange with the end
	    //need to check the new i again
            if(nums[i]==2){
                nums[i] = nums[end];
                nums[end] = 2;
                end--;
                i--;
	    //if 0 exchange with the start
	    //do not need to check i, because nums[i] should be 1 or 0
            }else if(nums[i]==0){
                nums[i] = nums[start];
                nums[start] = 0;
                start++;
            }
        }
    }
}
