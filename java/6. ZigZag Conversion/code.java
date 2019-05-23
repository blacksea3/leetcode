class Solution {
    public String convert(String s, int numRows) {
        int len = s.length();
        int numturn = 2*numRows - 2;
	//numturn should not be 0
        if(numRows==1){
            return s;
        }
        int turn = len/numturn;
	//start postion of thr remaining after entire turn
        int shred = turn*numturn;
                
        String r = "";

	//for every row
        for(int i=0;i<numRows;i++){
	    //for every turn(entire turn)
            for(int j=0;j<turn;j++){
                r+=s.charAt(j*numturn+i);
                if(i!=0&&i!=numRows-1){
                    r+=s.charAt(j*numturn+numturn-i);
                }
            }
	    //for the remaining chars
            if(len>shred+i){
                r+=s.charAt(shred+i);
                if(len>shred+numturn-i&&i!=numRows-1){
                    r+=s.charAt(shred+numturn-i);
                }
            }
        }        
        return r;        
    }
}
