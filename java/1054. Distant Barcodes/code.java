class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        int blength = barcodes.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        int count = 0;
        int[] s_array = new int[barcodes.length];
        int[] s_array2;
        int [] newarray = new int[blength];
        
        if(blength==0){
            return barcodes;
        }
        
        //get the hashmap of all input with number
        for(int i=0,j=0;i<blength;i++){
            if(map.containsKey(barcodes[i])){
                map.put(barcodes[i], map.get(barcodes[i])+1);
            }
            else{
                map.put(barcodes[i], 1);
                count++;
                s_array[j] = barcodes[i];
                j++;
            }            
        }
        
        //the array of diffent elements
        s_array2 = Arrays.copyOfRange(s_array, 0, count);

        //find the element appears most
        int max=0,max_num=0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if(max<entry.getValue()){
                max=entry.getValue();
                max_num=entry.getKey();
            }
        }
        
        //place the most frequent element at the front
        for(int i=0; i<count; i++){
            if(s_array2[i]==max_num){
                s_array2[i] = s_array2[0];
                s_array2[0] = max_num;
                break;
            }
        }
        
        //get the block size and number of block
        int blocksize = blength/map.get(max_num);
        //if blocksize is 1 
        if(blocksize == 1){
            blocksize = 2;
        }
        
        int block = blength/blocksize;
                
        //create the new array, loc1 is the block num and loc2 is the loc in block
        int loc1 = 0, loc2 = 0;
        //for all the posible place
        for(int i=0;i<blocksize;i++){
            for(int j=0;j<block+1;j++){
                if(j*blocksize+i<blength){
                    newarray[j*blocksize+i] = s_array2[loc1];
                    loc2++;
                    if(loc2==map.get(s_array2[loc1])){
                        loc1++;
                        loc2=0;
                    }
                }
            }
        }    

        return newarray;        
    }
}
