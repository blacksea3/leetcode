class Solution {
    public int myAtoi(String str) {
        int ret;
        int start = 0,end = 0;
        boolean sign = true;
	//fliter all the blanks before
        while(start<str.length()&&(str.charAt(start)==' ')){
            start++;
        }
        
        end = start;

	//check the first sign or number
        if(end<str.length()&&(isnum(str.charAt(end))||
                              str.charAt(end)=='+'||
                             str.charAt(end)=='-')){
            end++;

	    //get the rest sign
            while(end<str.length()&&isnum(str.charAt(end))){
                end++;
            }
            
        }

	//return 0 for non number(just + - or nothing at all)
        if(start==end||(start+1==end&&(!isnum(str.charAt(start))))){
            return 0;
        }   
        

        String s = str.substring(start,end);
        try{
            ret = Integer.parseInt(s);
        }catch(Exception e){
	    //if the num is out of boundary
            if(str.charAt(start)=='-'){
                return Integer.MIN_VALUE;
            }else{
                return Integer.MAX_VALUE;
            }
        }      
        return ret;
    }
    
    public boolean isnum(char c){
        if('0'<=c&&c<='9'){
            return true;
        }else{
            return false;
        }
    }
        
}
