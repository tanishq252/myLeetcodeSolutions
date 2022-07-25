class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long currentStreak = 0;
        int i=0;
        while(i < prices.size()-1){
            if(prices[i]-prices[i+1] == 1){
                while(prices[i]-prices[i+1] == 1 and i<prices.size()-1){
                    currentStreak++;
                    i++;
                    if(i==prices.size() - 1){
                        break;
                    }
                }
                ans+= ((currentStreak*(currentStreak+1))/2);
                currentStreak = 0;
            }
            i++;
        }
        return ans+prices.size();
    }
};