class Solution {
    public String countAndSay(int n) {
        String s = getstring("1",n);
        return s;
    }
    public String getstring(String s, int n){
        int len = s.length();
        StringBuffer sb = new StringBuffer();
        
        if(n==1){
            return s;
        }
        
        char num = s.charAt(0);
        int count = 1;
        
        for(int i=1;i<len;i++){
            if(s.charAt(i)==num){
                count++;
            }else{
                sb.append(count);
                sb.append(num);
                num = s.charAt(i);
                count = 1;
            }
        }
        sb.append(count);
        sb.append(num);
        
        return getstring(sb.toString(),n-1);
    }
}
