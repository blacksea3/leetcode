class Solution {
    public void setZeroes(int[][] matrix) {
        int row = -1;
        int col = -1;
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    if(row==-1){
                        row = i;
                        col = j;
                        for(int a=0;a<matrix.length;a++){
                            if(matrix[a][j]==0){
                                matrix[a][j]=1;
                            }else{
                                matrix[a][j]=0;
                            }
                        }
                        for(int a=0;a<matrix[0].length;a++){
                            if(matrix[i][a]==0){
                                matrix[i][a]=1;
                            }else{
                                matrix[i][a]=0;
                            }
                        }
                        break;
                    }else{
                        if(j!=col){
                            matrix[row][j]=1;
                            matrix[i][col]=1;
                        }
                    }
                    
                }
            }
        }
        if(row!=-1){
            for(int i=0;i<matrix.length;i++){
                if(matrix[i][col]==1){
                    for(int a=0;a<matrix[0].length;a++){
                        matrix[i][a]=0;
                    }
                }
            }
            if(matrix.length==0){
                return;
            }
            for(int i=0;i<matrix[0].length;i++){
                if(matrix[row][i]==1){
                    for(int a=0;a<matrix.length;a++){
                        matrix[a][i]=0;
                    }
                }
            }
        }
    }
}
