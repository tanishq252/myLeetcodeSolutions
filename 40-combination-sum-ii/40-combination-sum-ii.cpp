class Solution {
public:
    
    void combinationFunction(vector<vector<int>> &ans, vector<int> &comb, vector<int> &candidates,int target, int index){
        // if(accumulate(comb.begin(), comb.end(), 0) == target){
        //     ans.push_back(comb);
        //     return;
        // }else if(accumulate(comb.begin(), comb.end(), 0) > target){
        //     return;
        // }
        
        if(index>=candidates.size() && target<0) return;
        if(target == 0){
            ans.push_back(comb);
            return;
        } 

        for(int i = index;i<candidates.size();i++){
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]<=target){
                comb.push_back(candidates[i]);
                combinationFunction(ans, comb, candidates, target-candidates[i], i+1);
                comb.pop_back();
            }
            
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        vector<vector<int>> ans;
        if(accumulate(candidates.begin(), candidates.end(), 0) < target){
            return ans;
        }
        combinationFunction(ans, comb, candidates, target, 0);
        set<vector<int>> s(ans.begin(), ans.end());
        vector<vector<int>> answer(s.begin(), s.end());
        cout<<candidates.size();

        return answer;
    }
};