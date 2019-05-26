class Solution {
    public int reverse(int x) {
        String s = Integer.toString(Math.abs(x));
        String rev = new StringBuilder(s).reverse().toString();
        int ret;
	
        try{
            ret = Integer.parseInt(rev);
        }catch(Exception e){
	    //out of boundary of int
            ret = 0;
        }
        if(x<0){
            ret = -ret;
        }
        return ret;
    }
}
