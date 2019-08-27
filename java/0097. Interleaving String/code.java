class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        boolean[][] ans = new boolean[len1+1][len2+1];
        
        if(len1+len2!=s3.length()){
            return false;
        }
        
        ans[0][0] = true;
        for(int i=1;i<=len1;i++){
            ans[i][0] = ans[i-1][0]&&(s1.charAt(i-1)==s3.charAt(i-1));
        }
        for(int i=1;i<=len2;i++){
            ans[0][i] = ans[0][i-1]&&(s2.charAt(i-1)==s3.charAt(i-1));
        }
        
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(ans[i][j-1]&&s2.charAt(j-1)==s3.charAt(j+i-1)){
                    ans[i][j]=true;
                }
                if(ans[i-1][j]&&s1.charAt(i-1)==s3.charAt(j+i-1)){
                    ans[i][j]=true;
                }
            }
        }
        
        return ans[len1][len2];
    }
}
