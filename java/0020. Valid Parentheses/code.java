class Solution {
    public boolean isValid(String s) {
        StringBuffer sb = new StringBuffer("0");
        
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='('||
                s.charAt(i)=='['||
                s.charAt(i)=='{'){
                sb.append(s.charAt(i));
            }else if(
                    (s.charAt(i)==')'&&sb.charAt(sb.length()-1)=='(')||
                    (s.charAt(i)==']'&&sb.charAt(sb.length()-1)=='[')||
                    (s.charAt(i)=='}'&&sb.charAt(sb.length()-1)=='{')){
                sb.setLength(sb.length() - 1);
            }else{
                return false;
            }
        }
        
        return sb.length() == 1;
        
    }
}
