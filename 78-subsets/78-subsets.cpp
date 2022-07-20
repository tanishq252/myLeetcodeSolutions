class Solution {
public:
    void combos(set<vector<int>> &ans, vector<int> &nums, vector<int> &combo, int ind){
        ans.insert(combo);
        
        if(ind >= nums.size()) return;
        
        combo.push_back(nums[ind]);
        combos(ans, nums, combo, ind+1);
        combo.pop_back();
        combos(ans, nums, combo, ind+1);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> combo;
        combos(ans, nums, combo, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};