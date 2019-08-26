class Solution {
    int[][] array;
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        array = obstacleGrid;
        //use negative value to represent the num of path
        //if 1 means do not path(array[0][0] not path should be 0)
        array[0][0]--;
        
        //set the first line and row 
        for(int i=1;i<array[0].length;i++){
            if(array[0][i]!=1){
                array[0][i]=array[0][i-1];
            }
        }
        for(int i=1;i<array.length;i++){
            if(array[i][0]!=1){
                array[i][0]=array[i-1][0];
            }
        }
        
        //set inside
        for(int i=1;i<array.length;i++){
            for(int j=1;j<array[0].length;j++){
                //if block do nothing
                if(array[i][j]==1) continue;
                int top = (array[i-1][j]==1) ? 0 : array[i-1][j];
                int left = (array[i][j-1]==1) ? 0 : array[i][j-1];
                array[i][j]=top+left;
            }
        }
        //if last is block return 0
        //else return - value
        if(array[array.length-1][array[0].length-1]==1){
            return 0;
        }else{
            return -(array[array.length-1][array[0].length-1]);
        }
        
    }
}
