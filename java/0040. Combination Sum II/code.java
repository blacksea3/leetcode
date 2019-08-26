class Solution {
    List<List<Integer>> retlist = new ArrayList<List<Integer>>();
    int[] can;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {   
        Arrays.sort(candidates);
        can = candidates;
        isvalid(new ArrayList<Integer>(), target, 0);
        return retlist;
    }
    
    public void isvalid(List<Integer> l, int target, int start){
        for(int i=start;i<can.length;i++){
            List<Integer> newl = new ArrayList<Integer>(l);
            if(can[i]==target){
                newl.add(can[i]);
                retlist.add(newl);
            }else if(target-can[i]>=can[0]){
                newl.add(can[i]);
                isvalid(newl,target-can[i], i+1);
            }
            
            while(i+1<can.length&&can[i]==can[i+1]){
                i++;
            }
        }
        return;
    }
}
