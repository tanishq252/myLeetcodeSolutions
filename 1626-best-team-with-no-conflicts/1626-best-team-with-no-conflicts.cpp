class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vec;
        for(int i=0;i<ages.size();i++){
            vec.push_back({ages[i], scores[i]});
        }
        sort(vec.begin(), vec.end(), greater<>());
        vector<int> dp;
        for(auto &i:vec) {
            dp.push_back(i.second);
        }
        scores = dp;
        int mx = 0;
        for(int j=0;j<vec.size();j++){
            for(int i=j-1;i>=0;i--){
                if(vec[i].second >= vec[j].second){
                    dp[j] = max(dp[j], dp[i]+vec[j].second);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};