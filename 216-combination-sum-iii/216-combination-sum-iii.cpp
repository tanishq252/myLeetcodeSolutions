class Solution {
public:
    
    void combinationSumHelper(int k, int n, int num,vector<int> &comb, vector<vector<int>> &ans){
        if(k==0){
            if(accumulate(comb.begin(), comb.end(), 0)==n){
                ans.push_back(comb);
            }
            return;
        }
        
        if(num>9) return;
        
        comb.push_back(num);
        combinationSumHelper(k-1, n,num+1, comb, ans);        
        comb.pop_back();
        combinationSumHelper(k, n,num+1, comb, ans);

    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        combinationSumHelper(k, n, 1, comb, ans);
        return ans;
    }
};