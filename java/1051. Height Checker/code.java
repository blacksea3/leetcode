class Solution {
    public int heightChecker(int[] heights) {
        int count = 0;
        int[] origin = heights.clone();

        Arrays.sort(heights);        
        for(int i=0; i<heights.length;i++){
            if(origin[i]!=heights[i]){
                count++;
            }
        }
        
        return count;
    }
}
