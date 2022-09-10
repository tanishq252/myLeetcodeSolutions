class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), ans=0;
        vector<int> buy(k+1, INT_MAX), sell(k+1);
        if(k>=n/2){
            for(int i=0;i<n-1;i++){
                if(prices[i+1] > prices[i]){
                    ans+=(prices[i+1]-prices[i]);
                }
            }
            return ans;
        }
        
        for(auto price:prices){
            for(int i=1; i<=k; i++){
                buy[i] = min(buy[i], price - sell[i-1]);
                sell[i] = max(sell[i], price - buy[i]);
            }
        }
        return sell[k];
        
    }
};