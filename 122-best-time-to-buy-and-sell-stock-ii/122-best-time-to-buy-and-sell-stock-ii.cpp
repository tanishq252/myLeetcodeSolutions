class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int mxProfit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-mn >= 0){
                mxProfit+=(prices[i]-mn);
                mn = prices[i];
            }else{
                mn = min(mn, prices[i]);
            }
            cout<<mn<<" "<<mxProfit<<"\n";
        }
        return mxProfit;
    }
};