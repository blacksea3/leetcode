class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> list = new ArrayList<int[]>();
        int i=0;
        
        while(i<intervals.length&&intervals[i][1]<newInterval[0]){
            list.add(intervals[i]);
            i++;
        }
        while(i<intervals.length&&intervals[i][0]<=newInterval[1]){
            newInterval[0] = Math.min(intervals[i][0],newInterval[0]);
            newInterval[1] = Math.max(intervals[i][1],newInterval[1]);
            i++;
        }
        list.add(newInterval);
        while(i<intervals.length){
            list.add(intervals[i]);
            i++;
        }
        
        int[][] ret = new int[list.size()][2];
        int j=0;
        
        for(int[] set : list){
            ret[j] = set;
            j++;
        }
        return ret; 
    }
}
