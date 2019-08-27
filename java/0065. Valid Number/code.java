class Solution {
    public boolean isNumber(String s) {
        StringBuffer sb = new StringBuffer();
        int[] num = new int[10];
        int start = 0;
        for(int i=0;i<s.length();i++){
            int n = check(s.charAt(i));
            if(n==num[start]){
                if(n==0||n==3){
                    continue;
                }else{
                    return false;
                }                
            }else if(n!=-1){
                start++;
                num[start]=n;
                sb.append(n);
                if(start>8){
                    return false;
                }
            }else{
                return false;
            }   
        }
        if(sb.length()>1&&sb.charAt(sb.length()-1)=='0'){
            sb.setLength(sb.length()-1);
        }
        
        if(sb.length()>=2&&sb.substring(0,2).equals("13")){
            sb.replace(0,2,"313");
        }else if(sb.length()>=3&&sb.substring(0,3).equals("413")){
            sb.replace(0,3,"4313");
        }else if(sb.length()>=3&&sb.substring(0,3).equals("312")){
            sb.replace(0,3,"32");
        }else if(sb.length()>=4&&sb.substring(0,4).equals("4312")){
            sb.replace(0,4,"432");
        }
                
        String sbs = sb.toString();
        if(sbs.length()==1){
            return sbs.equals("3");
        }else if(sbs.length()==2){
            return sbs.equals("43")||sbs.equals("31");
        }else if(sbs.length()==3){
            return sbs.equals("313")||sbs.equals("323")||sbs.equals("431");       
        }else if(sbs.length()==4){
            return sbs.equals("4313")||sbs.equals("4323")||sbs.equals("3243");
        }else if(sbs.length()==5){
            return sbs.equals("43243")||sbs.equals("31323");
        }else if(sbs.length()==6){
            return sbs.equals("431323")||sbs.equals("313243");
        }else if(sbs.length()==7){
            return sbs.equals("4313243");    
        }else{
            return false;
        }        
    }
    public int check(char c){
        if(Character.isSpace(c)){
            return 0;
        }else if(c=='.'){
            return 1;
        }else if(c=='e'){
            return 2;
        }else if(c<='9'&&c>='0'){
            return 3;
        }else if(c=='+'||c=='-'){
            return 4;
        }else{
            return -1;
        }
    }
}
