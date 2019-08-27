class Solution {
    int[] a;
    public int numDecodings(String s) {
        int len = s.length();
        if(len==0){
            return 0;
        }
        a = new int[len+1];
        for(int i=0;i<len+1;i++){
            a[i] = -1;
        }
        
        return D(s);
    }
    public int D(String s) {
        int len = s.length();
        int ans;
        int val1,val2;
        if(len==0){
            return 0;
        }else if(len==1){
            if(s.equals("0")){
                return 0;
            }else{
                return 1;
            }
        }else if(len==2){
            int n = Integer.parseInt(s);
            if(n>26||n<10){
                ans = 1;
            }else{
                ans = 2;
            }
            if(s.charAt(1)=='0'||s.charAt(0)=='0'){
                ans--;
            }
            return ans;
        }else{
            if(s.charAt(len-1)=='0'){
                if(s.charAt(len-2)!='1'&&s.charAt(len-2)!='2'){
                    return 0;
                }else{
                    if(a[len-2]==-1){
                        a[len-2]=D(s.substring(0,len-2));
                    }
                    return a[len-2];
                }
            }else if(s.charAt(len-2)=='0'){
                if(a[len-1]==-1){
                    a[len-1]=D(s.substring(0,len-1));
                }
                ans = a[len-1];
            }else if(s.charAt(len-2)-'0'>2||
              (s.charAt(len-2)-'0'==2&&s.charAt(len-1)-'0'>6)){
                if(a[len-1]==-1){
                    a[len-1]=D(s.substring(0,len-1));
                }
                ans = a[len-1];
            }else{
                if(a[len-1]==-1){
                    a[len-1]=D(s.substring(0,len-1));
                }
                if(a[len-2]==-1){
                    a[len-2]=D(s.substring(0,len-2));
                }
                ans = a[len-1]+a[len-2];
            }
            return ans;
        }        
    }
}
