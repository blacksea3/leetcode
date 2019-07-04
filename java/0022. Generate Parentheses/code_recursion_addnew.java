class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> l = new ArrayList<String>();
        List<String> last;
        
        if(n==1){
            l.add("()");
            return l;
        }
        last = generateParenthesis(n-1);
        
        last.forEach((str) -> {
            StringBuffer sb = new StringBuffer(str);
            for(int i=0;i<sb.length();i++){
                sb.insert(i,"()");
                if(!l.contains(sb.toString())){
                    l.add(sb.toString());
                }
                sb = new StringBuffer(str);
            }
            
        }); 
        return l;
    }
}
