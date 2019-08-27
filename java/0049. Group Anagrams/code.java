class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> l = new ArrayList<List<String>>();

        int count = 0;
        Map<String,Integer> map = new HashMap<String,Integer>();
        
        for(int i=0;i<strs.length;i++){
            char[] arrayCh=strs[i].toCharArray();
            Arrays.sort(arrayCh);
            String s = new String(arrayCh);
            if(map.containsKey(s)){
                int key = map.get(s);
                List<String> inside = l.get(key);
                inside.add(strs[i]);
            }else{
                map.put(s,count);
                List<String> inside = new ArrayList<String>();
                inside.add(strs[i]);
                l.add(inside);
                count++;
            }
        }
        return l;
    }
}
