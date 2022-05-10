class Solution {
public:
    void combHelper(int n, int num, vector<int> &comb, vector<vector<int>> &ans, vector<int> &candidates){
        if(accumulate(comb.begin(), comb.end(), 0) == n){
            ans.push_back(comb);
            return;
        }else if(accumulate(comb.begin(), comb.end(), 0) > n){
            return;
        }
        
        if(num>=candidates.size()) return;
        
        comb.push_back(candidates[num]);
        combHelper(n, num, comb, ans, candidates);
        comb.pop_back();
        combHelper(n, num+1, comb, ans, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        combHelper(target, 0, comb, ans, candidates);
        return ans;
    }
};