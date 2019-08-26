class Solution {
    int[][] array;
    public int minPathSum(int[][] grid) {
        array = new int[grid.length][grid[0].length];
        
        array[0][0] = grid[0][0];
        //set the first line and row 
        for(int i=1;i<array[0].length;i++){
            array[0][i] = grid[0][i]+array[0][i-1];
        }
        for(int i=1;i<array.length;i++){
            array[i][0] = grid[i][0]+array[i-1][0];
        }
        
        //set inside
        for(int i=1;i<array.length;i++){
            for(int j=1;j<array[0].length;j++){         
                array[i][j]= grid[i][j]+Math.min(array[i-1][j],array[i][j-1]);
            }
        }
        
        return array[grid.length-1][grid[0].length-1];
        
    }
}
