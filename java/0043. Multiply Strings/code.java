class Solution {
    public String multiply(String num1, String num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        
        int[] retnum = new int[len1+len2];
        for(int i=len1-1; i>=0;i--){
            for(int j=len2-1; j>=0; j--){
                int sum = (num1.charAt(i)-'0')*(num2.charAt(j)-'0');
                sum+=retnum[i+j+1];
                retnum[i+j+1]=sum%10;
                retnum[i+j]+=sum/10;
            }
        }
        
        StringBuffer sb = new StringBuffer();
        
        for(int p: retnum){
            if(p!=0||sb.length()!=0){
                sb.append(p);
            }
        }
        
        return sb.length()==0 ? "0" : sb.toString();
    }
}
