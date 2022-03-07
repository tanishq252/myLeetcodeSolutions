class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> v;
        int n = prices.size();
        for(int i=0;i<n;i++){
            int f=0;
            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    v.push_back(prices[i] - prices[j]);
                    f=1;
                    break;
                }
            }
            if(f==0){v.push_back(prices[i]);}
        }
        return v;
    }
};