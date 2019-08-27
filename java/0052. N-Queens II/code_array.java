class Solution {
    int res = 0;
    public int totalNQueens(int n) {
      //int[] horizonal = new int[n];
      boolean[] vertical = new boolean[n];
      boolean[] leftfall = new boolean[2 * n - 1];
      boolean[] rightfall = new boolean[2 * n - 1];
      helper(n, vertical, leftfall, rightfall, 0);
      return res;
    }
    
    void helper(int n, boolean[] v, boolean[] l, boolean[] r, int row){
      
      if(row == n){
        res++;
        return;
      }
      
      for(int col = 0; col < n; col++){
         if(v[col] || l[row - col + n - 1] || r[row + col]) continue;
         v[col] = true;
         l[row - col + n - 1] = true;
         r[row + col] = true;
         
         helper(n, v, l, r, row + 1);
         
         v[col] = false;
         l[row - col + n - 1] = false;
         r[row + col] = false;
      }    
    }
}
