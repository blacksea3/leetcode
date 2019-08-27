class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> list = new ArrayList<String>();
        check(1,s,list,new String());
        return list;
    }
    private void check(int part, String s, List<String> list, String prev_s){
        if(s.length()>(5-part)*3||s.length()==0){
            return;
        }
        if(part==4){
            if(Integer.parseInt(s)<=255){
                if(s.charAt(0)=='0'&&s.length()>1){
                    return;
                }else{
                    StringBuffer sb = new StringBuffer(prev_s);
                    sb.append(s);
                    list.add(sb.toString());
                }
            }
        }else{
            String s1 = prev_s + s.substring(0,1) + ".";
            check(part+1,s.substring(1),list,s1);
            if(s.length()>=2&&Integer.parseInt(s.substring(0,2))<=255){
                if(s.charAt(0)!='0'){
                    String s2 = prev_s + s.substring(0,2) + ".";
                    check(part+1,s.substring(2),list,s2);
                }       
            }
            if(s.length()>=3&&Integer.parseInt(s.substring(0,3))<=255){
                if(s.charAt(0)!='0'){
                    String s3 = prev_s + s.substring(0,3) + ".";
                    check(part+1,s.substring(3),list,s3);
                }  
            }
        }
        return;
    }
}
