class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy, sell, i=0,n = prices.size()-1;
        int mxProfit = 0;
        while(i<n){
            // finding the local minima
            while(i<n and prices[i]>=prices[i+1]){
                i++;
            }
            buy = prices[i];
            
            // finding the local maxima
            while(i<n and prices[i]<prices[i+1]){
                i++;
            }
            sell = prices[i];
            mxProfit+=(sell - buy);
        }
        
        return mxProfit;
    }
};