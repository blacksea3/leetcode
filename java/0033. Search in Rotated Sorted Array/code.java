class Solution {
    int rotloc = 0;
    int tg = 0;
    public int search(int[] nums, int target) {
	//find the rotation loc
        rotloc = findR(nums, 0, nums.length-1);
        tg = target;
	
	//if nums is null
        if(nums.length==0){
            return -1;
        }
	
        //the start loc for findtarget
        if(nums[0]>tg){
            return findtarget(nums, rotloc+1, nums.length-1);
        }else if(nums[0]==tg){
            return 0;
        }else{
            return findtarget(nums, 0, rotloc);
        }
    }
    
    public int findR(int[] nums, int loc1, int loc2){
        int loc = (loc1+loc2)/2;
        
        //if the loc is the last in nums 
        if(loc>=nums.length-1){
            return nums.length-1;
        }
        
        if(nums[loc]>nums[loc+1]){
            return loc;
        }
	
        if(nums[loc]<nums[0]){
            return findR(nums, loc1, loc-1);
        }else{
            return findR(nums, loc+1, loc2);
        }
    }
    
    public int findtarget(int[] nums, int loc1, int loc2){
        int loc = (loc1+loc2)/2;  
        
        if(nums[loc]==tg){
            return loc;
        }
        
        if(loc1>=loc2){
            return -1;
        }
        
        if(nums[loc]<tg){
            return findtarget(nums, loc+1, loc2);
        }else{
            System.out.print(loc1);
            return findtarget(nums, loc1, loc-1);
        }
    }
}
