class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> l = new ArrayList<>();
        String s = digits;
        l = addnewletter(s,null);
        
        return l;
    }
    //iterate until the last char
    public List<String> addnewletter(String s, List<String> l){
        List<String> ret = new ArrayList<>();
        if(l==null){
            if(s.length()!=0){
                appendlist(s.charAt(0),ret,"");
            }
        }else{
            for (String element : l) {
                appendlist(s.charAt(0),ret,element);
            }
        }
        
        if(s.length()>1){
            return addnewletter(s.substring(1),ret);
        }else{
            return ret;
        }
    }
    //update the list to for new char
    public List<String> appendlist(char c, List<String> l, String s){
        if(c == '2'){
            l.add(s+'a');
            l.add(s+'b');
            l.add(s+'c');
        }else if(c == '3'){
            l.add(s+'d');
            l.add(s+'e');
            l.add(s+'f');
        }else if(c == '4'){
            l.add(s+'g');
            l.add(s+'h');
            l.add(s+'i');
        }else if(c == '5'){
            l.add(s+'j');
            l.add(s+'k');
            l.add(s+'l');
        }else if(c == '6'){
            l.add(s+'m');
            l.add(s+'n');
            l.add(s+'o');
        }else if(c == '7'){
            l.add(s+'p');
            l.add(s+'q');
            l.add(s+'r');
            l.add(s+'s');
        }else if(c == '8'){
            l.add(s+'t');
            l.add(s+'u');
            l.add(s+'v');
        }else if(c == '9'){
            l.add(s+'w');
            l.add(s+'x');
            l.add(s+'y');
            l.add(s+'z');
        }
        
        return l;
    }
}
