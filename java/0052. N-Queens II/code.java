class Solution {
    Set<Integer> col = new HashSet<Integer>();
    Set<Integer> dia_sam = new HashSet<Integer>();
    Set<Integer> dia_dif = new HashSet<Integer>();
    List<List<String>> list = new ArrayList<List<String>>();
    int count = 0;
    
    public int totalNQueens(int n) {
        addqueen(0,n);
        return count;
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
                if(row==n-1){
                    count++;
                }else{
                    addqueen(row+1,n);
                }
                col.remove(i);
                dia_sam.remove(i-row);
                dia_dif.remove(i+row);
            }
        }
    }
}
