class Solution {
    public int[][] merge(int[][] intervals) {
        //ways to sort the object or array
        Arrays.sort(intervals, (i1, i2) -> Integer.compare(i1[0], i2[0]));
        
        List<int[]> list = new ArrayList<int[]>();
        if(intervals.length==0){
            return intervals;
        }
        list.add(intervals[0]);
        
        for(int i=1;i<intervals.length;i++){
            //get the last item in list
            int[] lastlist = list.get(list.size()-1);
            if(intervals[i][0]>lastlist[1]){
                list.add(intervals[i]);
            }else if(intervals[i][1]>lastlist[1]){
                lastlist[1] = intervals[i][1];               
            }
        }
        
        int[][] ret = new int[list.size()][2];
        int i=0;
        
        for(int[] set : list){
            ret[i] = set;
            i++;
        }
        return ret;
    }
}
