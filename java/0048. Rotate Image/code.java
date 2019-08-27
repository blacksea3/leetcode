class Solution {
    public void rotate(int[][] matrix) {
        int row = 0;
        int col = 0;
        int len = matrix.length;
        
        for(;row<len/2;row++){       
            for(col=row;col<len-row-1;col++){
                int temp = matrix[row][col];
                matrix[row][col] = matrix[len-col-1][row];
                matrix[len-col-1][row] = matrix[len-row-1][len-col-1];
                matrix[len-row-1][len-col-1] = matrix[col][len-row-1];
                matrix[col][len-row-1] = temp;
            }
        }
    }
}
