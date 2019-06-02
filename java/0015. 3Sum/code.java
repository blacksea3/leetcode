class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int start = 0;
        List<List<Integer>> ret = new LinkedList<>(); 
        int thre = nums.length - 2;
        Arrays.sort(nums);
        //get the the index in num which is > 0
        //and set it as thre, then thre = min(thre,length-2)
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0){
                thre = i;
                break;
            }
        }
        thre = Math.min(thre,nums.length-2);
        
        //from 0 to thre
        //after nums[start] > 0,there will be any fits
        for(start = 0;start<thre;start++){
            int i = start+1;
            int j = nums.length-1; 
            while(i<j){
                if(nums[i]+nums[j]==-nums[start]){
                    ret.add(Arrays.asList(nums[start], nums[i], nums[j]));
                    while(i<j&&nums[i+1]==nums[i]){
                        i++;
                    }
                    while(i<j&&nums[j-1]==nums[j]){
                        j--;
                    }
                    i++;j--;
                }else if(nums[i]+nums[j]<-nums[start]){
                    i++;
                }else{                    
                    j--;
                }
            }
            while(nums[start]==nums[start+1]&&start<thre){
                start++;
            }
        }
        return ret;
    }
}
