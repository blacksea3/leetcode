class Solution {
    public String simplifyPath(String path) {
        Stack<String> st = new Stack<>();
        
        for(String s : path.split("/")){
            if(s.equals("..")){
                if(!st.empty()){
                    st.pop();
                }
            }else if(s.equals(".")||s.equals("")){
                continue;
            }else{
                st.push(s); 
            }
        }
        
        StringBuffer ret = new StringBuffer();
        while(!st.empty()){
            ret.insert(0,st.pop());
            ret.insert(0,'/');
        }
        
        return ret.length()==0 ? "/" : ret.toString();
    }
}
