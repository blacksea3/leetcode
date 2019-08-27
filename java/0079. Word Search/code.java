class Solution {
    public boolean exist(char[][] board, String word) {
        if(board.length==0){
            return false;
        }
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]==word.charAt(0)){
                    if(find(board,word,i,j,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public boolean find(char[][] b, String word, int row, int col, int index){
	//set the board to be same as before
        char[][] board = new char[b.length][b[0].length];
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                board[i][j] = b[i][j];
            }
        }
        
        board[row][col] = '\0';
        if(index == word.length()){
            return true;
        }
        if(row!=0&&board[row-1][col]==word.charAt(index)){
            if(find(board, word, row-1,col,index+1)){
                return true;
            }
        }
        if(row!=board.length-1&&board[row+1][col]==word.charAt(index)){
            if(find(board, word, row+1,col,index+1)){
                return true;
            }
        }
        if(col!=0&&board[row][col-1]==word.charAt(index)){
            if(find(board, word, row,col-1,index+1)){
                return true;
            }
        }
        if(col!=board[0].length-1&&board[row][col+1]==word.charAt(index)){
            if(find(board, word, row,col+1,index+1)){
                return true;
            }
        }
        
        return false;
    }
}
