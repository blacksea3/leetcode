class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        int wordlen;
        int slen;
        int wordslen;
        
        List<Integer> output = new ArrayList<>();
        
        slen = s.length();
        if(words!=null&&words.length>0){
            wordlen = words[0].length();
            wordslen = words.length;
        }else{
            return output;
        }
        
        Map<String, Integer> wordset = new HashMap<>();
        
        for (String word : words) {
            wordset.put(word, wordset.getOrDefault(word, 0) + 1);
        }
        
        //i++ ;not i+wordlen
        for(int i=0;i<slen - wordlen * wordslen+1;i++){
            Map<String, Integer> newwordset = new HashMap<>();
            int j = 0;
            while (j < wordslen) {
                String word = s.substring(i + j * wordlen, i + (j + 1) * wordlen);
                if (wordset.containsKey(word)) {
                    newwordset.put(word, newwordset.getOrDefault(word, 0) + 1);
                    if (newwordset.get(word) > wordset.getOrDefault(word, 0)) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
            if (j == wordslen) {
                output.add(i);
            }
        }
        return output;
    }
}
