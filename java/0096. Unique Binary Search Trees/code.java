class Solution {
    int[][] dp;
    public int numTrees(int n) {
        if(n==0){
            return 0;
        }else{
            dp = new int[n+2][n+2];
            for(int i=0;i<n+2;i++){
                for(int j=0;j<n+2;j++){
                    dp[i][j]=-1;
                }
            }
            return getAns(1,n);
        }
    }
    private int getAns(int start, int end) { 
        int ans = 0;
        if (start >= end) {
            return 1;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        
        for (int i = start; i <= end; i++) {
            int leftTrees = getAns(start, i - 1);
            dp[start][i-1]=leftTrees;
            
            int rightTrees = getAns(i + 1, end);
            dp[i+1][end]=rightTrees;
            
            ans += leftTrees * rightTrees;
        }
        return ans;
    }
}
