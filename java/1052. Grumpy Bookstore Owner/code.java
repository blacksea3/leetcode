class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int[] unhappy = new int[customers.length];
        int max = 0;
        int loc = 0;
        int result = 0;
        int total = 0;
        
        //unhappy is the result the possible unhappy customers
        for(int i=0; i<customers.length;i++){
            unhappy[i] = customers[i] * grumpy[i];
            result += (-grumpy[i]+1)*customers[i];
            total += customers[i];
        }

	//if X is larger than the total time
        if(customers.length<X){
            return total;
        }
        
        for(int i=0; i<customers.length-X+1;i++){            
            int sum = 0;
            for(int j=i;j<i+X;j++){
                sum+= unhappy[j];
            }
            if(sum>max){
                max = sum;
                loc = i;
            }
        }
        
        for(int i=loc;i<loc+X;i++){
            result += grumpy[i]*customers[i];
        }
        
        return result;
    }
}
