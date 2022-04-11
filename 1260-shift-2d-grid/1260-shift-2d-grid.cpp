class Solution {
public:
    
    void rotateArray(vector<int> &v, int k){
        if(k==0){
            return;
        }else{
            int n = v.size();
            int t = v[n-1];
            for(int i=n-1;i>0;i--){
                v[i] = v[i-1];
            }
            v[0] = t;
        }
        rotateArray(v, k-1);
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> v;
        int n = grid.size();
        int m = grid[0].size();
        for(auto i:grid){
            for(auto j:i){
                v.push_back(j);
            }
        }
        rotateArray(v, k);
        vector<vector<int>> ans;
        int l = 0;
        for(int i=0;i<n;i++){
            vector<int> t;
            for(int j=0;j<m;j++){
                t.push_back(v[l++]);
            }
            ans.push_back(t);
        }
        return ans;
        
    }
};