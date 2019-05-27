class Solution {
    public String intToRoman(int num) {
        int temp = 0;
        String ret = "";
        
        temp = num/1000;
        for(int i=0;i<temp;i++){
            ret += "M";
        }
        
        temp = (num%1000)/100;
        if(temp%5-4==0){
            ret += "C";
            if(temp==9){
                ret += "M";
            }else{
                ret += "D";
            }
        }else{
            if(temp/5==1){
                ret += "D";
            }
            
            for(int i=0;i<temp%5;i++){
                ret += "C";
            }

        }
        
        temp = (num%100)/10;
        if(temp%5-4==0){
            ret += "X";
            if(temp==9){
                ret += "C";
            }else{
                ret += "L";
            }
        }else{
            if(temp/5==1){
                ret += "L";
            }
            for(int i=0;i<temp%5;i++){
                ret += "X";
            }
        }
        
        temp = (num%10);
        if(temp%5-4==0){
            ret += "I";
            if(temp==9){
                ret += "X";
            }else{
                ret += "V";
            }
        }else{
            if(temp/5==1){
                ret += "V";
            }
            for(int i=0;i<temp%5;i++){
                ret += "I";
            }

        }
        
        return ret;
    }
}
