class Solution {
    public int longestValidParentheses(String s) {
        int maxlen = 0;
        int len = 0;
        int count = 0;
        
        int slen = s.length();
        for(int i=0;i<slen;i++){
            if(s.charAt(i)==')'){
                count--;
            }else{
                count++;
            }
            if(count<0){
                maxlen = Math.max(len,maxlen);
                len = 0;
                count = 0;
            }else if(count == 0){
                len++;
                maxlen = Math.max(len,maxlen);
                //System.out.println(maxlen);
            }else{
                len++;
            }
        }
        if(len>maxlen+count){
            if(count>0){
                return Math.max(longestValidParentheses(s.substring(1)),maxlen);
            }else{
                maxlen = len;
                return maxlen;
            }
        }else{
            return maxlen;     
        }        
    }
}
