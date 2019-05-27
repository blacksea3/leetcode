class Solution {
    public int romanToInt(String s) {
        int max = 0;
        int length = s.length();
        int temp = 0;
        int ret = 0;

	//if the num < max sub else add
        for(int i=length-1;i>=0;i--){
            temp = check(s.charAt(i));
            if(temp>=max){
                max = temp;
                ret += temp;
            }else{
                ret -= temp;
            }
        }
        return ret;
    }

    //get the num of char
    public int check(char c){
        if(c=='I'){
            return 1;
        }else if(c=='V'){
            return 5;
        }else if(c=='X'){
            return 10;
        }else if(c=='L'){
            return 50;
        }else if(c=='C'){
            return 100;
        }else if(c=='D'){
            return 500;
        }else if(c=='M'){
            return 1000;
        }else{
            return 0;
        }

    }
}
