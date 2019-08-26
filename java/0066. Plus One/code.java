class Solution {
    public int[] plusOne(int[] digits) {
        for(int i=digits.length-1;i>=0;i--){
            if(digits[i]!=9){
                digits[i]=digits[i]+1;
                return digits;
            }else{
                digits[i]=0;
            }
        }
        int[] ret = new int[digits.length+1];
        ret[0]=1;
        for(int i=0;i<digits.length-1;i++){
            ret[i+1]=digits[i];
        }
        return ret;
    }
}
