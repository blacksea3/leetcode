class Solution {
    public double myPow(double x, int n) {  
        boolean sign = true;
        if(n<0){
            if(n==Integer.MIN_VALUE){
                return myPow(x,-Integer.MAX_VALUE)/x;
            }
            n=-n;
            sign=false;
        }
    
        if(sign){
            return pown(x,n);
        }else{
            return 1/pown(x,n);
        }
    }
    public double pown(double x, int n){
        int len = 0;
        double ret = 0;

        //count the binary length of n
        for(int temp = n;temp!=0;len++){
            temp=temp>>1;
        }
        //if len of available discount should -1 
        if(len>0){
            len--;
        }else{
            return 1;
        }
        int n_left = n-(1<<len);

        double ret1 = pow2(x,len);
        double ret2 = myPow(x,n_left);
        
        //if inf, direct return
        if(ret1==Double.POSITIVE_INFINITY||ret2==Double.POSITIVE_INFINITY){
            return Double.POSITIVE_INFINITY;
        }
        
        if(n_left==0){
            ret = ret1;
        }else{
            ret = ret1 * ret2;
        }
        return ret;
    }
    
    public double pow2(double x, int time){
        if(time<=0){
            return x;
        }
        return pow2(x*x,time-1);
    }
}
