class Solution {
    int[][] path = new int[101][101];
    public int uniquePaths(int m, int n) {
        if(n==1||m==1){
            return 1;
        }else{
            if(path[m][n]==0){
                path[m][n]=uniquePaths(m-1,n)+uniquePaths(m,n-1);
            }
            return path[m][n];            
        }
    }
}
