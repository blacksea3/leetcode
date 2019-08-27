class Solution {
    List<List<Integer>> list = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
       backtrack(new ArrayList<>(), nums);
       return list;
    }

    private void backtrack(List<Integer> tempList, int [] nums){
       if(tempList.size() == nums.length){
          list.add(new ArrayList<>(tempList));
       } else{
          for(int i = 0; i < nums.length; i++){ 
             if(tempList.contains(nums[i])) continue; 
             tempList.add(nums[i]);
             backtrack(tempList, nums);
             tempList.remove(tempList.size() - 1);
          }
       }
    }
}
