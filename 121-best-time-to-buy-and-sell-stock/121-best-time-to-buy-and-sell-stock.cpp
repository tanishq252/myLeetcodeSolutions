class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_diff = 0;
        int min = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>min){
                max_diff = max(max_diff, prices[i]-min);
            }
            else{
                min = prices[i];
            }
        }
        return max_diff;
    }
};