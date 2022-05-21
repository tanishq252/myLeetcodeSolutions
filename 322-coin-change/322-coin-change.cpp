class Solution {
public:
    
    void coinChange(vector<int> &coins, vector<int> &dp){
        for(int i=1;i<=10000;i++){
            for(int j=0;j<coins.size();j++){
                if(i>=coins[j]){
                    if(dp[i-coins[j]]!=INT_MAX){
                        dp[i] = min(dp[i], dp[i-coins[j]]+1);
                    }
                }
            }
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10001, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        coinChange(coins,dp);
        
        return (dp[amount] == INT_MAX) ?-1: dp[amount];
        // return 0;
    }
    
//     TLE using recursion and backtracking
    
//     int minSize = INT_MAX;
//     int mod = 1000000007;
    
//     void comboHelper(vector<int> &coins, int amount, vector<int> &combination, int index){
//         if(accumulate(combination.begin(), combination.end(), 0)%mod == amount){
//             minSize = (minSize > combination.size()) ? combination.size():minSize;
//         }else if(accumulate(combination.begin(), combination.end(), 0) > amount){
//             return;
//         }
        
//         if(index>=coins.size()) return;
        
//         combination.push_back(coins[index]%mod);
//         comboHelper(coins, amount, combination, index);
//         combination.pop_back();
//         comboHelper(coins, amount, combination, index+1);
//     }
    
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> combination;
//         comboHelper(coins, amount, combination, 0);
//         return (minSize == INT_MAX) ?-1: minSize;
//         // return 0;
//     }
};