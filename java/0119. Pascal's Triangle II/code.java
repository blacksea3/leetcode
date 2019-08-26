class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new ArrayList<Integer>();
        
        rowIndex++;
        
        for(int i=1;i<=rowIndex;i++){
            for(int j=i-1;j>=2;j--){
                list.set(j-1, list.get(j-2)+list.get(j-1));
            }
            list.add(1);
        }
        
        return list;
    }
    
}
