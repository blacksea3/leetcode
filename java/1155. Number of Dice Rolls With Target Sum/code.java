class Solution {
    public int numRollsToTarget(int d, int f, int target) {
        int[][] ans = new int[target+1][d+1];
        for(int i=1;i<=target;i++){
            ans[i][0] = 0;
        }
        for(int i=1;i<=d;i++){
            ans[0][d] = 0;
        }
        ans[0][0] = 1;
        int MOD = 1000000007;
        
        for(int i=1;i<=target;i++){
            for(int j=1;j<=d;j++){
                int temp = 0;
                for(int dis=1;dis<=f;dis++){
                    if(i-dis<0){
                        break;
                    }else{
                        temp += ans[i-dis][j-1];
                        temp%=MOD;
                    }  
                }
                ans[i][j]=temp;
            }
        }
        return ans[target][d];
    }
}
