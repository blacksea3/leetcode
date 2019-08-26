class Solution {
    public String getPermutation(int n, int k) {
        if(n==1){
            return "1";
        }else if(n<=0){
            return "";
        }
        k--;
        int size = factorial(n-1);
        int num = k/size;
        int pos = k%size+1;
        String s_prev = getPermutation(n-1,pos);
        char[] c_prev = s_prev.toCharArray();
        char[] c = new char[n];
        c[0] = (char)(num+'1');
        for(int i=1;i<c.length;i++){
            if(c_prev[i-1]>=c[0]){
                c[i]=(char)(c_prev[i-1]+1);
            }else{
                c[i]=c_prev[i-1];
            }
        }
        String s = new String(c);
        return s;   
    }
    public int factorial(int n){
        if(n==1){
            return 1;
        }
        return n*factorial(n-1);
    }
}
