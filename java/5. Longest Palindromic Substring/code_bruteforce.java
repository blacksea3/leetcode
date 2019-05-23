//brute force solution, will spend a long time
//n^3 for time
class Solution {
    public String longestPalindrome(String s) {
        int max = 0;
        String r = "";
        int i=0,j=0;
        for(;i<s.length();i++){
            for(j=i;j<s.length();j++){
                if(check(s.substring(i,j+1))>max){
                    max = check(s.substring(i,j+1));
                    r = s.substring(i,j+1);
                }
            }
        }
        return r;
    }
    
    public int check(String s){
        
        int length = s.length();
        for(int i=0;i<length/2;i++){
            if(s.charAt(i)!=s.charAt(length-1-i)){
                return 0;
            }
        }
        return length;
    }
}
