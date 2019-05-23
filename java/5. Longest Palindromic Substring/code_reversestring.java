//get new reverse string and find the shared substring of s and rev
//time n^2
//space could reduce to n^2 by using one 1-d array
class Solution {
    public String longestPalindrome(String s) {
	//max length and start position
        int max = 0,start=0;
	//return string
        String r = "";
	//reverse string
        String rev = new StringBuilder(s).reverse().toString();
        int length = s.length();
        int[][] countarray = new int[length][length];

	//use a 2-d dynamic array to store get the substring
        for(int i=0;i<length;i++){
            for(int j=0;j<length;j++){
                if(s.charAt(i)==rev.charAt(j)){
                    if(i==0||j==0){
                        countarray[i][j]=1;
                    }else{
                        countarray[i][j]=countarray[i-1][j-1]+1;
                    }
                }
                if(max<countarray[i][j]&&(i+j+2-countarray[i][j])==length){
                    max = countarray[i][j];
                    start = length - j - 1;
                }
            }
        }        
        r=s.substring(start,start+max);
        
        return r;
    }

}
