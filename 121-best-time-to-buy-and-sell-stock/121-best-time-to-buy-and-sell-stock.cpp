class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int mxProfit = 0;
        for(int i=1;i<prices.size();i++){
            mxProfit = max(mxProfit, prices[i]-mn);
            mn = min(mn, prices[i]);
        }
        return mxProfit;
    }
};