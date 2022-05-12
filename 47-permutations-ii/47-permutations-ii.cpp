class Solution {
public:
    void combinations(vector<int> &comb, vector<bool> &visited, vector<int> &nums, vector<vector<int>> &ans){
        if(nums.size() == comb.size()){
            ans.push_back(comb);
            // return;
        }
        for(int i=0;i<nums.size();i++){
            
            if(visited[i]) continue;
            
            if(i>0 and nums[i]==nums[i-1] and !visited[i-1]) continue;
            
            visited[i] = true;
            
            comb.push_back(nums[i]);
            
            combinations(comb, visited, nums, ans);
            
            visited[i] = false;
            
            comb.pop_back();
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> comb;
        sort(nums.begin(), nums.end());
        combinations(comb, visited, nums, ans);
        return ans;
    }
};