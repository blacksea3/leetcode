class Solution {
    public int strStr(String haystack, String needle) {
        char start;
        if(needle.length()==0){
            return 0;
        }
        if(haystack.length()==0){
            return -1;
        }else{
            start = needle.charAt(0);
        }
        int length = haystack.length()-needle.length()+1;
        for(int i=0;i<length;i++){
            if(haystack.charAt(i)==start){
                if(haystack.substring(i, i+needle.length()).equals(needle)){
                    return i;
                }                
            }
        }
        return -1;
    }
}
