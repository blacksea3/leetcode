class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int ylen = matrix.length;
        if(ylen==0){
            return false;
        }
        int xlen = matrix[0].length;
        
        int begin = 0, end = xlen * ylen - 1;
	
        while(begin <= end){
            int mid = (begin + end) / 2;
            int mid_value = matrix[mid/xlen][mid%xlen];

            if( mid_value == target){
                return true;
            }else if(mid_value < target){
                begin = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }
}
