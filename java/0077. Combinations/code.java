class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> l = new ArrayList<>();
        if(k==1){
            for(int i=1;i<=n;i++){
                List<Integer> com = new ArrayList<>();
                com.add(i);
                l.add(com);
            }
            return l;
        }else{
            List<List<Integer>> prev_l = combine(n,k-1);
            for(int i=1;i<=n;i++){
                for(List<Integer> com: prev_l){
                    if(com.get(0)>i){
                        List<Integer> newcom = new ArrayList<>(com);
                        newcom.add(0,i);
                        l.add(newcom);
                    }
                }
            }
            return l;
        }
    }
}
