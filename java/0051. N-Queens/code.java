class Solution {
    Set<Integer> col = new HashSet<Integer>();
    Set<Integer> dia_sam = new HashSet<Integer>();
    Set<Integer> dia_dif = new HashSet<Integer>();
    List<List<String>> list = new ArrayList<List<String>>();
    char[][] c;
    public List<List<String>> solveNQueens(int n) {
        c = new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                c[i][j]='.';
            } 
        }

        addqueen(0,n);
        return list;
    }
    
    public void addqueen(int row,int n){
        for(int i=0;i<n;i++){
            if(col.contains(i)||
               dia_sam.contains(i-row)||
               dia_dif.contains(i+row)){
                continue;
            }else{
                col.add(i);
                dia_sam.add(i-row);
                dia_dif.add(i+row);
                c[row][i]='Q';
                if(row==n-1){
                    List<String> s_list = new ArrayList<String>();
                    for(int line=0;line<n;line++){
                        s_list.add(new String(c[line]));
                    }
                    list.add(s_list);
                }else{
                    addqueen(row+1,n);
                }
                c[row][i]='.';
                col.remove(i);
                dia_sam.remove(i-row);
                dia_dif.remove(i+row);
            }
        }
    }
}
