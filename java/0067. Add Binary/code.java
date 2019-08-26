class Solution {
    public String addBinary(String a, String b) {
        StringBuffer sb = new StringBuffer();
        int len = Math.max(a.length(),b.length())+1;
        int a_v;
        int b_v;
        int prev_v=0;
        for(int i=0;i<len;i++){
            a_v = a.length()-i-1<0 ? 0 : (a.charAt(a.length()-i-1)-'0');
            b_v = b.length()-i-1<0 ? 0 : (b.charAt(b.length()-i-1)-'0');

            sb.insert(0,(a_v+b_v+prev_v)%2);
            prev_v = (a_v+b_v+prev_v)/2;
        }
        if(sb.charAt(0)=='0'){
            sb.delete(0,1);
        }
        return sb.toString();
    }
}
