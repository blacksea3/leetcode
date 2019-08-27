class Solution {
    public int maxProfit(int[] prices) {
        int max_profit = 0;
        if(prices.length==0){
            return max_profit;
        }
        int min = prices[0];
        
        for(int i=1;i<prices.length;i++){
            if(prices[i]<min){
                min = prices[i];
            }else{
                max_profit = Math.max(max_profit,prices[i]-min);
            }         
        }
        return max_profit;
    }
}
