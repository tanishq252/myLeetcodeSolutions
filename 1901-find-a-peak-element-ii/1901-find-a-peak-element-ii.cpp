class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> matt(m+2, vector<int>(n+2, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matt[i+1][j+1] = mat[i][j];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int k = matt[i][j];
                if(k > matt[i+1][j] and k > matt[i][j+1] and k>matt[i][j-1] and k> matt[i-1][j]){
                    cout<<matt[i][j];
                    return {i-1, j-1};
                }
            }
        }
        return {};
    }
};