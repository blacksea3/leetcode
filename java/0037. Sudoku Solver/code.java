class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);
    }
    public boolean solve(char[][] board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board, i, j,c)){
                            board[i][j]=c;
                            if(solve(board)){
                                return true;
                            }else{
                                board[i][j]='.';
                            }
                        }
                    }
                    //if 1-9 do not satified
                    return false;
                }
            }
        }
        return true;
    }
    
    public boolean isValid(char[][] board, int i, int j, char c){
        for(int index=0; index<9; index++){
            if(board[i][index]==c){
                return false;
            }
            if(board[index][j]==c){
                return false;
            }
            if(board[3*(i/3)+index/3][3*(j/3)+index%3]==c){
                return false;
            }
        }
        return true;
    }
}
