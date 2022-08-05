class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1, 0);
        sort(nums.begin(), nums.end());
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]<=i){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
    
    // TLE
//     int ans=0;
//     void comboHelper(vector<int> &combo, vector<int> &nums, int target, int ind){
//         if(ind == nums.size()) return;
//         if(accumulate(combo.begin(), combo.end(), 0) > target){
//             return;
//         }else if(accumulate(combo.begin(), combo.end(), 0) == target){
//             sort(combo.begin(), combo.end());
//             do{
//                 cout<<"\n";
//                 for(auto i:combo){
//                     cout<<i<<" ";
//                 }
//                 ans++;
//             }while(next_permutation(combo.begin(), combo.end()));cout<<"\n";
//             return;
//         }
        
//         combo.push_back(nums[ind]);
//         comboHelper(combo, nums, target, ind);
//         combo.pop_back();
//         comboHelper(combo, nums, target, ind+1);
        
//     }
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int> combo;
//         sort(nums.begin(), nums.end());
//         comboHelper(combo, nums, target, 0);
//         return ans;
//     }
};