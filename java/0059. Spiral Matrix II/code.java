class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        addround(0,matrix,1);
        return matrix;
    }
    public void addround(int round, int[][] matrix, int input){
        if(matrix.length-2*round==1){
            matrix[round][round] = input;
            return;
        }
        
        for(int i=round;i<matrix[0].length-round-1;i++){
            //list.add(matrix[round][i]);
            matrix[round][i]=input;
            input++;
        }
        for(int i=round;i<matrix.length-round-1;i++){
            //list.add(matrix[i][matrix[0].length-round-1]);
            matrix[i][matrix[0].length-round-1]=input;
            input++;
        }
        for(int i=matrix[0].length-round-1;i>round;i--){
            //list.add(matrix[matrix.length-round-1][i]);
            matrix[matrix.length-round-1][i] = input;
            input++;
        }
        for(int i=matrix.length-round-1;i>round;i--){
            //list.add(matrix[i][round]);
            matrix[i][round]=input;
            input++;
        }   
        round++;
        if(matrix.length>2*round&&matrix[0].length>2*round){
            addround(round,matrix, input);
        }        
        return;
    }
}
