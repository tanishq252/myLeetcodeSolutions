class Solution {
public:
    
    void combos(set<vector<int>> &ans, vector<int> &v, vector<int> &combo, int ind, int k){
        if(combo.size() == k) ans.insert(combo);
        if(ind>=v.size()) return;
        
        combo.push_back(v[ind]);
        combos(ans, v, combo, ind+1, k);        
        combo.pop_back();
        combos(ans, v, combo, ind+1, k);

    }
    
    vector<vector<int>> combine(int n, int k) {
        set<vector<int>> ans;
        vector<int> v;
        vector<int> combo;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
        combos(ans, v, combo, 0, k);
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};