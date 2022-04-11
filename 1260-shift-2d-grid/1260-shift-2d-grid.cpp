class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> v;
        int n = grid.size();
        int m = grid[0].size();
        for(auto i:grid){
            for(auto j:i){
                v.push_back(j);
            }
        }
        vector<int> rotatedA;
        int nn = n*m;
        k%=v.size();
        for(int i=nn-k;i<nn;i++){
            rotatedA.push_back(v[i]);
        }
        for(int i=0;i<nn-k;i++){
            rotatedA.push_back(v[i]);
        }
        vector<vector<int>> ans;
        int l = 0;
        for(int i=0;i<n;i++){
            vector<int> t;
            for(int j=0;j<m;j++){
                t.push_back(rotatedA[l++]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};