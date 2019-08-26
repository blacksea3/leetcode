class Solution {
    public int[] searchRange(int[] nums, int target) {
        int before = target*2-1;
        int after = target*2+1;
        int s1=0,s2=0;
        int e1=nums.length,e2=nums.length;
        int[] ret = {-1,-1};
        
        while(s1<e1){
            int loc = (s1+e1)/2;
            if(2*nums[loc]<before){
                s1 = loc+1;
            }else{
                e1 = loc;
            }
        }
        
        
        while(s2<e2){
            int loc = (s2+e2)/2;
            if(2*nums[loc]<after){
                s2 = loc+1;
            }else{
                e2 = loc;
            }
        }
        
        if(s1!=s2){
            ret[0] = s1;
            ret[1] = s2-1;
        }

        return ret;
        
    }
    
}
