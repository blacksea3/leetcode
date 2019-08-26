class Solution {
    public List<Integer> listclone(List<Integer> l1) { 
        List<Integer> l2 = new ArrayList<Integer>();
        for(int i=0;i<l1.size();i++){
            l2.add(l1.get(i));
        }
        return l2;
    } 
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(nums.length==0){
            result.add(new ArrayList<Integer>());
        }else{
            int[] newnums = new int[nums.length-1];
            for(int i=0;i<nums.length-1;i++){
                newnums[i] = nums[i];
            }
            List<List<Integer>> pre_res = subsets(newnums);
            List<List<Integer>> pre_res2  = new ArrayList<List<Integer>>();
            
            for(int i=0;i<pre_res.size();i++){
                pre_res2.add(listclone(pre_res.get(i)));
            }
            
            result.addAll(pre_res2);
            for(List<Integer> list : pre_res){
                list.add(nums[nums.length-1]);
            }
	    //if we could use subsets again to replace the deepcopy
            result.addAll(pre_res);
	    //result.addAll(subsets(newnums));
	    
        } 
        return result;
    }  
    
}
