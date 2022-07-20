class Solution {
public:
    void combos(set<vector<int>> &ans, vector<int> &combo, vector<int> &nums, int ind){
        vector<int> temp = combo;
        sort(temp.begin(), temp.end());
        ans.insert(temp);
        
        if(ind>=nums.size()) return;
        
        combo.push_back(nums[ind]);
        combos(ans, combo, nums, ind+1);
        combo.pop_back();
        combos(ans, combo, nums, ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> combo;
        combos(ans, combo, nums, 0);
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};