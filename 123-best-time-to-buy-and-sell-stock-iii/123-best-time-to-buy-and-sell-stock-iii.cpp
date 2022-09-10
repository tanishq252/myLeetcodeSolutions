class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> leftMaxPrf(n);
        vector<int> rightMaxPrf(n);
        int mx = prices[n-1], mn = prices[0], rmx=0, lmx=0, ans = 0;
        int mxPrf=0, mnPrf = 0;
        for(int i=1;i<n;i++){            
            mn = min(mn, prices[i]);

            leftMaxPrf[i] = max(leftMaxPrf[i-1], prices[i]-mn);;
        }
        for(int i=n-2;i>=0;i--){
                        mx = max(mx, prices[i]);

            rightMaxPrf[i] = max(rightMaxPrf[i+1], mx - prices[i]);;
        }
        for(int i=0;i<n;i++){
            ans = max(ans, rightMaxPrf[i]+leftMaxPrf[i]);
        }
        return ans;
    }
};