
class Solution {
    public int divide(int dividend, int divisor) {
        int sign = 1;
        if(dividend == (1<<31)&&divisor == -1){
            return (1<<31)-1;
        }
        if(divisor == (1<<31)){
            if(dividend == (1<<31)){
                return 1;
            }else{
                return 0;
            }
        }
        if(dividend<0&&divisor>0){
            sign = -1;
            dividend = -dividend;
        }else if(dividend>0&&divisor<0){
            sign = -1;
            divisor = - divisor;
            
        }else if(dividend<0&&divisor<0){
            dividend = - dividend;
            divisor = - divisor;
        }
        return sign*d(dividend,divisor);
    }
    
    public int d(int dividend, int divisor) {
        int l_dividend = Integer.toBinaryString(dividend).length();
        int l_divisor = Integer.toBinaryString(divisor).length();
        
        int sample = 0;
        int result = 0;
        
        if(l_dividend>l_divisor){
            sample = dividend >> (l_dividend - l_divisor -1);
            if(sample >= 2*divisor){
                dividend = dividend - divisor * (1<<(l_dividend - l_divisor));
                result = (1<<(l_dividend - l_divisor));
            }else{
                dividend = dividend - divisor * (1<<(l_dividend - l_divisor -1));
                result = (1<<(l_dividend - l_divisor -1));
            }
        }else{
            if(dividend>=divisor){
                return 1;
            }else{
                return 0;
            }
        }
        result = (result + d(dividend, divisor));
        return result;
    }
}
