class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        vector<int> dp(101, 101);
        dp[0] = 0;
        for(auto &clip:clips){
            for(int i=clip[0]+1;i<=clip[1];i++){
                dp[i] = min(dp[i], dp[clip[0]]+1);
            }
        }
        return dp[time] == 101 ? -1:dp[time];
//         sort(clips.begin(), clips.end(), [](vector<int> &a, vector<int> &b){
//             return a[0]<b[0];
//         });
//         vector<vector<int>> ans;
//         for(auto i:clips){
//             if(ans.size() == 0){
//                 ans.push_back(i);
//             }else{
//                 if(ans.back()[1] >= i[0]){
//                     if(ans.back()[1] < i[1]){
//                         if(ans.back()[0] == i[0]){
//                             ans.back()[1] = i[1];
//                         }else{
//                             ans.push_back(i);
//                         }
//                     }
//                 }
//             }
//             if(ans.back()[1] == time){
//                 break;
//             }
//         }
//         int j=0;
//         while(true){
            
//         }
//         for(auto i:ans){
//             cout<<i[0]<<" "<<i[1]<<"\n";
//         }
//         return ans.size();
    }
};