class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ret = "";
        int minlength;
        if(strs.length==0){
            return "";
        }
        minlength = strs[0].length();
        
        for(int i=0; i<strs.length; i++){
            if(minlength>strs[i].length()){
                minlength = strs[i].length();
            }
        }
        for(int i=0; i<minlength; i++){
            char temp = strs[0].charAt(i);
            for(int j=1; j<strs.length; j++){
                if(strs[j].charAt(i)!=temp){
                    return ret;
                }
            }
            ret += temp;
        }
        return ret;
    }
}
