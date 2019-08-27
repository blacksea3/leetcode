class Solution {
    int rotloc = 0;
    int tg = 0;
    public boolean search(int[] nums, int target) {
        rotloc = findR(nums, 0, nums.length-1);
        tg = target;
        if(nums.length==0){
            return false;
        }
        
        if(nums[0]>tg){
            return findtarget(nums, rotloc+1, nums.length-1);
        }else if(nums[0]==tg){
            return true;
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
	//check from the start to loc
	//to decide whether is in the front or end
        boolean front = false;
        for(int i=0;i<loc;i++){
            if(nums[i]>nums[loc]){
                front = true;
                break;
            }
        }
        if(front){
            return findR(nums, loc1, loc-1);
        }else{
            return findR(nums, loc+1, loc2);
        }
    }
    
    public boolean findtarget(int[] nums, int loc1, int loc2){
        int loc = (loc1+loc2)/2;  
        
        if(nums[loc]==tg){
            return true;
        }
        
        if(loc1>=loc2){
            return false;
        }
        
        if(nums[loc]<tg){
            return findtarget(nums, loc+1, loc2);
        }else{
            return findtarget(nums, loc1, loc-1);
        }
    }
}
