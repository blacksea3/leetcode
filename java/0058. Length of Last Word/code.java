class Solution {
    public int lengthOfLastWord(String s) {
        int loc = s.length()-1;
        int last = loc;
        if(loc==-1){
            return 0;
        }
        
        for(;loc>=0;loc--){
            if(Character.isSpace(s.charAt(loc))){
                if(loc==last){
                    last--;
                }else{
                    break;
                }
            }
        }
        return last - loc;
        
    }
}
