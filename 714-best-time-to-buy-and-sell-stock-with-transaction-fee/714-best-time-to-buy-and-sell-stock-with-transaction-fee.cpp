class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), ans=0;
        int buy = INT_MAX, sell=0;
        for(auto &p:prices){
            buy = min(buy, p - sell);
            sell = max(sell, p-buy-fee);
        }
        return sell;
    }
};