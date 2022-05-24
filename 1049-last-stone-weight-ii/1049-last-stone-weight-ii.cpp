class Solution {
public:
    
    int lastStoneWeightII(vector<int>& stones) {
        int target =  accumulate(stones.begin(), stones.end(), 0)/2;
        vector<int> dp(target+1, 0);
        for(int i=0;i<stones.size();i++){
            for(int j=target;j>=stones[i];j--){
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        return accumulate(stones.begin(), stones.end(), 0)-dp[target]*2;
    }
//     void smash1(vector<int> &stones){
//         if(stones.size() == 1) return;
//         int n = stones.size();
//         stones[n-2] = stones[n-1] - stones[n-2];
//         stones.pop_back();
//         sort(stones.begin(), stones.end());
//         smash1(stones);
//     }
//     void smash(vector<int> &stones){
//         if(stones.size() == 1) return;
//         int n = stones.size();
//         for(int i=0;i<n/2;i++){
//             stones[i] = stones[n-i-1] - stones[i];
//             stones.pop_back();
//         }
//         sort(stones.begin(), stones.end());
//         smash(stones);
//     }
    
//     int lastStoneWeightII(vector<int>& stones) {
//         sort(stones.begin(), stones.end());
//         vector<int> stones2 = stones;
//         smash1(stones2);
//         smash(stones);
//         return min(stones[0], stones2[0]);
//     }
};