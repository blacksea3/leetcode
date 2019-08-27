class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size()==0){
            return 0;
        }
        
        List<Integer> l = triangle.get(triangle.size()-1);
        int len = l.size();
        int[] arr = new int[len];
        
        for(int i=0;i<l.size();i++){
            arr[i] = l.get(i);
        }
        
        for(int i=1;i<triangle.size();i++){
            List<Integer> list = triangle.get(triangle.size()-1-i);
            for(int j=0;j<list.size();j++){
                arr[j] = Math.min(arr[j],arr[j+1])+list.get(j);
            }
        }
        return arr[0];
    }
}
