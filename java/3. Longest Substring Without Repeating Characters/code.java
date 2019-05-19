class Solution {
    public int lengthOfLongestSubstring(String s) {
        //max is the total length 
        int max = 0;
        int start = 0, end = 0;

        //hashmap store the location of every char and its postion
        HashMap<String, Integer> map = new HashMap<String, Integer>();
                
        for(; end<s.length(); end++){
            //element is the 'start'th char in s
            String element = Character.toString(s.charAt(end));
            
            //if contains, the start position may change
            if(map.containsKey(element)){
                start = Math.max(start, map.get(element)+1);
            }
            //alway update max and put new
            max = Math.max(max, end - start + 1);
            map.put(element, end);
        }

        return max;
    }    
}