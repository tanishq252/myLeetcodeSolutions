class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevSell=0, prevBuy, buy = INT_MAX, sell = 0;
        for(auto &p:prices){
            prevBuy = buy;
            buy = min(buy, p - prevSell);
            prevSell = sell;
            sell = max(sell, p - prevBuy);
        }
        return sell;
    }
};