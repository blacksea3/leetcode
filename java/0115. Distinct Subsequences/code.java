class Solution {
    public int numDistinct(String s, String t) {
        int slen = s.length();
        int tlen = t.length();
        int[][] array = new int[tlen][slen];
        
        if(slen==0||tlen==0){
            return 0;
        }
        
        //initalize
        if(s.charAt(0)==t.charAt(0)){
            array[0][0] = 1;
        }else{
            array[0][0] = 0;
        }
        for(int i=1;i<slen;i++){
            if(s.charAt(i)==t.charAt(0)){
                array[0][i] = 1+array[0][i-1];
            }else{
                array[0][i] = array[0][i-1];
            }
        }
        for(int i=1;i<tlen;i++){
            array[i][0] = 0;
        }
        
        for(int i=1; i<tlen;i++){
            for(int j=1; j<slen;j++){
                if(s.charAt(j)==t.charAt(i)){
                    array[i][j] = array[i][j-1]+array[i-1][j-1];
                }else{
                    array[i][j] = array[i][j-1];
                }
            }
        }
        return array[tlen-1][slen-1];
        
    }
}
