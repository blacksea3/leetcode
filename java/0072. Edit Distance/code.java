class Solution {
    public int minDistance(String word1, String word2) {
        int[][] ans = new int[word1.length()+1][word2.length()+1];
        for(int i=0;i<=word2.length();i++){
            ans[0][i] = i;
        }
        for(int i=1;i<=word1.length();i++){
            ans[i][0] = i;
        }
        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                int v_1 = ans[i][j-1] + 1;
                int v_2 = ans[i-1][j] + 1;
                int v_3 = ans[i-1][j-1] + 1;
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    v_3--;
                }
                ans[i][j] = Math.min(Math.min(v_1,v_2),v_3);
            }
        }
        return ans[word1.length()][word2.length()];
    }
}
