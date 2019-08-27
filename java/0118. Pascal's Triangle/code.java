class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> l =new ArrayList<List<Integer>>();
        
        if(numRows>=1){
            List<Integer> list = new ArrayList<Integer>();
            list.add(1);
            l.add(list);
        }
        for(int i=2;i<=numRows;i++){
            List<Integer> prevlist = l.get(i-2);
            List<Integer> list = new ArrayList<Integer>();
            
            list.add(1);
            for(int j=2;j<i;j++){
                int p = prevlist.get(j-2);
                int c = prevlist.get(j-1);
                list.add(p+c);
            }
            list.add(1);
            
            l.add(list);
        }
        return l;
    }
}
