class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<Integer>();
        if(matrix.length!=0&&matrix[0].length!=0){
            addround(0,matrix,list);
        }
        return list;
    }
        
    public void addround(int round, int[][] matrix, List<Integer> list){
        if(matrix.length-2*round==1){
            for(int i=round;i<matrix[0].length-round;i++){
                list.add(matrix[round][i]);
            }
            return;
        }else if(matrix[0].length-2*round==1){      
            for(int i=round;i<matrix.length-round;i++){
                list.add(matrix[i][round]);
            }
            return;
        }
        
        for(int i=round;i<matrix[0].length-round-1;i++){
            list.add(matrix[round][i]);
        }
        for(int i=round;i<matrix.length-round-1;i++){
            list.add(matrix[i][matrix[0].length-round-1]);
        }
        for(int i=matrix[0].length-round-1;i>round;i--){
            list.add(matrix[matrix.length-round-1][i]);
        }
        for(int i=matrix.length-round-1;i>round;i--){
            list.add(matrix[i][round]);
        }   
        round++;
        if(matrix.length>2*round&&matrix[0].length>2*round){
            addround(round,matrix,list);
        }        
        return;
    }
}
