class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> l = new ArrayList<Integer>();
        if(n==0){
            l.add(0);
            return l;
        }
        int center = 1<<(n-1);
        List<Integer> prev_l = grayCode(n-1);
        for(int a : prev_l){
            l.add(a);
        }
        for(int a : prev_l){
            l.add(center,a+center);
        }
        return l;
    }
}
